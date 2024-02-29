/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:54:32 by gfernand          #+#    #+#             */
/*   Updated: 2024/02/08 20:36:28 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	execution(t_data data)
{
	t_cub	cub;
	t_ray	ray;

	cub.data = data;
	cub.mlx = mlx_init();
	cub.win = mlx_new_window(cub.mlx, W_WIDTH, W_HEIGHT, "cub3D");
	if (!cub.win)
		exit_mssg("Wrong window\n");
	//cub.img = mlx_new_image(cub.mlx, W_WIDTH, W_HEIGHT);
	cub.px = 200;
	cub.py = 250;
	ray.angle = 0;
	cub.pa = -30;
	cub.ray = ray;
	draw_map2d(cub, ray);
	//mlx_put_image_to_window(cub.mlx, cub.win, cub.img, 0, 0);
	window(&cub);
}
