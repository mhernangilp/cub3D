/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:47:24 by gfernand          #+#    #+#             */
/*   Updated: 2024/02/08 17:26:22 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static int	exkey(t_cub	*cub);
static int	keyb(int key, t_cub *cub);

void	window(t_cub *cub)
{
	mlx_hook(cub->win, 02, 1L << 0, &keyb, cub);
	mlx_hook(cub->win, 17, 1L < 17, &exkey, cub);
	mlx_loop(cub->mlx);
	mlx_destroy_window(cub->mlx, cub->win);
	free(cub->mlx);
}

static int	exkey(t_cub	*cub)
{
	mlx_destroy_window(cub->mlx, cub->win);
	cub->win = NULL;
	exit(1);
}

static int	keyb(int key, t_cub *cub)
{
	if (key == 53)
	{
		mlx_destroy_window(cub->mlx, cub->win);
		cub->win = NULL;
		exit(1);
	}
	if(key== 0)
		cub->p_x -= 5;
 	if(key== 2)
		cub->p_x += 5;
 	if(key== 13)
		cub->p_y -= 5;
 	if(key== 1)
		cub->p_y += 5;
	if (key == 0 || key == 1 || key == 2 || key == 13)
	{
		mlx_clear_window(cub->mlx, cub->win);
		drawMap2D(*cub);
	}
	return (0);
}
