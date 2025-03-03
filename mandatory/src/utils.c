#include "push_swap.h"

double sqrt(double nbr) {

    double estimate = nbr / 2.0;  
    
    while ((estimate * estimate) - nbr > 0 || (nbr - (estimate * estimate)) > 0) {
        estimate = (estimate + nbr / estimate) / 2.0;
    }
    
    return estimate;
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