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

# define W_WIDTH 1200
# define W_HEIGHT 675
# define PI 3.1415926535

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
	t_RGB	F;
	t_RGB	C;
	t_map	map;
}	t_data;

typedef struct s_ray
{
	int		angle;
	float	radians;
}	t_ray;

typedef struct s_cub
{
	void	*mlx;
	void	*win;
	void	*img;
	int		height;
	int		width;

	t_ray	ray;
	
	int		angle;
	int		p_x;
	int		p_y;
	int     n_x;
	int     n_y;
	int     p_a;
	int     p_dx;
	int     p_dy;
}	t_cub;

void	window(t_cub *cub);
void	exit_mssg(char *s);

/* PARSE */
void	parse(char *file, t_data *data);

/* PARSE_UTILS */
int	ft_strrncmp(char *s1, char *s2, int n);

/* EXECUTION */
void	execution();

void	drawMap2D(t_cub cub, t_ray ray);
void 	box(t_cub cub, int x, int y, int color);
void 	draw_player(t_cub cub, t_ray ray);


#endif
