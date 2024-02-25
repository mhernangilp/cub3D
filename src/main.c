/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:13:32 by gfernand          #+#    #+#             */
/*   Updated: 2024/02/08 13:53:38 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	leaks(void)
{
	system("leaks cub3D");
}

void    ft_map(t_data data);

int	main(int arg, char **argv)
{
	t_data	data;

	atexit(leaks);
	if (arg < 2)
		exit_mssg("Error: 2 arguments are spected\n");
	parse(argv[1], &data);
	ft_map(data);
	execution(data);
	(void)argv[0];
	return (0);
}

void	exit_mssg(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		write(2, (s + i), 1);
	exit(1);
}


void    ft_map(t_data data)
{
	data.map.map = malloc((MAP_HEIGHT + 1) * sizeof(char *));
	for (int i = 0; i < MAP_HEIGHT; i++)
        data.map.map[i] = malloc((MAP_WIDTH + 1) * sizeof(char));


    data.map.map[0][0] = '1';
    data.map.map[0][1] = '1';
    data.map.map[0][2] = '1';
    data.map.map[0][3] = '1';
    data.map.map[0][4] = '1';
    data.map.map[0][5] = '1';
    data.map.map[0][6] = '1';
    data.map.map[0][7] = '1';
    data.map.map[0][8] = '\0';

    data.map.map[1][0] = '1';
    data.map.map[1][1] = '0';
    data.map.map[1][2] = '1';
    data.map.map[1][3] = '0';
    data.map.map[1][4] = '0';
    data.map.map[1][5] = '0';
    data.map.map[1][6] = '0';
    data.map.map[1][7] = '1';
    data.map.map[1][8] = '\0';

    data.map.map[2][0] = '1';
    data.map.map[2][1] = '0';
    data.map.map[2][2] = '1';
    data.map.map[2][3] = '0';
    data.map.map[2][4] = '0';
    data.map.map[2][5] = '0';
    data.map.map[2][6] = '0';
    data.map.map[2][7] = '1';
    data.map.map[2][8] = '\0';

    data.map.map[3][0] = '1';
    data.map.map[3][1] = '0';
    data.map.map[3][2] = '1';
    data.map.map[3][3] = '0';
    data.map.map[3][4] = '0';
    data.map.map[3][5] = '0';
    data.map.map[3][6] = '0';
    data.map.map[3][7] = '1';
    data.map.map[3][8] = '\0';

    data.map.map[4][0] = '1';
    data.map.map[4][1] = '0';
    data.map.map[4][2] = '0';
    data.map.map[4][3] = '0';
    data.map.map[4][4] = '0';
    data.map.map[4][5] = '0';
    data.map.map[4][6] = '0';
    data.map.map[4][7] = '1';
    data.map.map[4][8] = '\0';

	data.map.map[5][0] = '1';
    data.map.map[5][1] = '1';
    data.map.map[5][2] = '1';
    data.map.map[5][3] = '1';
    data.map.map[5][4] = '1';
    data.map.map[5][5] = '1';
    data.map.map[5][6] = '1';
    data.map.map[5][7] = '1';
    data.map.map[5][8] = '\0';

    data.map.map[6] = NULL;
}