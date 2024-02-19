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
	//cub.img = mlx_new_image(cub.mlx, W_WIDTH, W_HEIGHT);
	cub.p_x = 100;
	cub.p_y = 100;
	drawMap2D(cub);
	//mlx_put_image_to_window(cub.mlx, cub.win, cub.img, 0, 0);

	window(&cub);
}

/*
void    ray_casting(void)
{
	t_ray	ray;
	
    para(int x = posx; x < weigth; x++)
    {
      //calcular la posición y dirección del rayo
       double cameraX = 2 * x / double(w) - 1; //coordenada x en el espacio de la cámara
       double rayDirX = dirX + planeX * cameraX;
      double rayDirY = dirY + planoY * cámaraX;
	}

	delta_x = sqrt(1 + (rdir_y * rdir_y) / (rdir_x * rdir_x));
	delta_y = sqrt(1 + (rdir_x * rdir_x) / (rdir_y * rdir_y));
		Es lo mismo que:
	deltaDistX = abs(1 / rayDirX);
	deltaDistY = abs(1 / rayDirY);

	if (rdir_x < 0)
	{
    	stepX = -1;
        sideDistX = (posX - mapX) * delta_x;
    }
    else
    {
        stepX = 1;
        sideDistX = (mapX + 1.0 - posx) * delta_x;
    }
    if (rdir_y < 0)
    {
        stepY = -1;
        sideDistY = (posY - mapY) * delta_y;
    }
    else
    {
        stepY = 1;
        sideDistY = (mapY + 1.0 - posY) * delta_y;
    }

}
*/
