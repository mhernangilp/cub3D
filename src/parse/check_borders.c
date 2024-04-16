/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <mhernang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:29:12 by mhernang          #+#    #+#             */
/*   Updated: 2024/04/16 17:44:55 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static char	**dup_map(t_map *original);
static void	floodfill(char **map, int y, int x, t_player coord);

void	check_borders(t_map *map)
{
	char		**duped_map;
	int			i;
	int			j;
	t_player	coord;

	coord.y = map->rows;
	coord.x = map->cols;
	duped_map = dup_map(map);
	i = -1;
	while (duped_map[++i])
	{
		j = -1;
		while (duped_map[i][++j])
			if (duped_map[i][j] == '0')
				floodfill(duped_map, i, j, coord);
	}
	free_map(&duped_map);
}

static char	**dup_map(t_map *original)
{
	char	**copy;
	int		i;

	i = -1;
	copy = malloc((original->rows + 1) * sizeof(char *));
	while (original->map[++i])
		copy[i] = ft_strdup(original->map[i]);
	copy[i] = NULL;
	return (copy);
}

static void	floodfill(char **map, int y, int x, t_player coord)
{
	if (y < 0 || x < 0 || y >= coord.y || x >= coord.x || map[y][x] == ' ')
		exit_mssg("WRONG MAP: invalid walls configuration\n");
	else if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	floodfill(map, y - 1, x, coord);
	floodfill(map, y, x - 1, coord);
	floodfill(map, y + 1, x, coord);
	floodfill(map, y, x + 1, coord);
}
