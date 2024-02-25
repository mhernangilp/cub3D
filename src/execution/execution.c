#include "../../cub3D.h"

void	execution(void)
{
	t_cub	cub;

	cub.mlx = mlx_init();
	cub.win = mlx_new_window(cub.mlx, WIDTH, HEIGHT, "cub3D");
	if (!cub.win)
		exit_mssg("Wrong window\n");
	//cub.img = new_image(&cub, WIDTH, HEIGHT);
	window(&cub);
}
