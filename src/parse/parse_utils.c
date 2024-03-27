#include "../../cub3D.h"

void    free_map(char ***map)
{
    int i;

    i = -1;
    while ((*map)[++i])
        free((*map)[i]);
    free(*map);
}

void    set_player_pos(t_data *data)
{
    int i;
    int j;

    i = -1;
    while (data->map.map[++i])
    {
        j = -1;
        while (data->map.map[i][++j])
            if (data->map.map[i][j] == 'N' || data->map.map[i][j] == 'S' || data->map.map[i][j] == 'E' || data->map.map[i][j] == 'W')
            {
                data->map.player_pos.y = i;
                data->map.player_pos.x = j;
                return ;
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

int is_map(char *line)
{
    int empty;

    empty = 1;
    while (*line && *line != '\n')
    {
        if (*line == '1')
            empty = 0;
        if (*line != ' ' && *line != '1')
            return (0);
        line++;
    }
    if (empty)
        return (0);
    return (1);
}