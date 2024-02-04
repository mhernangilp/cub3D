#include "../../cub3D.h"

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