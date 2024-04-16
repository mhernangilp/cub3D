/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:26:42 by gfernand          #+#    #+#             */
/*   Updated: 2024/04/16 14:26:44 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static int	stop_height(t_cub *cub, int i, int key);
static int	stop_width(t_cub *cub, int i, int key);
static void	move(t_cub *cub, int key);

void	wasd(t_cub *cub, int key)
{
	int	stop_x;
	int	stop_y;
	int	i;

	stop_x = cub->px;
	stop_y = cub->py;
	i = 0;
	while (++i < 40)
	{
		stop_x = stop_width(cub, i, key);
		stop_y = stop_height(cub, i, key);
		if ((cub->data.map.map[(int)floor(stop_y / MAP_SCALE)]
				[(int)(stop_x / MAP_SCALE)] == '1')
			|| (cub->data.map.map[(int)(stop_y / MAP_SCALE)]
			[(int)floor(stop_x / MAP_SCALE)] == '1'))
			return ;
	}
	move(cub, key);
}

static void	move(t_cub *cub, int key)
{
	if (key == 0)
	{
		cub->px += 20 * sin(cub->ray.angle * (M_PI / 180.0));
		cub->py += 20 * -cos(cub->ray.angle * (M_PI / 180.0));
	}
	if (key == 2)
	{
		cub->px += 20 * -sin(cub->ray.angle * (M_PI / 180.0));
		cub->py += 20 * cos(cub->ray.angle * (M_PI / 180.0));
	}
	if (key == 13)
	{
		cub->px += 20 * cos(cub->ray.angle * (M_PI / 180.0));
		cub->py += 20 * sin(cub->ray.angle * (M_PI / 180.0));
	}
	if (key == 1)
	{
		cub->px += 20 * -cos(cub->ray.angle * (M_PI / 180.0));
		cub->py += 20 * -sin(cub->ray.angle * (M_PI / 180.0));
	}
}

static int	stop_width(t_cub *cub, int i, int key)
{
	if (key == 0)
		return (cub->px + (i * sin(cub->ray.angle * (M_PI / 180.0))));
	if (key == 2)
		return (cub->px + (i * -sin(cub->ray.angle * (M_PI / 180.0))));
	if (key == 13)
		return (cub->px + (i * cos(cub->ray.angle * (M_PI / 180.0))));
	if (key == 1)
		return (cub->px + (i * -cos(cub->ray.angle * (M_PI / 180.0))));
	return (0);
}

static int	stop_height(t_cub *cub, int i, int key)
{
	if (key == 0)
		return (cub->py + (i * -cos(cub->ray.angle * (M_PI / 180.0))));
	if (key == 2)
		return (cub->py + (i * cos(cub->ray.angle * (M_PI / 180.0))));
	if (key == 13)
		return (cub->py + (i * sin(cub->ray.angle * (M_PI / 180.0))));
	if (key == 1)
		return (cub->py + (i * -sin(cub->ray.angle * (M_PI / 180.0))));
	return (0);
}
