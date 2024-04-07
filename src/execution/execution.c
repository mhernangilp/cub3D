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
void    init_textures(t_data *data, t_cub *cub);
t_img	new_texture(t_cub *cub, char *path, int width, int height);

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
	cub.img->img = mlx_new_image(cub.mlx, W_WIDTH, W_HEIGHT);
	cub.pa = -30;
	start_position(&cub, &ray);
	cub.map_h = 12;
	cub.map_w = 12;
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
	int		x;
	int		y;
	char	**map;

	map = cub->data.mp;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'E' || map[y][x] == 'W')
			{
				cub->px = x * MAP_SCALE + MAP_SCALE / 2;
				cub->py = y * MAP_SCALE + MAP_SCALE / 2;
				if (map[y][x] == 'N')
					ray->angle = 270;
				if (map[y][x] == 'S')
					ray->angle = 90;
				if (map[y][x] == 'E')
					ray->angle = 0;
				if (map[y][x] == 'W')
					ray->angle = 180;
				map[y][x] = '0';
			}
		}
	}
}

void    init_textures(t_data *data, t_cub *cub)
{
	/*cub->no_tex = new_texture(cub, data->NO, 32, 32);
	cub->so_tex = new_texture(cub, data->SO, 32, 32);
	cub->we_tex = new_texture(cub, data->WE, 32, 32);
	cub->ea_tex = new_texture(cub, data->EA, 32, 32);*/
	cub->no_tex = new_texture(cub, "textures/n.xpm", 32, 32);
	cub->so_tex = new_texture(cub, "textures/n.xpm", 32, 32);
	cub->we_tex = new_texture(cub, "textures/n.xpm", 32, 32);
	cub->ea_tex = new_texture(cub, "textures/n.xpm", 32, 32);
	(void) data;
}

t_img	new_texture(t_cub *cub, char *path, int width, int height)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(cub->mlx, path, &width, &height);
	if (img.img == NULL)
	{
		printf("Error loading texture '%s'\n", path);
		exit (1);
	}
	img.addr = mlx_get_data_addr(img.img, &img.bits,
			&img.line, &img.end);
	return (img);
}