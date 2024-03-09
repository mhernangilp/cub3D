/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:01:44 by gfernand          #+#    #+#             */
/*   Updated: 2024/02/08 17:00:58 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"
# include "minilibx/mlx.h"

# define MAX 2147483647
# define MIN -2147483648
# define W_WIDTH 1200
# define W_HEIGHT 675
# define PI 3.1415926535

#define SQR_SIZE 10
#define MAP_WIDTH  8 //map width
#define MAP_HEIGHT  6 //map height
#define MAP_SCALE 64 //map cube size

typedef struct s_map
{
	char	**map;
	int		rows;
	int		cols;
}	t_map;

typedef struct RGB
{
	int	R;
	int	G;
	int	B;
}	t_RGB;

typedef struct data
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	**mp;
	t_RGB	F;
	t_RGB	C;
	t_map	map;
}	t_data;

typedef struct s_ray
{
	int		angle;
	float	radians;
	int		look;
	int		dof;
	float	vx;
	float	vy;
	float	rx;
	float	ry;
	float	ra;
	float	xo;
	float	yo;
	float	d_v;
	float	d_h;
	float	tan;
}	t_ray;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits;
	int		line;
	int		end;
}	t_img;

typedef struct s_brsh
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
}	t_brsh;


typedef struct s_cub
{
	void	*mlx;
	void	*win;
	t_img	*img;
	int		height;
	int		width;
	t_ray	ray;
	t_data	data;
	int		px;
	int		py;
	int		pa;
}	t_cub;

void	window(t_cub *cub);
void	exit_mssg(char *s);

/* PARSE */
void	parse(char *file, t_data *data);

/* PARSE_UTILS */
int	ft_strrncmp(char *s1, char *s2, int n);

/* EXECUTION */
void	execution(t_data data);
void	set_pixel(t_cub *cub, int x, int y, int color);
void	bresenham_line(t_cub cub, t_brsh brsh, int color);

void	draw_map2d(t_cub cub, t_ray ray);
void	draw_rays2d(t_cub cub, t_ray ray);
void 	box(t_cub cub, int x, int y, int color);
void 	draw_player(t_cub cub, t_ray ray);


#endif
