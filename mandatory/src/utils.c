#include "push_swap.h"

int	ft_isvalid(char a, char b)
{
	if (!((a >= '0' && a <= '9')||(a == '-')))
		return (0);
	if (!((a >= '0' && a <= '9')&&(b == '-')))
		return (0);
	return (1);
}