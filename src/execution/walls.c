/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:54:59 by gfernand          #+#    #+#             */
/*   Updated: 2024/03/25 13:55:02 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	rd_angle(t_ray *ray, int pa, int i, int w);

void	walls(t_cub cub, t_ray ray)
{
	float	ray_angle;
	t_brsh		brsh;
	float	reverse;
	int		color;
	int		pixels_per_ray;

	pixels_per_ray = 0;
	ray_angle = 60.0;
	reverse = 0.0;
	color = 0xF0000F;
	while (ray_angle > 0.0)
	{
		ray.ra = cub.pa - cub.ray.angle + ray_angle;
		vertical(cub, &ray);
		horizontal(cub, &ray);
		if (ray.d_v < ray.d_h)
		{
			ray.rx = ray.vx;
			ray.ry = ray.vy;
			ray.d_h = ray.d_v;
			rd_angle(&ray, cub.pa, 0, reverse);
			if (ray.look == 1)
				color = 0xFFF000;
			else if (ray.look == 2)
				color = 0x000FFF;
		}
		else
		{
			rd_angle(&ray, cub.pa, 1, reverse);
			if (ray.look == 1)
				color = 0x000000;
			else if (ray.look == 2)
				color = 0xFFFFFF;
		}
		int p = 0;
		while (p++ < 2)
		{
			brsh.x0 = reverse * 10 + p + pixels_per_ray;
  			brsh.y0 = (W_HEIGHT / 2) - ((MAP_SCALE * 1150) / ray.d_h / 2);
    		brsh.x1 = brsh.x0;
    		brsh.y1 = brsh.y0 + (MAP_SCALE * 1150) / ray.d_h;
			bresenham_line(cub, brsh, color);
		}
		ray_angle -= 0.1;
		reverse += 0.1;
		pixels_per_ray++;
	}
}

void	rd_angle(t_ray *ray, int pa, int i, int w)
{
	int	ag;

	ag = ray->angle + pa + w;
	if (ag > 360)
		ag -= 360;
	if (ag < -360)
		ag += 360;
	if (i == 1)
	{
		if ((ag > 180 && ag < 360) || (ag < 0 && ag > -180))
			ray->look = 1;
		else if ((ag > 0 && ag < 180) || (ag < -180 && ag > -360))
			ray->look = 2;
		else if (ag == 180 || ag == -180 || ag == 0 || ag == 360 || ag == -360)
			ray->look = 3;
	}
	else
	{
		if ((ag > -90 && ag < 90) || (ag < -270 && ag > -361) || (ag > 270 && ag < 361))
			ray->look = 1;
		else if ((ag > 90 && ag < 270) || (ag < -90 && ag > -270))
			ray->look = 2;
		else if (ag == 90 || ag == -270 || ag == 270 || ag == -90)
			ray->look = 3;
	}
	if (ray->look == 3)
		printf("ray->look: %d\n", ray->look);
}
