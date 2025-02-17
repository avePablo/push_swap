#include "push_swap.h"

int main (int argc, char *argv[])
{
char **args;
int i;

i = 1;
while (i < argc)
{
    args = ft_split(argv[i], ' ');
    if(args == NULL)
        return(1);
    i++;
}

int j;
j = 0;
while (args[j] != NULL)
{
    ft_printf("%s\n", args[j]);
    j++;
}
return (0);
}
