#include "push_swap.h"

void print_stack(t_stack *stack)
{
    t_node *current = stack->top;

    while (current)
    {
        ft_printf("%d\n", current->value);
        current = current->next;
    }
}

void print_index(t_stack *stack)
{
    t_node *current = stack->top;

    while (current)
    {
        ft_printf("%d\n", current->index);
        current = current->next;
    }
}

int node_repeat(t_stack *stack)
{
     t_node *current = stack->top;

    while (current && current->next)
    {
        if (current->value == current->next->value)
            {
            ft_printf("repes\n");
            exit(1);
            }
        current = current->next;
    }
    return 0; 
}

int get_nums(int argc, char *argv[], t_stack *stack_a)
{
    char **args;
    int i, j;
    long long int num;

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
                ft_printf("%s\n", "caracter no vale");
                exit(1);
            }
            num = ft_atoi(args[j]);
            push(stack_a, num);
            j++;
        }
        i++;
    }
    return (i - 1);
}

int main(int argc, char *argv[])
{
    t_stack *stack_a = malloc(sizeof(t_stack));
    t_stack *stack_b = malloc(sizeof(t_stack));

    if (!stack_a || !stack_b)
        return (1);

    init_stack(stack_a);
    init_stack(stack_b);

    if (argc > 1)
        get_nums(argc, argv, stack_a); 
       
    if (!is_empty(stack_a)) 
        assign_indices(stack_a);
    node_repeat(stack_a);
    print_index(stack_a);
    k_sort(stack_a);
    
    print_stack(stack_a);

    free(stack_a);
    free(stack_b);

    return (0);
}