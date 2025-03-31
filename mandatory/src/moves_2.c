/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <pabalvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:29:39 by pabalvar          #+#    #+#             */
/*   Updated: 2025/03/31 19:00:37 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a)
{
	t_node	*first;
	t_node	*last;

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
	ft_printf("ra\n");
}

void	rb(t_stack *stack_b)
{
	t_node	*first;
	t_node	*last;

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
	ft_printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_printf("rr\n");
}

void	rra(t_stack *stack_a)
{
	t_node	*last;
	t_node	*second_last;

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
	ft_printf("rra\n");
}

void	rrb(t_stack *stack_b)
{
	t_node	*last;
	t_node	*second_last;

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
	ft_printf("rrb\n");
}
