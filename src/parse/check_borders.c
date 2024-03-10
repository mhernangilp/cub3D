/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <mhernang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:29:12 by mhernang          #+#    #+#             */
/*   Updated: 2024/03/10 20:52:10 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static int  is_left(int i, int j, t_map *map);
static int  is_top(int i, int j, t_map *map);
static int  is_right(int i, int j, t_map *map);
static int  is_bot(int i, int j, t_map *map);

void    check_borders(t_map *map)
{
    int i;
    int j;

    i = -1;
    while (map->map[++i])
    {
        j = -1;
        while (map->map[i][++j])
        {
            if (is_left(i, j, map) || is_top(i, j, map) || is_right(i, j, map) || is_bot(i, j, map))
                if (map->map[i][j] == '0')
                    exit_mssg("WRONG MAP: walls missing\n");
        }
    }
}

static int  is_left(int i, int j, t_map *map)
{
    return (j == 0 || map->map[i][j - 1] == ' ');
}

static int  is_top(int i, int j, t_map *map)
{
    return (i == 0 || ft_strlen(map->map[i - 1]) <= (size_t)j || map->map[i - 1][j] == ' ');
}

static int  is_right(int i, int j, t_map *map)
{
    return (map->map[i][j + 1] == '\n' || map->map[i][j + 1] == ' ');
}
static int  is_bot(int i, int j, t_map *map)
{
    return (i == map->rows || ft_strlen(map->map[i + 1]) <= (size_t)j || map->map[i + 1][j] == ' ');
}