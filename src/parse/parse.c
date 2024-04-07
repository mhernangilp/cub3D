/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <mhernang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:12:49 by gfernand          #+#    #+#             */
/*   Updated: 2024/03/31 14:24:36 by mhernang         ###   ########.fr       */
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
	data -> F = -1;
	data -> C = -1;
	data -> map.map = NULL;
	data -> map.rows = 0;
	data -> map.cols = -1;
	data -> map.player_pos.x = -1;
	data -> map.player_pos.y = -1;
}

static void	read_file(int fd, t_data *data)
{
	char	*line;

	line = get_next_line(fd);
	while (line && !elements_full(data))
	{
		process_line(line, data);
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		exit_mssg("WRONG MAP: no map found\n");
	if (!data -> NO || !data -> SO || !data -> WE || !data -> EA
		|| data -> F == -1 || data -> C == -1)
		exit_mssg("WRONG MAP: missing information\n");
	process_map(fd, line, data);
	check_borders(&data->map);
}
