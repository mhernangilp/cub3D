/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <mhernang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:12:49 by gfernand          #+#    #+#             */
/*   Updated: 2024/02/11 18:00:25 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static void	initialize_data(t_data *data);
static void	read_file(int fd, t_data *data);

void	parse(char *file, t_data *data)
{
	int		fd;
	int		fd_dir;

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
	initialize_data(data);
	read_file(fd, data);
	close(fd);
	return ;
}

static void	initialize_data(t_data *data)
{
	data -> NO = NULL;
	data -> SO = NULL;
	data -> WE = NULL;
	data -> EA = NULL;
	data -> F.R = -1;
	data -> F.G = -1;
	data -> F.B = -1;
	data -> C.R = -1;
	data -> C.G = -1;
	data -> C.B = -1;
	data -> map.map = NULL;
	data -> map.rows = -1;
	data -> map.cols = -1;
}

static void	read_file(int fd, t_data *data)
{
	char	*line;

	line = get_next_line(fd);
	while (line) //no ha llegado al mapa	
	{
		process_line(line, data);
		printf("%s", line);
		line = get_next_line(fd);
	}
	//if (NO, SO, ... == NUL || !F o !C)
}
