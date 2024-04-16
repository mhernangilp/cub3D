/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <mhernang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:13:32 by gfernand          #+#    #+#             */
/*   Updated: 2024/04/16 19:28:24 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	main(int arg, char **argv)
{
	t_data	data;

	if (arg != 2)
		exit_mssg("Error\n2 arguments are spected\n");
	parse(argv[1], &data);
	execution(data);
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
