#include "push_swap.h"

int is_sorted(t_stack *stack)
{
    t_node *current = stack->top;

    while (current && current->next)
    {
        if (current->value > current->next->value)
            return 0;  // No está ordenado
        current = current->next;
    }
    return 1;  // Está ordenado
}

void sort_three_node(t_stack *stack_a)
{
    t_node *biggest = stack_a->top;
    t_node *second = biggest->next;
    t_node *third = second->next;
    
    if (biggest->value > second->value && biggest->value > third->value)
        ra(stack_a);
    else if (second->value > biggest->value && second->value > third->value)
        rra(stack_a);
    
    if (stack_a->top->value > stack_a->top->next->value)
        sa(stack_a);
}

void sort_four_node(t_stack *stack_a, t_stack *stack_b)
{
    while (stack_length(stack_a) > 3)
    {
        if (stack_a->top->index != 0)
        {
            if (find_moves_to_top(stack_a, 0) <= stack_length(stack_a) / 2)
                ra(stack_a);
            else
                rra(stack_a);
        }
        if (stack_a->top->index == 0)
            pb(stack_a, stack_b);
    }
    if (!is_sorted(stack_a))
        sort_three_node(stack_a);
    pa(stack_a, stack_b);
}

void sort_five_node(t_stack *stack_a, t_stack *stack_b)
{
    while (stack_length(stack_a) > 3)
    {
        if (stack_a->top->index != 0 && stack_a->top->index != 1)
        {
            if ((find_moves_to_top(stack_a, 0) <= (stack_length(stack_a) / 2 ))||
                (find_moves_to_top(stack_a, 1) <= (stack_length(stack_a) / 2)))
                ra(stack_a);
            else
                rra(stack_a);
        }
        if (stack_a->top->index == 0 || stack_a->top->index == 1)
            pb(stack_a, stack_b);
    }
    if (!is_sorted(stack_a))
        sort_three_node(stack_a);
    if (is_sorted(stack_b))
        sb(stack_b);
    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
}