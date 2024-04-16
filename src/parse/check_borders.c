/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <mhernang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:29:12 by mhernang          #+#    #+#             */
/*   Updated: 2024/04/16 17:18:52 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static char	**dup_map(t_map *original);
static void	floodfill(char **map, t_player coord, int rows, int cols);

void	check_borders(t_map *map)
{
	char		**duped_map;
	t_player	coord;

	duped_map = dup_map(map);
	coord.y = -1;
	while (duped_map[++coord.y])
	{
		coord.x = -1;
		while (duped_map[coord.y][++coord.x])
			if (duped_map[coord.y][coord.x] == '0')
				floodfill(duped_map, coord, map->rows, map->cols);
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

static void	floodfill(char **map, t_player coord, int rows, int cols)
{
	if (coord.y < 0 || coord.x < 0 || coord.y >= rows
		|| coord.x >= cols || map[coord.y][coord.x] == ' ')
		exit_mssg("WRONG MAP: invalid walls configuration\n");
	else if (map[coord.y][coord.x] == '1' || map[coord.y][coord.x] == 'F')
		return ;
	map[coord.y][coord.x] = 'F';
	floodfill(map, coord, rows, cols);
	floodfill(map, coord, rows, cols);
	floodfill(map, coord, rows, cols);
	floodfill(map, coord, rows, cols);
}
