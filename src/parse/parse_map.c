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

void	parse_map(char *s)
{
	int	i;
	int	fd;
	int	fd_dir;

	fd = open(s, O_RDONLY);
	if (fd < 0)
		exit_mssg("WRONG MAP\n");
	else
	{
		fd_dir = open(s, O_DIRECTORY);
		if (fd_dir != -1)
			exit_mssg("PATH IS A DIRECTORY\n");
		close(fd_dir);
	}
	i = ft_strlen(s) - 1;
	if (s[i] != 'b' || s[--i] != 'u' || s[--i] != 'c' || s[--i] != '.')
	{
		close(fd);
		exit_mssg("WRONG MAP: invalid format\n");
	}
//	parse_map(fd);
	close(fd);
	return ;
}

//static void	parse_map(int fd)
