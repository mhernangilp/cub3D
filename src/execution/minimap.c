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

void drawMap2D(t_cub cub)
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
	draw_player(cub);
	if (cub.angle < PI)
		printf("HOLA\n");
	if (cub.angle > PI)
		printf("ADIOS\n");
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

void draw_player(t_cub cub)
{
    int s;
    int u;
    int square_size = 20;

    int origin_x = cub.p_x;
    int origin_y = cub.p_y;
    float radians = cub.angle * (M_PI / 180.0);
    int rotated_x = 0;
    int rotated_y = 0;
    
    s = -1;
    while (++s < square_size)
    {
        u = -1;
        while (++u < square_size)
        {
            rotated_x = round((s - square_size / 2) * cos(radians) - (u - square_size / 2) * sin(radians)) + origin_x;
            rotated_y = round((s - square_size / 2) * sin(radians) + (u - square_size / 2) * cos(radians)) + origin_y;
            mlx_pixel_put(cub.mlx, cub.win, rotated_x, rotated_y, 0x00FF00);
        }
    }
    int end_x1 = round(10 * cos(radians - M_PI / 2)) + origin_x;
    int end_y1 = round(10 * sin(radians - M_PI / 2)) + origin_y;
    int end_x2 = end_x1 + round(50 * cos(radians));
    int end_y2 = end_y1 + round(50 * sin(radians));

    // Dibujar la línea perpendicular al lado del cuadrado
    bresenham_line(cub.mlx, cub.win, end_x1, end_y1, end_x2, end_y2, 0x00FF00);
}

// Algoritmo de Bresenham para dibujar una línea
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