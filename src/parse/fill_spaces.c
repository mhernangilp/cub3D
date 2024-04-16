/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_spaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <mhernang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:37:15 by mhernang          #+#    #+#             */
/*   Updated: 2024/04/16 16:18:34 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static int  get_max_col(char **map);
static char *fill_line(char *line, int max_col);
static void change_player(char **map);

char    **fill_spaces(char **original, int rows, int *cols)
{
    char    **filled_map;
    int     i;
    int     max_col;

    filled_map = malloc((rows + 1) * sizeof(char *));
    max_col = get_max_col(original);
    *cols = max_col;
    i = -1;
    while (original[++i])
        filled_map[i] = fill_line(original[i], max_col);
    filled_map[i] = NULL;
    change_player(filled_map);
    return (filled_map);
}

static void change_player(char **map)
{
    int i;
    int j;

    i = -1;
    while (map[++i])
    {
        j = -1;
        while (map[i][++j])
        {
            if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
                map[i][j] = '0';
        }
    }
}

static int  get_max_col(char **map)
{
    int i;
    int j;
    int max_col;

    max_col = -1;
    i = -1;
    while (map[++i])
    {
        j = 0;
        while (map[i][j])
            j++;
        if (j > max_col)
            max_col = j;
    }
    return (max_col);
}

static char *fill_line(char *line, int max_col)
{
    int     i;
    char    *new_line;

    new_line = malloc((max_col + 1) *  sizeof(char));
    i = -1;
    while (++i < max_col)
        new_line[i] = ' ';
    new_line[i] = '\0';
    ft_memcpy(new_line, line, ft_strlen(line));
    return (new_line);
}