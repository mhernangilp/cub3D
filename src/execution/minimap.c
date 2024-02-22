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

#define MAP_WIDTH  8      //map width
#define MAP_HEIGHT  8      //map height
#define MAP_SCALE 64      //map cube size

void bresenham_line(void *mlx, void *win, int x0, int y0, int x1, int y1, int color);

void drawMap2D(t_cub cub, t_ray ray)
{
	int map[] = {
		1,1,1,1,1,1,1,1,
		1,0,1,0,0,0,0,1,
		1,0,1,0,0,0,0,1,
		1,0,1,0,0,0,0,1,
		1,0,0,0,0,0,0,1,
		1,0,0,0,0,1,0,1,
		1,0,0,0,0,0,0,1,
		1,1,1,1,1,1,1,1
	};

	int	x;
	int y;

	for (y = 0; y < MAP_HEIGHT; y++) {
		for (x = 0; x < MAP_WIDTH; x++) {
			if (map[y * MAP_WIDTH + x] == 1)
				box(cub, x, y, 0xFFFFFF);
			else
				box(cub, x, y, 0x808080);
		}
	}
	draw_player(cub, ray);

    ray.radians = ray.angle *(PI / 180.0);
    if (ray.radians < 0)
		ray.radians += 2 * PI;
	if (ray.radians > 2 * PI)
		ray.radians -= 2 * PI;


    printf("GRADOS->%d    RADIANES->%f\n", ray.angle, ray.radians);
    if (ray.radians > 6)
        ray.radians -= 6;
	if (ray.radians > PI)
        printf("POSITIVO\n");
   	else if (ray.radians < PI)
		printf("NRGA\n");
}

void box(t_cub cub, int x, int y, int color)
{
	int s;
	int	u;

	s = 0;
	while (++s < 60)
	{
		mlx_pixel_put(cub.mlx, cub.win, x * MAP_SCALE + s, y * MAP_SCALE, color);
		u = 0;
		while (++u < 60)
			mlx_pixel_put(cub.mlx, cub.win, x * MAP_SCALE + s, y * MAP_SCALE + u, color);
	}
}

void draw_player(t_cub cub, t_ray ray)
{
    int s;
    int u;
    int square_size = 10;
    float rotated_x;
    float rotated_y;

    ray.radians = ray.angle *(PI / 180.0);
	s = -square_size / 2;
    while (s++ < square_size / 2)
    {
		u = -square_size / 2;
        while (u++ < square_size / 2 )
        {
            rotated_x = (s * cos(ray.radians) - u * sin(ray.radians)) + cub.p_x;
            rotated_y = (s * sin(ray.radians) + u * cos(ray.radians)) + cub.p_y;
            mlx_pixel_put(cub.mlx, cub.win, rotated_x, rotated_y, 0x00FF00);
        }
    }

    int end_x1 = cub.p_x + square_size / 2 * cos(ray.radians);
    int end_y1 = cub.p_y + square_size / 2 * sin(ray.radians);
    int end_x2 = end_x1 + 50 * cos(ray.radians);
    int end_y2 = end_y1 + 50 * sin(ray.radians);
    bresenham_line(cub.mlx, cub.win, end_x1, end_y1, end_x2, end_y2, 0x00FF00);
}

void bresenham_line(void *mlx, void *win, int x0, int y0, int x1, int y1, int color)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;

    while (1)
    {
        mlx_pixel_put(mlx, win, x0, y0, color);
        if (x0 == x1 && y0 == y1)
            break;
        e2 = err;
        if (e2 > -dx)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            y0 += sy;
        }
    }
}
