/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <mhernang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:54:50 by gfernand          #+#    #+#             */
/*   Updated: 2024/04/16 15:46:39 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	vertical_loop(t_cub cub, t_ray *ray);
void	horizontal_loop(t_cub cub, t_ray *ray);

void	vertical(t_cub cub, t_ray *ray)
{
	ray->dof = 0;
	ray->d_v = 100000;
	ray->tan = tan(ray->ra * (PI / 180.0));
	if (cos(ray->ra * (PI / 180.0)) > 0.001)
	{
		ray->rx = (((int)cub.px >> 6) << 6) + 64;
		ray->ry = (cub.px - ray->rx) * ray->tan + cub.py;
		ray->xo = 64;
		ray->yo = -ray->xo * ray->tan;
	}
	else if (cos(ray->ra * (PI / 180.0)) < -0.001)
	{
		ray->rx = (((int)cub.px >> 6) << 6) - 0.0001;
		ray->ry = (cub.px - ray->rx) * ray->tan + cub.py;
		ray->xo = -64;
		ray->yo = -ray->xo * ray->tan;
	}
	else
	{
		ray->rx = cub.px;
		ray->ry = cub.py;
		ray->dof = cub.map_w;
	}
	vertical_loop(cub, ray);
}

void	vertical_loop(t_cub cub, t_ray *ray)
{
	int	mx;
	int	my;

	while (ray->dof < cub.map_w + 1)
	{
		mx = (int)(ray->rx) >> 6;
		my = (int)(ray->ry) >> 6;
		if (my >= 0 && my < cub.map_h && mx >= 0 && mx < cub.map_w
			&& cub.data.map.map[my][mx] == '1')
		{
			ray->dof = cub.map_w + 1;
			ray->d_v = cos(ray->ra * (PI / 180.0)) * (ray->rx - cub.px)
				- sin(ray->ra * (PI / 180.0)) * (ray->ry - cub.py);
		}
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof += 1;
		}
	}
	ray->vx = ray->rx;
	ray->vy = ray->ry;
}

void	horizontal(t_cub cub, t_ray *ray)
{
	ray->dof = 0;
	ray->d_h = 100000;
	ray->tan = 1.0 / ray->tan;
	if (sin(ray->ra * (PI / 180.0)) > 0.001)
	{
		ray->ry = (((int)cub.py >> 6) << 6) - 0.0001;
		ray->rx = (cub.py - ray->ry) * ray->tan + cub.px;
		ray->yo = -64;
		ray->xo = -ray->yo * ray->tan;
	}
	else if (sin(ray->ra * (PI / 180.0)) < -0.001)
	{
		ray->ry = (((int)cub.py >> 6) << 6) + 64;
		ray->rx = (cub.py - ray->ry) * ray->tan + cub.px;
		ray->yo = 64;
		ray->xo = -ray->yo * ray->tan;
	}
	else
	{
		ray->rx = cub.px;
		ray->ry = cub.py;
		ray->dof = cub.map_h;
	}
	horizontal_loop(cub, ray);
}

void	horizontal_loop(t_cub cub, t_ray *ray)
{
	int	mx;
	int	my;

	while (ray->dof < cub.map_h + 1)
	{
		mx = (int)(ray->rx) >> 6;
		my = (int)(ray->ry) >> 6;
		if (my >= 0 && my < cub.map_h && mx >= 0 && mx < cub.map_w
			&& cub.data.map.map[my][mx] == '1')
		{
			ray->dof = cub.map_h + 1;
			ray->d_h = cos(ray->ra * (PI / 180.0)) * (ray->rx - cub.px)
				- sin(ray->ra * (PI / 180.0)) * (ray->ry - cub.py);
		}
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof += 1;
		}
	}
}
