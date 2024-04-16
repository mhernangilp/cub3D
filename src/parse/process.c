/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <mhernang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:28:12 by mhernang          #+#    #+#             */
/*   Updated: 2024/04/16 16:57:10 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static void	process_texture(char *line, t_data *data);
static void	process_color(char *line, t_data *data);
static void	check_colors_length(char **colors);
static void	rgb_to_hex(char type, t_data *data, t_RGB color);

void	process_line(char *line, t_data *data)
{
	while (*line && *line == ' ')
		line++;
	if (*line == 'N' && (*(line + 1) && *(line + 1) == 'O')
		&& (*(line + 2) && *(line + 2) == ' '))
		process_texture(line, data);
	else if (*line == 'S' && (*(line + 1) && *(line + 1) == 'O')
		&& (*(line + 2) && *(line + 2) == ' '))
		process_texture(line, data);
	else if (*line == 'W' && (*(line + 1) && *(line + 1) == 'E')
		&& (*(line + 2) && *(line + 2) == ' '))
		process_texture(line, data);
	else if (*line == 'E' && (*(line + 1) && *(line + 1) == 'A')
		&& (*(line + 2) && *(line + 2) == ' '))
		process_texture(line, data);
	else if (*line == 'F' && (*(line + 1) && *(line + 1) == ' '))
		process_color(line, data);
	else if (*line == 'C' && (*(line + 1) && *(line + 1) == ' '))
		process_color(line, data);
	else if (*line && *line != '\n')
		exit_mssg("WRONG MAP: wrong elements configuration\n");
}

static void	process_texture(char *line, t_data *data)
{
	int		i;
	int		start;
	char	*path;
	int		fd;

	i = 2;
	while (line[i] && line[i] == ' ')
		i++;
	start = i;
	while (line[i] && line[i] != ' ' && line[i] != '\n')
		i++;
	path = ft_substr(line, start, i - start);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_msg("Error\nInvalid texture");
	close(fd);
	if (line[0] == 'N' && line[1] == 'O')
		data -> no = path;
	if (line[0] == 'S' && line[1] == 'O')
		data -> so = path;
	if (line[0] == 'W' && line[1] == 'E')
		data -> we = path;
	if (line[0] == 'E' && line[1] == 'A')
		data -> ea = path;
}

static void	process_color(char *line, t_data *data)
{
	int		i;
	char	**colors;
	t_RGB	color_rgb;

	i = 2;
	while (line[i] && line[i] == ' ')
		i++;
	colors = ft_split(&line[i], ',');
	check_colors_length(colors);
	color_rgb.r = ft_atoi(colors[0]);
	color_rgb.g = ft_atoi(colors[1]);
	color_rgb.b = ft_atoi(colors[2]);
	if ((color_rgb.r == 0 && !is_zero(colors[0]))
		|| (color_rgb.g == 0 && !is_zero(colors[1]))
		|| (color_rgb.b == 0 && !is_zero(colors[2])))
		exit_mssg("WRONG MAP: invalid colors\n");
	if (color_rgb.r < 0 || color_rgb.r > 255 || color_rgb.g < 0
		|| color_rgb.g > 255 || color_rgb.b < 0 || color_rgb.b > 255)
		exit_mssg("WRONG MAP: invalid colors\n");
	rgb_to_hex(line[0], data, color_rgb);
	free_map(&colors);
}

static void	rgb_to_hex(char type, t_data *data, t_RGB color)
{
	int	hex;

	hex = (color.r << 16) | (color.g << 8) | color.b;
	if (type == 'F')
		data -> f = hex;
	if (type == 'C')
		data -> c = hex;
}

static void	check_colors_length(char **colors)
{
	int	i;

	i = 0;
	while (colors[i])
		i++;
	if (i != 3)
		exit_mssg("WRONG MAP: invalid colors\n");
}
