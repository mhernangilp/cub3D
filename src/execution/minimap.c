#include "../../cub3D.h"

#define MAP_WIDTH  8      //map width
#define MAP_HEIGHT  8      //map height
#define MAP_SCALE 64      //map cube size

void b_box(t_cub cub, int x, int y);

void drawMap2D(t_cub cub)
{
	int map[] = {
		1,1,1,1,1,1,1,1,
		1,0,1,0,0,0,0,1,
		1,0,1,0,0,0,0,1,
		1,0,1,0,0,0,0,1,
		1,0,0,0,0,0,0,1,
		1,0,0,0,0,1,0,1,
		1,0,0,0,0,0,0,1,
		1,1,1,1,1,1,1,1
	};

	int	x;
	int y;

	for (y = 0; y < MAP_HEIGHT; y++) {
		for (x = 0; x < MAP_WIDTH; x++) {
			if (map[y * MAP_WIDTH + x] == 1)
				box(cub, x, y);
			else
				b_box(cub, x, y);
		}
	}
	draw_player(cub);
}

void box(t_cub cub, int x, int y)
{
	int s;
	int	u;

	s = 0;
	while (++s < 60)
	{
		mlx_pixel_put(cub.mlx, cub.win, x * MAP_SCALE + s, y * MAP_SCALE, 0xFFFFFF);
		u = 0;
		while (++u < 60)
			mlx_pixel_put(cub.mlx, cub.win, x * MAP_SCALE + s, y * MAP_SCALE + u, 0xFFFFFF);
	}
}

void draw_player(t_cub cub)
{
	int s;
	int	u;

	s = 0;
	while (++s < 20)
	{
		mlx_pixel_put(cub.mlx, cub.win, cub.p_x + s, cub.p_y, 0x00FF00);
		u = 0;
		while (++u < 20)
			mlx_pixel_put(cub.mlx, cub.win, cub.p_x + s, cub.p_y + u, 0x00FF00);
	}
}
void b_box(t_cub cub, int x, int y)
{
	int s;
	int	u;

	s = 0;
	while (++s < 60)
	{
		mlx_pixel_put(cub.mlx, cub.win, x * MAP_SCALE + s, y * MAP_SCALE, 0x808080);
		u = 0;
		while (++u < 60)
			mlx_pixel_put(cub.mlx, cub.win, x * MAP_SCALE + s, y * MAP_SCALE + u, 0x808080);
	}
}