#include "../../cub3D.h"

void	init_textures(t_data *data, t_cub *cub)
{
	cub->no_tex = new_texture(cub, data->NO, 32, 32);
	cub->so_tex = new_texture(cub, data->SO, 32, 32);
	cub->we_tex = new_texture(cub, data->WE, 32, 32);
	cub->ea_tex = new_texture(cub, data->EA, 32, 32);
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

t_img	side_texture(t_cub cub, t_ray *ray, float w, int i)
{
	int		ag;
	t_img	texture;

	ag = ray->angle + cub.pa + w;
	if (ag > 360)
		ag -= 360;
	if (ag < -360)
		ag += 360;
	if (i == 1)
	{
		if ((ag > 180 && ag < 360) || (ag < 0 && ag > -180))
			texture = cub.no_tex;
		else
			texture = cub.so_tex;
	}
	else
	{
		if ((ag > -90 && ag < 90) || (ag < -270 && ag > -361)
			|| (ag > 270 && ag < 361))
			texture = cub.ea_tex;
		else
			texture = cub.we_tex;
	}
	return (texture);
}

int	get_color_from_image(t_img *img, int x, int y)
{
	char	*dst;
	int		length;
	int		bpp;

	if (x < 0 || y < 0 || x >= 32 || y >= 32)
		return (0);
	length = img->line;
	bpp = img->bits;
	dst = img->addr + (y * length + x * (bpp / 8));
	return (*(unsigned int *)dst);
}
