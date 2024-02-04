/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:01:44 by gfernand          #+#    #+#             */
/*   Updated: 2024/01/29 17:19:13 by gfernand         ###   ########.fr       */
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

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
}	t_mlx;

void	window(t_mlx *mlx);
void	exit_mssg(char *s);

/* PARSE */
void	parse(char *s);

/* PARSE_UTILS */
int	ft_strrncmp(char *s1, char *s2, int n);

#endif
