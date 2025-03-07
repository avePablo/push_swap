#include "push_swap.h"

void sa(t_stack *stack_a)
{
    t_node *first;
    t_node *second;

    if (stack_a->top && stack_a->top->next)
    {
        first = stack_a->top;
        second = first->next;
        first->next = second->next;
        second->next = first;
        stack_a->top = second;
    }
    ft_printf("sa\n");
}

void sb(t_stack *stack_b)
{
    t_node *first;
    t_node *second;

    if (stack_b->top && stack_b->top->next)
    {
        first = stack_b->top;
        second = first->next;
        first->next = second->next;
        second->next = first;
        stack_b->top = second;
    }
    ft_printf("sb\n");
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
    sa(stack_a);
    sb(stack_b);
    ft_printf("ss\n");
}

void pa(t_stack *stack_a, t_stack *stack_b)
{
    t_node *temp;

    if (!is_empty(stack_b))
    {
        temp = stack_b->top;
        stack_b->top = temp->next;
        temp->next = stack_a->top;
        stack_a->top = temp;
    }
    ft_printf("pa\n");
}

void pb(t_stack *stack_a, t_stack *stack_b)
{
    t_node *temp;

    if (!is_empty(stack_a))
    {
        temp = stack_a->top;
        stack_a->top = temp->next;
        temp->next = stack_b->top;
        stack_b->top = temp;
    }
    ft_printf("pb\n");
}
