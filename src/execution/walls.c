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

void	draw(t_cub cub, t_ray *ray, float reverse);
void	draw_vertical_line(t_cub *cub, t_draw draw, t_ray *ray);

void	walls(t_cub cub, t_ray ray)
{
	float	ray_angle;
	float	reverse;

	ray_angle = 60.0;
	reverse = 0.0;
	while (ray_angle >= 0.0)
	{
		ray.ra = cub.pa - cub.ray.angle + ray_angle;
		vertical(cub, &ray);
		horizontal(cub, &ray);
		draw(cub, &ray, reverse);
		ray_angle -= 0.05;
		reverse += 0.05;
	}
}

void	draw(t_cub cub, t_ray *ray, float reverse)
{
	t_draw	draw;

	if (ray->d_v < ray->d_h)
	{
		ray->rx = ray->vx;
		ray->ry = ray->vy;
		ray->d_h = ray->d_v;
		draw.texture = side_texture(cub, ray, reverse, 0);
	}
	else
		draw.texture = side_texture(cub, ray, reverse, 1);
	draw.x = reverse * 20;
	draw.y = (W_HEIGHT / 2) - ((MAP_SCALE * 1150) / ray->d_h / 2);
	draw.len = (MAP_SCALE * 1150) / ray->d_h;
	draw_vertical_line(&cub, draw, ray);
}

void	draw_vertical_line(t_cub *cub, t_draw draw, t_ray *ray)
{
	float	x;
	int		y;
	int		color;
	int		i;

	x = ray->rx / 64 * 32;
	if (ray->d_h == ray->d_v)
		x = ray->ry / 64 * 32;
	while (x > 31)
		x -= 32;
	i = -1;
	while (++i <= draw.len)
	{
		y = (i * 32) / draw.len;
		if (y > 31)
			y = 31;
		color = get_color_from_image(&draw.texture, x, y++);
		if (draw.y + i <= W_HEIGHT && draw.y + i >= 0)
			set_pixel(cub->img, draw.x, draw.y + i, color);
	}
}
