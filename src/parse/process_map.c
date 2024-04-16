/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <mhernang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:16:22 by mhernang          #+#    #+#             */
/*   Updated: 2024/04/16 16:20:40 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static void	add_row(char ***map, char *line);
static void	check_valid_chars(t_map *map);
static void	check_one_player(t_map *map);

void    process_map(int fd, char *line, t_data *data)
{
    char    **map;
    int     cols;

    map = malloc(sizeof(char *) * 2);
    map[0] = ft_substr(line, 0, ft_strlen(line) - 1);
    map[1] = NULL;
    data->map.rows++;
    while (line)
    {
        free(line);
        line = get_next_line(fd);
        if (line && line[0] != '\n')
        {
            add_row(&map, line);
            data->map.rows++;
        }
    }
    data->map.map = map;
    check_valid_chars(&data->map);
    check_one_player(&data->map);
    set_player_pos(data);
    data->map.map = fill_spaces(map, data->map.rows, &cols);
	data->map.cols = cols;
    free_map(&map);
}

static void    add_row(char ***map, char *line)
{
    int     i;
    int     len;
    char    **new_map;

    len = 0;
    while ((*map)[len])
        len++;
    new_map = malloc(sizeof(char *) * (len + 2));
    i = 0;
    while (i < len)
    {
        new_map[i] = (*map)[i];
        i++;
    }
    if (line[ft_strlen(line) - 1] == '\n')
        new_map[i] = ft_substr(line, 0, ft_strlen(line) - 1);
    else
        new_map[i] = ft_substr(line, 0, ft_strlen(line));
    new_map[i + 1] = NULL;
    free(*map);
    *map = new_map;
}

static void	check_valid_chars(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
			if (!(map->map[i][j] == ' ' || map->map[i][j] == '1'
				|| map->map[i][j] == '0' || map->map[i][j] == 'N'
				|| map->map[i][j] == 'S' || map->map[i][j] == 'E'
				|| map->map[i][j] == 'W'))
				exit_mssg("WRONG MAP: invalid characters detected\n");
	}
}

static void	check_one_player(t_map *map)
{
	int	i;
	int	j;
	int	found;

	i = -1;
	found = 0;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S'
				|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
				found += 1;
		}
	}
	if (found != 1)
		exit_mssg("WRONG MAP: invalid player configuration\n");
}
