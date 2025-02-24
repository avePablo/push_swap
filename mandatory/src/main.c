#include "push_swap.h"
#include <stdlib.h>



void print_stack(t_stack *stack)
{
    t_node *current = stack->top;

    while (current) // Recorrer toda la pila
    {
        ft_printf("%d\n", current->value);
        current = current->next;
    }
}



int get_nums(int argc, char *argv[], t_stack *stack_a)
{
    char **args;
    int i, j;

    i = 1;
    while (i < argc)
    {
        args = ft_split(argv[i], ' ');
        if (args == NULL)
            exit(1);
        j = 0;
        while (args[j] != NULL)
        {
            if (ft_isvalid(args) == 0)
            {
                ft_printf("%s\n", "error loool vaya tonto lmao");
                exit(1);
            }
            push(stack_a, ft_atoi(args[j]));
            j++;
        }
        i++;
    }
    ft_printf ("pila xd:\n");
    print_stack(stack_a);
    return (i);
}

int main(int argc, char *argv[])
{
    t_stack *stack_a = malloc(sizeof(t_stack));
    t_stack *stack_b = malloc(sizeof(t_stack));

    if (!stack_a || !stack_b)
        exit(1);

    init_stack(stack_a);
    init_stack(stack_b);
    
    quick(stack_a, 0, get_nums(argc, argv, stack_a)-1);
    ft_printf("sorted:");

    print_stack(stack_a); // Imprimir dirección de memoria correctamente

    free(stack_a);
    free(stack_b);

    return 0;
}
