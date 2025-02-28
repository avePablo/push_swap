#include "push_swap.h"

// Rotate para la pila A
void ra(t_stack *stack_a)
{
    t_node *first;
    t_node *last;

    if (stack_a->top && stack_a->top->next)
    {
        first = stack_a->top;
        stack_a->top = first->next;
        last = stack_a->top;
        while (last->next)
            last = last->next;
        first->next = NULL;
        last->next = first;
    }
}

// Rotate para la pila B
void rb(t_stack *stack_b)
{
    t_node *first;
    t_node *last;

    if (stack_b->top && stack_b->top->next)
    {
        first = stack_b->top;
        stack_b->top = first->next;
        last = stack_b->top;
        while (last->next)
            last = last->next;
        first->next = NULL;
        last->next = first;
    }
}

// Rotate simultáneo (ra y rb)
void rr(t_stack *stack_a, t_stack *stack_b)
{
    ra(stack_a);
    rb(stack_b);
}

// Reverse rotate para la pila A
void rra(t_stack *stack_a)
{
    t_node *last;
    t_node *second_last;

    if (stack_a->top && stack_a->top->next)
    {
        second_last = stack_a->top;
        while (second_last->next->next)
            second_last = second_last->next;
        last = second_last->next;
        second_last->next = NULL;
        last->next = stack_a->top;
        stack_a->top = last;
    }
}

// Reverse rotate para la pila B
void rrb(t_stack *stack_b)
{
    t_node *last;
    t_node *second_last;

    if (stack_b->top && stack_b->top->next)
    {
        second_last = stack_b->top;
        while (second_last->next->next)
            second_last = second_last->next;
        last = second_last->next;
        second_last->next = NULL;
        last->next = stack_b->top;
        stack_b->top = last;
    }
}
