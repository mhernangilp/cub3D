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
static void	wasd(t_cub *cub, int key);

void	window(t_cub *cub)
{
	mlx_hook(cub->win, 02, 1L << 0, &keyb, cub);
	mlx_hook(cub->win, 17, 1L < 17, &exkey, cub);
	mlx_loop(cub->mlx);
	mlx_destroy_image(cub->mlx, cub->img->img);
	mlx_destroy_window(cub->mlx, cub->win);
	free(cub->mlx);
}

static int	exkey(t_cub	*cub)
{
	mlx_destroy_image(cub->mlx, cub->img->img);
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
	wasd(cub, key);
	if (key == 123)
		cub->ray.angle -= 10;
	if (key == 124)
		cub->ray.angle += 10;
	if (cub->ray.angle > 360)
		cub->ray.angle -= 360;
	if (cub->ray.angle < -360)
		cub->ray.angle += 360;
	if (key == 0 || key == 1 || key == 2 || key == 13
		|| key == 123 || key == 124)
	{
		mlx_clear_window(cub->mlx, cub->win);
		map2d(*cub, cub->ray);
		mlx_put_image_to_window(cub->mlx, cub->win, cub->img->img, 0, 0);
	}
	return (0);
}

static void	wasd(t_cub *cub, int key)
{
	int		stop_x;
	int		stop_y;
	int		i;

	stop_x = cub->px;
	stop_y = cub->py;
	i = 0;
	while (++i < 40)
	{
		if (key == 0)
		{
			stop_x = cub->px + (i * sin(cub->ray.angle * (M_PI / 180.0)));
			stop_y = cub->py + (i * -cos(cub->ray.angle * (M_PI / 180.0)));
		}
		if (key == 2)
		{
			stop_x = cub->px + (i * -sin(cub->ray.angle * (M_PI / 180.0)));
			stop_y = cub->py + (i * cos(cub->ray.angle * (M_PI / 180.0)));
		}
		if (key == 13)
		{
			stop_x = cub->px + (i * cos(cub->ray.angle * (M_PI / 180.0)));
			stop_y = cub->py + (i * sin(cub->ray.angle * (M_PI / 180.0)));
		}
		if (key == 1)
		{
			stop_x = cub->px + (i * -cos(cub->ray.angle * (M_PI / 180.0)));
			stop_y = cub->py + (i * -sin(cub->ray.angle * (M_PI / 180.0)));
		}
		if ((cub->data.map.map[(int)floor(stop_y / MAP_SCALE)][(int)(stop_x / MAP_SCALE)] == '1')
			&& (cub->data.map.map[(int)(stop_y / MAP_SCALE)][(int)floor(stop_x / MAP_SCALE)] == '1'))
			return ;
	}
	if (cub->data.map.map[(int)floor(stop_y / MAP_SCALE)][(int)(stop_x / MAP_SCALE)] != '1')
	{
		if (key == 0)
			cub->px += 20 * sin(cub->ray.angle * (M_PI / 180.0));
		if (key == 2)
			cub->px += 20 * -sin(cub->ray.angle * (M_PI / 180.0));
		if (key == 13)
			cub->px += 20 * cos(cub->ray.angle * (M_PI / 180.0));
		if (key == 1)
			cub->px += 20 * -cos(cub->ray.angle * (M_PI / 180.0));
	}
	if (cub->data.map.map[(int)(stop_y / MAP_SCALE)][(int)floor(stop_x / MAP_SCALE)] != '1')
	{
		if (key == 0)
			cub->py += 20 * -cos(cub->ray.angle * (M_PI / 180.0));
		if (key == 2)
			cub->py += 20 * cos(cub->ray.angle * (M_PI / 180.0));
		if (key == 13)
			cub->py += 20 * sin(cub->ray.angle * (M_PI / 180.0));
		if (key == 1)
			cub->py += 20 * -sin(cub->ray.angle * (M_PI / 180.0));
	}
}
