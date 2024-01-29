/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:13:32 by gfernand          #+#    #+#             */
/*   Updated: 2024/01/29 18:56:51 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	leaks(void)
{
	system("leaks cub3D");
}

int	main(int arg, char **argv)
{
	t_mlx	mlx;

	atexit(leaks);
	if (arg < 2)
		exit_mssg("Error: 2 arguments are spected\n");
	check_map(argv[1]);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 900, 600, "cub3D");
	if (mlx.win == NULL)
		exit_mssg("Wrong window\n");
	window(&mlx);
	return (0);
}

void	exit_mssg(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		write(2, (s + i), 1);
	exit(0);
}
