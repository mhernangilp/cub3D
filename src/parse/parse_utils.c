/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <mhernang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:49:59 by mhernang          #+#    #+#             */
/*   Updated: 2024/04/16 17:07:54 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	free_map(char ***map)
{
	int	i;

	i = -1;
	while ((*map)[++i])
		free((*map)[i]);
	free(*map);
}

void	set_player_pos(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map.map[++i])
	{
		j = -1;
		while (data->map.map[i][++j])
		{
			if (data->map.map[i][j] == 'N' || data->map.map[i][j] == 'S'
				|| data->map.map[i][j] == 'E' || data->map.map[i][j] == 'W')
			{
				data->map.player_pos.y = i;
				data->map.player_pos.x = j;
				data->map.player_pos.dir = data->map.map[i][j];
				return ;
			}
		}
	}
}

int	ft_strrncmp(char *s1, char *s2, int n)
{
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	j = ft_strlen(s2) - 1;
	while (i != -1 && j != -1 && n-- > 0)
	{
		if (s1[i--] != s2[j--])
			return (1);
	}
	if (n > 0)
		return (1);
	return (0);
}

int	elements_full(t_data *data)
{
	return (data -> no && data -> so && data -> we
		&& data -> ea && data -> f != -1 && data -> c != -1);
}

int	is_zero(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] == '0')
		i++;
	if (str[i] != '\0' && str[i] != '\n')
		return (0);
	return (1);
}
