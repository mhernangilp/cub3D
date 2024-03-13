#include "../../cub3D.h"

void	walls(t_cub cub, t_ray ray)
{
	float	r;
	t_brsh		brsh;
	float	w;

	r = 60.0;
	w = 0.0;
	while (r > 0.0)
	{
		ray.ra = cub.pa - cub.ray.angle + r;
		vertical(cub, &ray);
		horizontal(cub, &ray);
		if (ray.d_v < ray.d_h)
		{
			ray.rx = ray.vx;
			ray.ry = ray.vy;
			ray.d_h = ray.d_v;
		}
		brsh.x0 = w * 8;
  		brsh.y0 = (W_HEIGHT / 2) - ((MAP_SCALE * 320) / ray.d_h / 2);
    	brsh.x1 = brsh.x0;
    	brsh.y1 = brsh.y0 + (MAP_SCALE * 320) / ray.d_h;
		bresenham_line(cub, brsh, 0x00FF00);
		r -= 0.1;
		w += 0.1;
	}
}