/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:50:49 by gfernand          #+#    #+#             */
/*   Updated: 2024/02/20 17:50:51 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	rd_angle(t_ray ray);
void	black(t_cub cub);

void	draw_map2d(t_cub cub, t_ray ray)
{
	int		x;
	int		y;
	char	**m;

	m = cub.data.mp;
	black(cub);
	y = -1;
	while (m[++y])
	{
		x = -1;
		while (m[y][++x])
		{
			if (m[y][x] == '1')
				box(cub, x, y, 0xFFFFFF);
			else
				box(cub, x, y, 0x808080);
		}
	}
	draw_player(cub, ray);
	rd_angle(ray);
	draw_rays2d(cub, ray);
}

void	rd_angle(t_ray ray)
{
	int	ag;

	ag = ray.angle;
	ray.radians = ag *(PI / 180.0);
	if (ray.radians < 0)
		ray.radians += 2 * PI;
	if (ray.radians > 2 * PI)
		ray.radians -= 2 * PI;
	if ((ag > 180 && ag < 360) || (ag < 0 && ag > -180))
		ray.look = 1; /* Arriba */
	else if ((ag > 0 && ag < 180) || (ag < -180 && ag > -360))
		ray.look = 2; /* Debajo */
	else if (ag == 180 || ag == -180)
		ray.look = 3; /* Izquierda */
	else if (ag == 0 || ag == 360 || ag == -360)
		ray.look = 4; /* Derecha */
}

void	box(t_cub cub, int x, int y, int color)
{
	int	s;
	int	u;
	int	xa;
	int	ya;

	s = 0;
	while (++s < 60)
	{
		xa = x * MAP_SCALE + s;
		ya = y * MAP_SCALE;
		set_pixel(&cub, xa, ya, color);
		u = 0;
		while (++u < 60)
		{
			xa = x * MAP_SCALE + s;
			ya = y * MAP_SCALE + u;
			set_pixel(&cub, xa, ya, color);
		}
	}
}

void	draw_player(t_cub cub, t_ray ray)
{
	int		s;
	int		u;
	float	rotated_x;
	float	rotated_y;

	ray.radians = ray.angle *(PI / 180.0);
	s = -SQR_SIZE / 2;
	while (s++ < SQR_SIZE / 2)
	{
		u = -SQR_SIZE / 2;
		while (u++ < SQR_SIZE / 2)
		{
			rotated_x = (s * cos(ray.radians) - u * sin(ray.radians)) + cub.px;
			rotated_y = (s * sin(ray.radians) + u * cos(ray.radians)) + cub.py;
			set_pixel(&cub, rotated_x, rotated_y, 0x00FF00);
		}
	}
}

void	black(t_cub cub)
{
	int	x;
	int	y;

	x = -1;
	while (++x < W_WIDTH)
	{
		y = -1;
		while (++y < W_HEIGHT)
			set_pixel(&cub, x, y, 0);
	}
}