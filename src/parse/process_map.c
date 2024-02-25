/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <mhernang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:16:22 by mhernang          #+#    #+#             */
/*   Updated: 2024/02/25 18:33:01 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

/*void    add_row(char ***map, char *line)
{
    int     i;
    int     len;
    char    **new_map;

    len = 0;
    while (*map[len])
        len++;
    new_map = malloc(sizeof(char *) * (len + 2));
    i = 0;
    while (i < len)
    {
        new_map[i] = *map[i];
        i++;
    }
    new_map[i] = line;
    new_map[i + 1] = NULL;
    free(*map);
    *map = new_map;
}*/

void    process_map(int fd, char *line, t_data *data)
{
    char    **map;

    (void)fd;
    map = malloc(sizeof(char *) * 2);
    map[0] = line;
    map[1] = NULL;
    data->map.cols = ft_strlen(line) - 1; //What if the lines are not the same length?
    while (line)
    {
        line = get_next_line(fd);
        if (line)
        {
            //add_row(&map, line);
            data->map.rows++;
        }
    }
}

