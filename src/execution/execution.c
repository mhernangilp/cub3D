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

void	execution(void)
{
	t_cub	cub;

	cub.mlx = mlx_init();
	cub.win = mlx_new_window(cub.mlx, W_WIDTH, W_HEIGHT, "cub3D");
	if (!cub.win)
		exit_mssg("Wrong window\n");
	cub.img = mlx_xpm_file_to_image(&cub, "../../img.xpm", &cub.width, &cub.height);
	if (!cub.img)
	{
		printf("Error loading img\n");
		exit (0);
	}
	mlx_put_image_to_window(cub.mlx, cub.win, cub.img, 0, 0);
	//position of player
	//keys to move player
	window(&cub);
}
