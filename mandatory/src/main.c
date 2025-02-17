#include "push_swap.h"

int checkvalues(char *args[])
{
    if(ft_isvalid(args) == 0)
        return(1);
    return(0);
}

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
    if(checkvalues(args) == 1)
    {
        ft_printf("%s\n","error loool vaya tonto lmao");
        return(1);
    }
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
