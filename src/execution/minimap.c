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

void    drawRays2D(t_cub cub);
void    rd_angle(t_ray ray);
void    bresenham_line(t_cub cub, t_brsh brsh, int color);

void drawMap2D(t_cub cub, t_ray ray)
{
	int map[] = {
		1,1,1,1,1,1,1,1,
		1,0,1,0,0,0,0,1,
		1,0,1,0,0,0,0,1,
		1,0,1,0,0,0,0,1,
		1,0,0,0,0,0,0,1,
		1,1,1,1,1,1,1,1
	};

    cub.map = map;
	int	x;
	int y;
    char    **m;

    m = cub.data.mp;
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
    drawRays2D(cub);
}

void    rd_angle(t_ray ray)
{
    ray.radians = ray.angle *(PI / 180.0);
    if (ray.radians < 0)
		ray.radians += 2 * PI;
	if (ray.radians > 2 * PI)
		ray.radians -= 2 * PI;
    printf("GRADOS-> %d    RADIANES-> %f\n", ray.angle, ray.radians);
    if ((ray.angle > 180 && ray.angle < 360) || (ray.angle < 0 && ray.angle > -180))
		ray.look = 1; //Arriba
	else if ((ray.angle > 0 && ray.angle < 180) || (ray.angle < -180 && ray.angle > -360))
        ray.look = 2; //Debajo
    else if (ray.angle == 180 || ray.angle == -180)
        ray.look = 3; // Izquierda
    else if(ray.angle == 0 || ray.angle == 360 || ray.angle == -360)
        ray.look = 4; //Derecha
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
    float rotated_x;
    float rotated_y;

    ray.radians = ray.angle *(PI / 180.0);
	s = -SQR_SIZE / 2;
    while (s++ < SQR_SIZE / 2)
    {
		u = -SQR_SIZE / 2;
        while (u++ < SQR_SIZE / 2 )
        {
            rotated_x = (s * cos(ray.radians) - u * sin(ray.radians)) + cub.px;
            rotated_y = (s * sin(ray.radians) + u * cos(ray.radians)) + cub.py;
            mlx_pixel_put(cub.mlx, cub.win, rotated_x, rotated_y, 0x00FF00);
        }
    }
}

void bresenham_line(t_cub cub, t_brsh brsh, int color)
{
    int dx = abs(brsh.x1 - brsh.x0);
    int dy = abs(brsh.y1 - brsh.y0);
    int sx = brsh.x0 < brsh.x1 ? 1 : -1;
    int sy = brsh.y0 < brsh.y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;

    while (1)
    {
        mlx_pixel_put(cub.mlx, cub.win, brsh.x0, brsh.y0, color);
        if (brsh.x0 == brsh.x1 && brsh.y0 == brsh.y1)
            break;
        e2 = err;
        if (e2 > -dx)
        {
            err -= dy;
            brsh.x0 += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            brsh.y0 += sy;
        }
    }
}

void drawRays2D(t_cub cub)
{
    int mx, my, mp, dof;
    float vx, vy, rx, ry, ra, xo, yo, disV, disH, r;
    ra = cub.pa;
    t_brsh  brsh;

    r = 0.0;
    while (r < 60.0)
    {
        ra = cub.pa - cub.ray.angle + r;
        // Vertical
        dof = 0;
        disV = 100000;
        float Tan = tan(ra * (PI / 180.0));
        if (cos(ra * (PI / 180.0)) > 0.001)
        {
            rx = (((int)cub.px >> 6) << 6) + 64;
            ry = (cub.px - rx) * Tan + cub.py;
            xo = 64;
            yo = -xo * Tan;
        }
        else if (cos(ra * (PI / 180.0)) < -0.001)
        {
            rx = (((int)cub.px >> 6) << 6) - 0.0001;
            ry = (cub.px - rx) * Tan + cub.py;
            xo = -64;
            yo = -xo * Tan;
        }
        else
        {
            rx = cub.px;
            ry = cub.py;
            dof = 8;
        }

        while (dof < 8)
        {
            mx = (int)(rx) >> 6;
            my = (int)(ry) >> 6;
            mp = my * MAP_WIDTH + mx;
            if (mp > 0 && mp < MAP_WIDTH * MAP_HEIGHT && cub.map[mp] == 1)
            {
                dof = 8;
                disV = cos(ra * (PI / 180.0)) * (rx - cub.px) - sin(ra * (PI / 180.0)) * (ry - cub.py);
            }
            else
            {
                rx += xo;
                ry += yo;
                dof += 1;
            }
        }
        vx = rx;
        vy = ry;
        

        // Horizontal
        dof = 0;
        disH = 100000;
        Tan = 1.0 / Tan;
        if (sin(ra * (PI / 180.0)) > 0.001)
        {
            ry = (((int)cub.py >> 6) << 6) - 0.0001;
            rx = (cub.py - ry) * Tan + cub.px;
            yo = -64;
            xo = -yo * Tan;
        }
        else if (sin(ra * (PI / 180.0)) < -0.001)
        {
            ry = (((int)cub.py >> 6) << 6) + 64;
            rx = (cub.py - ry) * Tan + cub.px;
            yo = 64;
            xo = -yo * Tan;
        }
        else
        {
            rx = cub.px;
            ry = cub.py;
            dof = 8;
        }

        while (dof < 8)
        {
            mx = (int)(rx) >> 6;
            my = (int)(ry) >> 6;
            mp = my * MAP_WIDTH + mx;
            if (mp > 0 && mp < MAP_WIDTH * MAP_HEIGHT && cub.map[mp] == 1)
            {
                dof = 8;
                disH = cos(ra * (PI / 180.0)) * (rx - cub.px) - sin(ra * (PI / 180.0)) * (ry - cub.py);
            }
            else
            {
                rx += xo;
                ry += yo;
                dof += 1;
            }
        }
        if (disV < disH)
        {
            rx = vx;
            ry = vy;
            disH = disV;
        }

        brsh.x0 = cub.px;
        brsh.y0 = cub.py;
        brsh.x1 = rx;
        brsh.y1 = ry;
        bresenham_line(cub, brsh, 0xFF0000);
        r += 0.1;
    }
}