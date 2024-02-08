/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:12:49 by gfernand          #+#    #+#             */
/*   Updated: 2024/02/08 13:54:07 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	parse(char *file, t_data *data)
{
	int	fd;
	int	fd_dir;

	if (ft_strrncmp(file, ".cub", 4))
		exit_mssg("WRONG MAP: invalid format\n");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_mssg("WRONG MAP: error opening file\n");
	else
	{
		fd_dir = open(file, O_DIRECTORY);
		if (fd_dir != -1)
			exit_mssg("WRONG MAP: path is a directory\n");
		close(fd_dir);
	}
	//parse_texture(fd, data);
	//parse_color(fd, data);
	//parse_map(fd, data);
	(void) data;
	close(fd);
	return ;
}
