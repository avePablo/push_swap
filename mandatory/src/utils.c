#include "push_swap.h"

int	ft_isvalid(char *args[])
{
	int i;
	int j;

	i = 0;
	j = 0;

	while(args[i])
	{
		j = 0;
		while(args[i][j])
			{
				if (args[i][j] == '-')
					j++;
				if (!(args[i][j] >= '0' && args[i][j] <= '9'))
					return (0);
				j++;
			}
	i++;
	}
	return (1);
}