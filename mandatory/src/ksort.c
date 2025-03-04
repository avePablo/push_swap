#include "push_swap.h"

void push_to_b_in_chunks(t_stack *stack_a, t_stack *stack_b, int chunk_size)
{
    int i = 0;
    int size = stack_length(stack_a);

    while (!is_empty(stack_a))
    {
        if (stack_a->top->index <= i)
        {
            pb(stack_a, stack_b);
            if (stack_length(stack_b) > 1)
                rb(stack_b);
            i++;
        }
        else if (stack_a->top->index <= i + chunk_size)
        {
            pb(stack_a, stack_b);
            i++;
        }
        else
            ra(stack_a);
    }
}

int find_moves_to_top(t_stack *stack, int target_index)
{
    t_node *current = stack->top;
    int moves = 0;

    while (current && current->index != target_index)
    {
        current = current->next;
        moves++;
    }
    return moves;
}

void move_max_to_top(t_stack *stack_a, t_stack *stack_b, int max_index)
{
    int moves_rb = find_moves_to_top(stack_b, max_index);
    int moves_rrb = stack_length(stack_b) - moves_rb;

    if (moves_rb <= moves_rrb)
    {
        while (stack_b->top->index != max_index)
            rb(stack_b);
    }
    else
    {
        while (stack_b->top->index != max_index)
            rrb(stack_b);
    }
    pa(stack_a, stack_b);
}

void k_sort(t_stack *stack_a)
{
    if (!stack_a || is_empty(stack_a))
        return;
    
    int size = stack_length(stack_a);
    t_stack stack_b;
    init_stack(&stack_b);
    
    int chunk_size = (int)ft_sqrt(size) * 7 / 5;
    push_to_b_in_chunks(stack_a, &stack_b, chunk_size);

    while (size-- > 0)
        move_max_to_top(stack_a, &stack_b, size);
}
