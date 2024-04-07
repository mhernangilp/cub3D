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

void	rd_angle(t_ray *ray, int pa, int i, float w);
//t_img	side_texture(t_cub cub, t_ray *ray, float w);
void	draw(t_cub cub, t_ray *ray, float reverse, int pixels_per_ray);

void	walls(t_cub cub, t_ray ray)
{
	float	ray_angle;
	float	reverse;
	int		pixels_per_ray;

	pixels_per_ray = 0;
	ray_angle = 60.0;
	reverse = 0.0;
	while (ray_angle > 0.0)
	{
		ray.ra = cub.pa - cub.ray.angle + ray_angle;
		vertical(cub, &ray);
		horizontal(cub, &ray);
		draw(cub, &ray, reverse, pixels_per_ray);
		ray_angle -= 0.1;
		reverse += 0.1;
		pixels_per_ray++;
	}
}

void	draw(t_cub cub, t_ray *ray, float reverse, int pixels_per_ray)
{
	t_brsh		brsh;
	int			p;

	if (ray->d_v < ray->d_h)
	{
		ray->rx = ray->vx;
		ray->ry = ray->vy;
		ray->d_h = ray->d_v;
		rd_angle(ray, cub.pa, 0, reverse);
	}
	else
		rd_angle(ray, cub.pa, 1, reverse);
	p = 0;
	while (p++ < 2)
	{
		brsh.x0 = reverse * 10 + p + pixels_per_ray;
		brsh.y0 = (W_HEIGHT / 2) - ((MAP_SCALE * 1150) / ray->d_h / 2);
		brsh.x1 = brsh.x0;
		brsh.y1 = brsh.y0 + (MAP_SCALE * 1150) / ray->d_h;
		bresenham_line(cub, brsh, ray->color);
	}
}

void	rd_angle(t_ray *ray, int pa, int i, float w)
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
			ray->color = 0x000000;
		else if ((ag > 0 && ag < 180) || (ag < -180 && ag > -360))
			ray->color = 0xFFFFFF;
		else if (ag == 180 || ag == -180 || ag == 0 || ag == 360 || ag == -360)
			ray->look = 3;
	}
	else
	{
		if ((ag > -90 && ag < 90) || (ag < -270 && ag > -361)
			|| (ag > 270 && ag < 361))
			ray->color = 0xFFF000;
		else if ((ag > 90 && ag < 270) || (ag < -90 && ag > -270))
			ray->color = 0x000FFF;
		else if (ag == 90 || ag == -270 || ag == 270 || ag == -90)
			ray->look = 3;
	}
	if (ray->look == 3)
		printf("ray->look: %d\n", ray->look);
}
/*
void	draw(t_cub cub, t_ray *ray, float reverse, int pixels_per_ray)
{
	t_brsh	brsh;
	t_img   texture;

	texture = side_texture(cub, ray, reverse);
	int p = 0;
	while (p++ < 1)
	{
		brsh.x0 = reverse * 10 + p + pixels_per_ray;
		brsh.y0 = (W_HEIGHT / 2) - ((MAP_SCALE * 1150) / ray->d_h / 2);
		brsh.x1 = brsh.x0;
		brsh.y1 = brsh.y0 + (MAP_SCALE * 1150) / ray->d_h;
		bresenham_line(cub, brsh, ray->color);
	}
}

t_img	side_texture(t_cub cub, t_ray *ray, float w)
{
	int	ag;
	t_img   texture;

	ag = ray->angle + cub.pa + w;
	if (ag > 360)
		ag -= 360;
	if (ag < -360)
		ag += 360;
	if (ray->d_v < ray->d_h)
	{
		ray->rx = ray->vx;
		ray->ry = ray->vy;
		ray->d_h = ray->d_v;
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
}*/