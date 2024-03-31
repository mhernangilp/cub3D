/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:13:32 by gfernand          #+#    #+#             */
/*   Updated: 2024/02/08 13:53:38 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/*void	leaks(void)
{
	system("leaks cub3D");
}*/

void    ft_map(t_data *data);

int	main(int arg, char **argv)
{
	t_data	data;

	//atexit(leaks);
	if (arg < 2)
		exit_mssg("Error: 2 arguments are spected\n");
	parse(argv[1], &data);
	ft_map(&data);
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


void    ft_map(t_data *data)
{
	data->mp = malloc((12 + 1) * sizeof(char *));
	

    data->mp[0] = ft_strdup("111111111111\0");
    data->mp[1] = ft_strdup("101000000001\0");
    data->mp[2] = ft_strdup("101000000001\0");
    data->mp[3] = ft_strdup("10000N100001\0");
    data->mp[4] = ft_strdup("100000000001\0");
    data->mp[5] = ft_strdup("100000000001\0");
	data->mp[6] = ft_strdup("100000010001\0");
    data->mp[7] = ft_strdup("101000000001\0");
    data->mp[8] = ft_strdup("101000000001\0");
    data->mp[9] = ft_strdup("100010000001\0");
    data->mp[10] = ft_strdup("100000000001\0");
    data->mp[11] = ft_strdup("111111111111\0");
    data->mp[12] = NULL;
}