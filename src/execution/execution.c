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

void	init_img(t_cub cub);
void	start_position(t_cub *cub, t_ray *ray);

void	execution(t_data data)
{
	t_cub	cub;
	t_ray	ray;

	cub.data = data;
	cub.mlx = mlx_init();
	cub.win = mlx_new_window(cub.mlx, W_WIDTH, W_HEIGHT - 90, "cub3D");
	if (!cub.win)
		exit_mssg("Wrong window\n");
	cub.img = malloc (sizeof (t_img));
	if (!cub.img)
		exit_mssg("Malloc error\n");
	cub.img->img = mlx_new_image(cub.mlx, W_WIDTH, W_HEIGHT);
	cub.pa = -30;
	start_position(&cub, &ray);
	cub.map_h = cub.data.map.rows;
	cub.map_w = cub.data.map.cols;
	cub.mouse = 0;
	cub.ray = ray;
	init_img(cub);
	init_textures(&data, &cub);
	map2d(cub, ray);
	mlx_put_image_to_window(cub.mlx, cub.win, cub.img->img, 0, 0);
	window(&cub);
	free(cub.img);
}

void	init_img(t_cub cub)
{
	cub.img->bits = 32;
	cub.img->line = W_WIDTH * 4;
	cub.img->end = 0;
}

void	start_position(t_cub *cub, t_ray *ray)
{	
	cub->px = cub->data.map.player_pos.x * MAP_SCALE + MAP_SCALE / 2;
	cub->py = cub->data.map.player_pos.y * MAP_SCALE + MAP_SCALE / 2;
	if (cub->data.map.player_pos.dir == 'N')
		ray->angle = 270;
	if (cub->data.map.player_pos.dir == 'S')
		ray->angle = 90;
	if (cub->data.map.player_pos.dir == 'E')
		ray->angle = 0;
	if (cub->data.map.player_pos.dir == 'W')
		ray->angle = 180;
}
