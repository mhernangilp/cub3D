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

static char **dup_map(t_map *original);
static void	floodfill(char **map, int y, int x, int rows, int cols);

void    check_borders(t_map *map)
{
    char    **duped_map;
    int     i;
    int     j;
    
    duped_map = dup_map(map);
    i = -1;
    while (duped_map[++i])
    {
        j = -1;
        while (duped_map[i][++j])
            if (duped_map[i][j] == '0')
                floodfill(duped_map, i, j, map->rows, map->cols);
    }
    i = -1;
    while (duped_map[++i])
        free(duped_map[i]);
    free(duped_map);
}

static char **dup_map(t_map *original)
{
    char    **copy;
    int     i;

    i = -1;
    copy = malloc((original->rows + 1) * sizeof(char *));
    while (original->map[++i])
        copy[i] = ft_strdup(original->map[i]);
    copy[i] = NULL;
    return (copy);
}

static void	floodfill(char **map, int y, int x, int rows, int cols)
{
	if (map[y][x] == '1')
		return ;
    else if (y < 0 || x < 0 || y >= rows/* || x >= cols*/ || map[y][x] == ' ')
    {
                printf("MAl en %d %d con mapa %s\n%s\n%s\n y %d %d %d %d %d\n", y , x, map[0], map[1], map[2], y < 0, x < 0, y >= rows, x >= cols, map[y][x] == ' ');
        error_msg("WRONG MAP: invalid walls configuration\n");
    }
	map[y][x] = 'F';
	floodfill(map, y - 1, x, rows, cols);
	floodfill(map, y, x - 1, rows, cols);
	floodfill(map, y + 1, x, rows, cols);
	floodfill(map, y, x + 1, rows, cols);
}
