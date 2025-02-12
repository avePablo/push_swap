#include "push_swap.h"

int	ft_isvalid(char c)
{
	if (!((c >= '0' && c <= '9')||(c == '-')))
		return (0);
	return (1);
}
