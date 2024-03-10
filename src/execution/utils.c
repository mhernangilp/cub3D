#include "../../cub3D.h"

void	put_pixel(t_img *img, int x, int y, int color);
int		brsh_variables(t_brsh *brsh);

void	set_pixel(t_img *img, int x, int y, int color)
{
	img->addr = mlx_get_data_addr(img->img, &img->bits,
			&img->line, &img->end);
	if (x > 0 && x < W_WIDTH && y > 0 && y < W_HEIGHT - 90)
	{
		if (x < MAX && x > MIN && y < MAX && y > MIN)
			put_pixel(img, x, y, color);
	}
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bits - 8;
	pixel = img->addr + (y * img->line + x * (img->bits / 8));
	while (i >= 0)
	{
		if (img->end != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bits - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	bresenham_line(t_cub cub, t_brsh brsh, int color)
{
	int	err;
	int	e2;

	err = brsh_variables(&brsh);
	while (1)
	{
		set_pixel(cub.img, brsh.x0, brsh.y0, color);
		if (brsh.x0 == brsh.x1 && brsh.y0 == brsh.y1)
			break ;
		e2 = err;
		if (e2 > -brsh.dx)
		{
			err -= brsh.dy;
			brsh.x0 += brsh.sx;
		}
		if (e2 < brsh.dy)
		{
			err += brsh.dx;
			brsh.y0 += brsh.sy;
		}
	}
}

int	brsh_variables(t_brsh *brsh)
{
	int	err;

	brsh->dx = abs(brsh->x1 - brsh->x0);
	brsh->dy = abs(brsh->y1 - brsh->y0);
	if (brsh->x0 < brsh->x1)
		brsh->sx = 1;
	else
		brsh->sx = -1;
	if (brsh->y0 < brsh->y1)
		brsh->sy = 1;
	else
		brsh->sy = -1;
	if (brsh->dx > brsh->dy)
		err = brsh->dx / 2;
	else
		err = -brsh->dy / 2;
	return (err);
}
