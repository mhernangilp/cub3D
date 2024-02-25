/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <mhernang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:13:32 by gfernand          #+#    #+#             */
/*   Updated: 2024/02/25 18:41:53 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	data_test(t_data *data);

void	leaks(void)
{
	system("leaks cub3D");
}

int	main(int arg, char **argv)
{
	t_data	data;

	atexit(leaks);
	if (arg < 2)
		exit_mssg("Error\n2 arguments are spected\n");
	parse(argv[1], &data);
	//data_test(&data);
	execution();
	(void)argv[0];
	return (0);
}

void	exit_mssg(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		write(2, (s + i), 1);
	exit(1);
}

void	error_msg(char *err)
{
	perror(err);
	exit (1);
}

static void	data_test(t_data *data)
{
	data->NO = ft_strdup("./textures/textureNO");
	data->SO = ft_strdup("./textures/textureSO");
	data->WE = ft_strdup("./textures/textureWE");
	data->EA = ft_strdup("./textures/textureEA");
	data->F.R = 220;
	data->F.G = 100;
	data->F.B = 0;
	data->C.R = 225;
	data->C.G = 30;
	data->C.B = 0;
	data->map.map = malloc(sizeof(char *) * 5);
	data->map.map[0] = ft_strdup("111111");
	data->map.map[1] = ft_strdup("100101");
	data->map.map[2] = ft_strdup("101001");
	data->map.map[3] = ft_strdup("1100N1");
	data->map.map[4] = ft_strdup("111111");
	data->map.rows = 5;
	data->map.cols = 6;
}