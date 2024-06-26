/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <mhernang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:50:49 by gfernand          #+#    #+#             */
/*   Updated: 2024/04/16 17:08:50 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	f_c(t_cub cub);

void	map2d(t_cub cub, t_ray ray)
{
	int		x;
	int		y;
	char	**m;

	m = cub.data.map.map;
	f_c(cub);
	walls(cub, ray);
	y = -1;
	while (m[++y])
	{
		x = -1;
		while (m[y][++x])
		{
			if (m[y][x] == '1')
				box(cub, x, y, 0xFFFFFF);
			else if (m[y][x] == '0')
				box(cub, x, y, 0x808080);
		}
	}
	player(cub, ray);
	throw_rays(cub, ray);
}

void	box(t_cub cub, int x, int y, int color)
{
	int	s;
	int	u;
	int	xa;
	int	ya;

	s = 0;
	while (++s < 64)
	{
		u = 0;
		while (++u < 64)
		{
			xa = x * MAP_SCALE + s;
			ya = y * MAP_SCALE + u;
			set_pixel(cub.img, xa / 5, ya / 5, color);
		}
	}
}

void	player(t_cub cub, t_ray ray)
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
			set_pixel(cub.img, rotated_x / 5, rotated_y / 5, 0x0FF000);
		}
	}
}

void	f_c(t_cub cub)
{
	int	x;
	int	y;

	x = -1;
	while (++x < W_WIDTH)
	{
		y = -1;
		while (++y < W_HEIGHT / 2)
			set_pixel(cub.img, x, y, cub.data.c);
	}
	x = -1;
	while (++x < W_WIDTH)
	{
		y = W_HEIGHT / 2 - 1;
		while (++y < W_HEIGHT)
			set_pixel(cub.img, x, y, cub.data.f);
	}
}

void	throw_rays(t_cub cub, t_ray ray)
{
	float	r;
	t_brsh	brsh;

	r = 60.0;
	while (r > 0.0)
	{
		ray.ra = cub.pa - cub.ray.angle + r;
		vertical(cub, &ray);
		horizontal(cub, &ray);
		if (ray.d_v < ray.d_h)
		{
			ray.rx = ray.vx;
			ray.ry = ray.vy;
			ray.d_h = ray.d_v;
		}
		brsh.x0 = cub.px / 5;
		brsh.y0 = cub.py / 5;
		brsh.x1 = ray.rx / 5;
		brsh.y1 = ray.ry / 5;
		bresenham_line(cub, brsh, 0xFF0000);
		r -= 0.1;
	}
}
