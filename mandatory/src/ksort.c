/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfuto <kfuto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:32:38 by pabalvar          #+#    #+#             */
/*   Updated: 2025/03/31 18:31:38 by kfuto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b_in_chunks(t_stack *stack_a, t_stack *stack_b, int chunk_size)
{
	int	i;

	i = 0;
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

int	find_moves_to_top(t_stack *stack, int target_index)
{
	t_node	*current;
	int		moves;

	current = stack->top;
	moves = 0;
	while (current && current->index != target_index)
	{
		current = current->next;
		moves++;
	}
	return (moves);
}

void	move_max_to_top(t_stack *stack_a, t_stack *stack_b, int max_index)
{
	int	moves_rb;
	int	moves_rrb;

	moves_rb = find_moves_to_top(stack_b, max_index);
	moves_rrb = stack_length(stack_b) - moves_rb;
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

void	reverse_stack(t_stack *stack_a)
{
	t_node	*prev;
	t_node	*current;
	t_node	*next;

	prev = NULL;
	current = stack_a->top;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	stack_a->top = prev;
}

void	k_sort(t_stack *stack_a,t_stack *stack_b)
{
	int		size;
	int		chunk_size;

	if (!stack_a || is_empty(stack_a))
		return ;
	size = stack_length(stack_a);
	chunk_size = (int)ft_sqrt(size) * 7 / 5;
	push_to_b_in_chunks(stack_a, stack_b, chunk_size);
	while (size > 0)
	{
		size--;
		move_max_to_top(stack_a, stack_b, size);
	}
}