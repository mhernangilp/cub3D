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
		rd_angle(ray, cub.pa, 0, reverse);
	}
	else
		rd_angle(ray, cub.pa, 1, reverse);
	draw.x = reverse * 20;
	draw.y = (W_HEIGHT / 2) - ((MAP_SCALE * 1150) / ray->d_h / 2);
	draw.len = (MAP_SCALE * 1150) / ray->d_h;
	draw_vertical_line(&cub, draw, ray);
}

void draw_vertical_line(t_cub *cub, t_draw draw, t_ray *ray)
{
	int i;
	int x;
	int y;
	int color;
		
	i = -1;
	while (++i <= draw.len)
	{
		x = draw.x * 31 / draw.len;
		while (x > 31)
			x -= 32;
		y = (i * 32) / draw.len;
		if (y > 31)
			y = 31;
		if (ray->look == 1)
			color = get_color_from_image(&cub->no_tex, x, y++);
		else if (ray->look == 2)
			color = get_color_from_image(&cub->so_tex, x, y++);
		else
			color = get_color_from_image(&cub->we_tex, x, y++);
		set_pixel(cub->img, draw.x, draw.y + i, color);
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
			ray->look = 1; //textura norte
		else if ((ag > 0 && ag < 180) || (ag < -180 && ag > -360))
			ray->look = 2; //textura sur
		else if (ag == 180 || ag == -180 || ag == 0 || ag == 360 || ag == -360)
			ray->look = 5;
	}
	else
	{
		if ((ag > -90 && ag < 90) || (ag < -270 && ag > -361)
			|| (ag > 270 && ag < 361))
			ray->look = 3; //textura este
		else if ((ag > 90 && ag < 270) || (ag < -90 && ag > -270))
			ray->look = 4; //textura oeste
		else if (ag == 90 || ag == -270 || ag == 270 || ag == -90)
			ray->look = 5;
	}
	if (ray->look == 5)
		printf("ray->look: %d\n", ray->look);
}
/*
void	draw(t_cub cub, t_ray *ray, float reverse)
{
	t_draw	draw;
	t_img   texture;

	texture = side_texture(cub, ray, reverse);
	draw.x = reverse * 20;
	draw.y = (W_HEIGHT / 2) - ((MAP_SCALE * 1150) / ray->d_h / 2);
	draw.len = (MAP_SCALE * 1150) / ray->d_h;
	draw_vertical_line(draw, cub.img, ray->color);
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
}*/

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