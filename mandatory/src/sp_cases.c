/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_cases.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <pabalvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:59:15 by pabalvar          #+#    #+#             */
/*   Updated: 2025/03/21 17:00:54 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_three_node(t_stack *stack_a)
{
	t_node	*biggest;
	t_node	*second;
	t_node	*third;

	biggest = stack_a->top;
	second = biggest->next;
	third = second->next;
	if (biggest->value > second->value && biggest->value > third->value)
		ra(stack_a);
	else if (second->value > biggest->value && second->value > third->value)
		rra(stack_a);
	if (stack_a->top->value > stack_a->top->next->value)
		sa(stack_a);
}

void	sort_four_node(t_stack *stack_a, t_stack *stack_b)
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

void	sort_five_node(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_length(stack_a) > 3)
	{
		if (stack_a->top->index != 0 && stack_a->top->index != 1)
		{
			if ((find_moves_to_top(stack_a, 0) <= (stack_length(stack_a) / 2))
				|| (find_moves_to_top(stack_a, 1) <= (stack_length(stack_a)
						/ 2)))
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
