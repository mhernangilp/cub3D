/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:47:24 by gfernand          #+#    #+#             */
/*   Updated: 2024/01/29 17:18:54 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static int	exkey(t_mlx	*mlx);
static int	keyb(int key, t_mlx *mlx);

void	window(t_mlx *mlx)
{
	mlx_hook(mlx->win, 02, 1L << 0, &keyb, mlx);
	mlx_hook(mlx->win, 17, 1L < 17, &exkey, mlx);
	mlx_loop(mlx->mlx);
	mlx_destroy_window(mlx->mlx, mlx->win);
	free(mlx->mlx);
}

static int	exkey(t_mlx	*mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx->win = NULL;
	exit(1);
}

static int	keyb(int key, t_mlx *mlx)
{
	if (key == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		mlx->win = NULL;
		exit(1);
	}
	return (0);
}
