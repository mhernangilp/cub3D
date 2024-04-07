/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <mhernang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:28:12 by mhernang          #+#    #+#             */
/*   Updated: 2024/04/07 12:32:57 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static void process_texture(char *line, t_data *data);
static void process_color(char *line, t_data *data);
static void	check_colors_length(char **colors);
static void rgb_to_hex(char type, t_data *data, t_RGB color);

void	process_line(char *line, t_data *data)
{
	while (*line && *line == ' ')
		line++;
	if (*line == 'N' && (*(line + 1) && *(line + 1) == 'O') && (*(line + 2) && *(line + 2) == ' '))
		process_texture(line, data);
	else if (*line == 'S' && (*(line + 1) && *(line + 1) == 'O') && (*(line + 2) && *(line + 2) == ' '))
		process_texture(line, data);
	else if (*line == 'W' && (*(line + 1) && *(line + 1) == 'E') && (*(line + 2) && *(line + 2) == ' '))
		process_texture(line, data);
	else if (*line == 'E' && (*(line + 1) && *(line + 1) == 'A') && (*(line + 2) && *(line + 2) == ' '))
		process_texture(line, data);
	else if (*line == 'F' && (*(line + 1) && *(line + 1) == ' '))
		process_color(line, data);
	else if (*line == 'C' && (*(line + 1) && *(line + 1) == ' '))
		process_color(line, data);
	else if (*line && *line != '\n')
		exit_mssg("WRONG MAP: wrong elements configuration\n");
}

static void process_texture(char *line, t_data *data)
{
    int     i;
    int     start;
    char    *path;
    int     fd;

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
        data -> NO = path;
    if (line[0] == 'S' && line[1] == 'O')
        data -> SO = path;
    if (line[0] == 'W' && line[1] == 'E')
        data -> WE = path;
    if (line[0] == 'E' && line[1] == 'A')
        data -> EA = path;
}

static void process_color(char *line, t_data *data)
{
    int     i;
    char    **colors;
    t_RGB   colorRGB;

	i = 2;
	while (line[i] && line[i] == ' ')
		i++;
	colors = ft_split(&line[i], ',');
	check_colors_length(colors);
	colorRGB.R = ft_atoi(colors[0]);
	colorRGB.G = ft_atoi(colors[1]);
	colorRGB.B = ft_atoi(colors[2]);
	/*if ((colorRGB.R == 0 && !is_zero(colors[0])) || (colorRGB.G == 0 && !is_zero(colors[1]))
		|| (colorRGB.B == 0 && !is_zero(colors[2])))
		exit_mssg("WRONG MAP: invalid colors\n");*/
	if (colorRGB.R < 0 || colorRGB.R > 255 || colorRGB.G < 0
		|| colorRGB.G > 255 || colorRGB.B < 0 || colorRGB.B > 255)
        exit_mssg("WRONG MAP: invalid colors\n");
	rgb_to_hex(line[0], data, colorRGB);
	free_map(&colors);
}

static void rgb_to_hex(char type, t_data *data, t_RGB color)
{
	int	hex;

	hex = (color.R << 16) | (color.G << 8) | color.B;
	hex |= 0xFF000000;
    if (type == 'F')
        data -> F = hex;
    if (type == 'C')
        data -> C = hex;
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