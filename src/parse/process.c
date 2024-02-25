/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <mhernang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:28:12 by mhernang          #+#    #+#             */
/*   Updated: 2024/02/25 18:09:51 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static void process_texture(char *line, t_data *data);
static void process_color(char *line, t_data *data);
static void set_colors(char type, t_data *data, t_RGB color);

void	process_line(char *line, t_data *data)
{
	while (*line && *line == ' ')
		line++;
	if (*line == 'N' && (*(line + 1) && *(line + 1) == 'O') && (*(line + 2) && *(line + 2) == ' '))
		process_texture(line, data);
	if (*line == 'S' && (*(line + 1) && *(line + 1) == 'O') && (*(line + 2) && *(line + 2) == ' '))
		process_texture(line, data);
	if (*line == 'W' && (*(line + 1) && *(line + 1) == 'E') && (*(line + 2) && *(line + 2) == ' '))
		process_texture(line, data);
	if (*line == 'E' && (*(line + 1) && *(line + 1) == 'A') && (*(line + 2) && *(line + 2) == ' '))
		process_texture(line, data);
	if (*line == 'F' && (*(line + 1) && *(line + 1) == ' '))
		process_color(line, data);
	if (*line == 'C' && (*(line + 1) && *(line + 1) == ' '))
		process_color(line, data);
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
    printf("%s\n", path);
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
    t_RGB   color;

    i = 2;
    while (line[i] && line[i] == ' ')
        i++;
    if (!ft_isdigit(line[i])) {
        color.R = color.G = color.B = -1;
        printf("R:%d G:%d B:%d\n", color.R, color.G, color.B);
        return;
    }
    color.R = ft_atoi(&line[i]);
    if (color.R < 0 || color.R > 255)
        color.R = -1;
    while (line[i] && line[i] != ',')
        i++;
    if (line[i])
        i++;
    if (!ft_isdigit(line[i])) {
        color.G = color.B = -1;
        printf("R:%d G:%d B:%d\n", color.R, color.G, color.B);
        return;
    }
    color.G = ft_atoi(&line[i]);
    if (color.G < 0 || color.G > 255)
        color.G = -1;
    while (line[i] && line[i] != ',')
        i++;
    
    if (line[i])
        i++;
    if (!ft_isdigit(line[i])) {
        color.B = -1;
        printf("R:%d G:%d B:%d\n", color.R, color.G, color.B);
        return;
    }
    color.B = ft_atoi(&line[i]);
    if (color.B < 0 || color.B > 255)
        color.B = -1;
    
    printf("R:%d G:%d B:%d\n", color.R, color.G, color.B);
    set_colors(line[0], data, color);
}

static void set_colors(char type, t_data *data, t_RGB color)
{
    if (type == 'F')
    {
        data -> F.R = color.R;
        data -> F.G = color.G;
        data -> F.B = color.B;
    }
    if (type == 'C')
    {
        data -> C.R = color.R;
        data -> C.G = color.G;
        data -> C.B = color.B;
    }
}
