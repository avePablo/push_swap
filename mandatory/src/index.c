/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <pabalvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:32:55 by pabalvar          #+#    #+#             */
/*   Updated: 2025/03/21 16:32:57 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	store_nodes(t_stack *stack_a, t_node **nodes, int size)
{
	t_node	*current;
	int		i;

	current = stack_a->top;
	i = 0;
	while (current && i < size)
	{
		nodes[i++] = current;
		current = current->next;
	}
}

void	sort_nodes(t_node **nodes, int size)
{
	int		swapped;
	t_node	*temp;
	int		i;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < size - 1)
		{
			if (nodes[i]->value > nodes[i + 1]->value)
			{
				temp = nodes[i];
				nodes[i] = nodes[i + 1];
				nodes[i + 1] = temp;
				swapped = 1;
			}
			i++;
		}
	}
}

void	assign_sorted_indices(t_node **nodes, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		nodes[i]->index = i;
		i++;
	}
}

void	assign_indices(t_stack *stack_a)
{
	int		size;
	t_node	**nodes;

	size = stack_length(stack_a);
	if (size <= 0)
		return ;
	nodes = malloc(size * sizeof(t_node *));
	if (!nodes)
		return ;
	store_nodes(stack_a, nodes, size);
	sort_nodes(nodes, size);
	assign_sorted_indices(nodes, size);
	free(nodes);
}

void	reverse_indices(t_stack *stack_a)
{
	int		size;
	t_node	*current;

	size = stack_length(stack_a);
	current = stack_a->top;
	while (current)
	{
		current->index = size - 1 - current->index;
		current = current->next;
	}
}
