/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <pabalvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:47:24 by pabalvar          #+#    #+#             */
/*   Updated: 2025/03/24 17:23:15 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
}

int	is_empty(t_stack *stack)
{
	return (stack->top == NULL);
}

void	push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
}

int	stack_length(t_stack *stack)
{
	int		length;
	t_node	*current;

	length = 0;
	current = stack->top;
	while (current)
	{
		length++;
		current = current->next;
	}
	return (length);
}
