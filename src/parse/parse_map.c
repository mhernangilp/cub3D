/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:12:49 by gfernand          #+#    #+#             */
/*   Updated: 2024/01/29 17:20:03 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

//static void	parse_map(int fd);

void	parse(char *s)
{
	int	fd;
	int	fd_dir;

	if (ft_strrncmp(s, ".cub", 4))
		exit_mssg("WRONG MAP: invalid format\n");
	fd = open(s, O_RDONLY);
	if (fd < 0)
		exit_mssg("WRONG MAP: error opening file\n");
	else
	{
		fd_dir = open(s, O_DIRECTORY);
		if (fd_dir != -1)
			exit_mssg("WRONG MAP: path is a directory\n");
		close(fd_dir);
	}
	//parse_map(fd);
	close(fd);
	return ;
}
/*
static void	parse_map(int fd)
{
}
*/
