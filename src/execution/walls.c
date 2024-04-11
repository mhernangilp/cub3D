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

t_img	side_texture(t_cub cub, t_ray *ray, float w, int i);
void	draw(t_cub cub, t_ray *ray, float reverse);
void	draw_vertical_line(t_cub *cub, t_draw draw, t_ray *ray);
int		get_color_from_image(t_img *img, int x, int y);

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

void draw_vertical_line(t_cub *cub, t_draw draw, t_ray *ray)
{
	int i;
	float x;
	int y;
	int color;

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

t_img	side_texture(t_cub cub, t_ray *ray, float w, int i)
{
	int	ag;
	t_img   texture;

	ag = ray->angle + cub.pa + w;
	if (ag > 360)
		ag -= 360;
	if (ag < -360)
		ag += 360;
	if (i == 1)
	{
		if ((ag > 180 && ag < 360) || (ag < 0 && ag > -180))
			texture = cub.no_tex;
		else
			texture = cub.so_tex;
	}
	else
	{
		if ((ag > -90 && ag < 90) || (ag < -270 && ag > -361)
			|| (ag > 270 && ag < 361))
			texture = cub.ea_tex;
		else
			texture = cub.we_tex;
	}
	return (texture);
}

int	get_color_from_image(t_img *img, int x, int y)
{
	char	*dst;
	int		length;
	int		bpp;

	if (x < 0 || y < 0 || x >= 32 || y >= 32)
		return (0);
	length = img->line;
	bpp = img->bits;
	dst = img->addr + (y * length + x * (bpp / 8));
	return (*(unsigned int *)dst);
}