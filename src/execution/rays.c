#include "../../cub3D.h"

void	vertical(t_cub cub, t_ray *ray);
void	horizontal(t_cub cub, t_ray *ray);

void	draw_rays2d(t_cub cub, t_ray ray)
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
		brsh.x0 = cub.px / 3;
		brsh.y0 = cub.py / 3;
		brsh.x1 = ray.rx / 3;
		brsh.y1 = ray.ry / 3;
		bresenham_line(cub, brsh, 0xFF0000);
		brsh.x0 = w * 8;
  		brsh.y0 = (W_HEIGHT / 2) - ((MAP_SCALE * 320) / ray.d_h / 2);
    	brsh.x1 = brsh.x0;
    	brsh.y1 = brsh.y0 + (MAP_SCALE * 320) / ray.d_h;
		r -= 0.1;
		w += 0.1;
	}
}

void	vertical(t_cub cub, t_ray *ray)
{
	int	mx;
	int	my;

	ray->dof = 0;
	ray->d_v = 100000;
	ray->tan = tan(ray->ra * (PI / 180.0));
	if (cos(ray->ra * (PI / 180.0)) > 0.001)
	{
		ray->rx = (((int)cub.px >> 6) << 6) + 64;
		ray->ry = (cub.px - ray->rx) * ray->tan + cub.py;
		ray->xo = 64;
		ray->yo = -ray->xo * ray->tan;
	}
	else if (cos(ray->ra * (PI / 180.0)) < -0.001)
	{
		ray->rx = (((int)cub.px >> 6) << 6) - 0.0001;
		ray->ry = (cub.px - ray->rx) * ray->tan + cub.py;
		ray->xo = -64;
		ray->yo = -ray->xo * ray->tan;
	}
	else
	{
		ray->rx = cub.px;
		ray->ry = cub.py;
		ray->dof = 8;
	}
	while (ray->dof < 8)
	{
		mx = (int)(ray->rx) >> 6;
		my = (int)(ray->ry) >> 6;
		if (my >= 0 && my < MAP_HEIGHT && mx >= 0 && mx < MAP_WIDTH && cub.data.mp[my][mx] == '1')
		{
			ray->dof = 8;
			ray->d_v = cos(ray->ra * (PI / 180.0)) * (ray->rx - cub.px) - sin(ray->ra * (PI / 180.0)) * (ray->ry - cub.py);
		}
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof += 1;
		}
	}
	ray->vx = ray->rx;
	ray->vy = ray->ry;
}

void	horizontal(t_cub cub, t_ray *ray)
{
	int	mx;
	int	my;

	ray->dof = 0;
	ray->d_h = 100000;
	ray->tan = 1.0 / ray->tan;
	if (sin(ray->ra * (PI / 180.0)) > 0.001)
	{
		ray->ry = (((int)cub.py >> 6) << 6) - 0.0001;
		ray->rx = (cub.py - ray->ry) * ray->tan + cub.px;
		ray->yo = -64;
		ray->xo = -ray->yo * ray->tan;
	}
	else if (sin(ray->ra * (PI / 180.0)) < -0.001)
	{
		ray->ry = (((int)cub.py >> 6) << 6) + 64;
		ray->rx = (cub.py - ray->ry) * ray->tan + cub.px;
		ray->yo = 64;
		ray->xo = -ray->yo * ray->tan;
	}
	else
	{
		ray->rx = cub.px;
		ray->ry = cub.py;
		ray->dof = 8;
	}
	while (ray->dof < 8)
	{
		mx = (int)(ray->rx) >> 6;
		my = (int)(ray->ry) >> 6;
		if (my >= 0 && my < MAP_HEIGHT && mx >= 0 && mx < MAP_WIDTH && cub.data.mp[my][mx] == '1')
		{
			ray->dof = 8;
			ray->d_h = cos(ray->ra * (PI / 180.0)) * (ray->rx - cub.px) - sin(ray->ra * (PI / 180.0)) * (ray->ry - cub.py);
		}
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof += 1;
		}
	}
}
