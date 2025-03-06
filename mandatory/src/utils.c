#include "push_swap.h"

int	ft_sqrt(int num)
{
	int	i;

	if (num < 4)
		return (1);
	i = 2;
	while (i * i < num)
	{
		i++;
	}
	if (i * i > num)
	{
		if ((i * i - num) < ((i - 1) * (i - 1) + (-num)))
			return (i);
	}
	return (i - 1);
}

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

// Reverse rotate simultáneo (rra y rrb)
void rrr(t_stack *stack_a, t_stack *stack_b)
{
    rra(stack_a);
    rrb(stack_b);
    ft_printf("rrr\n");
}

void	free_matrix(char **num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		free(num[i]);
		i++;
	}
	free(num);
}