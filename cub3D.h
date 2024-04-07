/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <mhernang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:01:44 by gfernand          #+#    #+#             */
/*   Updated: 2024/04/07 12:19:10 by mhernang         ###   ########.fr       */
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
#define MAP_SCALE 64 //map cube size
#define IMG_SCALE 32

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_map
{
	char		**map;
	int			rows;
	int			cols;
	t_player	player_pos;
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
	int		F;
	int		C;
	t_map	map;
}	t_data;

typedef struct s_ray
{
	int		color;
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
	t_img   no_tex;
	t_img   so_tex;
	t_img   we_tex;
	t_img   ea_tex;
	int		px;
	int		py;
	int		pa;
	int		map_h;
	int		map_w;
}	t_cub;

void	window(t_cub *cub);
void	exit_mssg(char *s);
void	error_msg(char *err);

/* PARSE */
void	parse(char *file, t_data *data);

/* PARSE_UTILS */
void    free_map(char ***map);
void    set_player_pos(t_data *data);
int	ft_strrncmp(char *s1, char *s2, int n);
int elements_full(t_data *data);
int	is_zero(char *str);

/* PROCESS */
void	process_line(char *line, t_data *data);

/* PROCESS_MAP */
void    process_map(int fd, char *line, t_data *data);

/* FILL_SPACES*/
char    **fill_spaces(char **original, int rows, int *cols);

/* CHECK_BORDERS*/
void    check_borders(t_map *map);

/* EXECUTION */
void	execution(t_data data);
void	set_pixel(t_img *img, int x, int y, int color);
void	bresenham_line(t_cub cub, t_brsh brsh, int color);

void	map2d(t_cub cub, t_ray ray);
void	throw_rays(t_cub cub, t_ray ray);
void 	box(t_cub cub, int x, int y, int color);
void 	player(t_cub cub, t_ray ray);

void	walls(t_cub cub, t_ray ray);
void	vertical(t_cub cub, t_ray *ray);
void	horizontal(t_cub cub, t_ray *ray);

//gnl
char	*get_next_line(int fd);

#endif
