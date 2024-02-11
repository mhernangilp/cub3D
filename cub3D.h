/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <mhernang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:01:44 by gfernand          #+#    #+#             */
/*   Updated: 2024/02/11 17:24:29 by mhernang         ###   ########.fr       */
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

# define WIDTH 1200
# define HEIGHT 675

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

typedef struct s_cub
{
	void	*mlx;
	void	*win;
	void	*img;
}	t_cub;

void	window(t_cub *cub);
void	exit_mssg(char *s);
void	error_msg(char *err);

/* PARSE */
void	parse(char *file, t_data *data);

/* PARSE_UTILS */
int	ft_strrncmp(char *s1, char *s2, int n);

/* PROCESS*/
void	process_line(char *line, t_data *data);

/* EXECUTION */
void	execution();

//gnl
char	*get_next_line(int fd);

#endif
