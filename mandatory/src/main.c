/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <pabalvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:47:26 by pabalvar          #+#    #+#             */
/*   Updated: 2025/03/31 19:27:59 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sp_cases(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_length(stack_a) == 2)
		sa(stack_a);
	else if (stack_length(stack_a) == 3)
		sort_three_node(stack_a);
	else if (stack_length(stack_a) == 4)
		sort_four_node(stack_a, stack_b);
	else if (stack_length(stack_a) == 5)
		sort_five_node(stack_a, stack_b);
	else
		k_sort(stack_a, stack_b);
}

int	node_repeat(t_stack *stack, t_stack *stack_b)
{
	t_node	*current;

	current = stack->top;
	while (current && current->next)
	{
		if (current->value == current->next->value)
		{
			error_handler();
			free_stack(stack);
			free_stack(stack_b);
			exit(1);
		}
		current = current->next;
	}
	return (0);
}

void	get_valid(t_stack *stack_a, char **args, t_stack *stack_b)
{
	int				j;
	long long int	num;

	j = 0;
	while (args[j] != NULL)
	{
		if (ft_isvalid(args) == 0)
		{
			error_handler();
			free_split(args);
			free_stack(stack_a);
			free_stack(stack_b);
			exit(1);
		}
		num = ft_atoi(args[j]);
		push(stack_a, num);
		j++;
	}
}

int	get_nums(int argc, char *argv[], t_stack *stack_a, t_stack *stack_b)
{
	char	**args;
	int		i;

	i = 1;
	while (i < argc)
	{
		args = ft_split(argv[i], ' ');
		comprove_int(args);
		get_valid(stack_a, args, stack_b);
		free_split(args);
		i++;
	}
	node_repeat(stack_a, stack_b);
	return (i - 1);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		return (1);
	init_stack(stack_a);
	init_stack(stack_b);
	if (argc > 1)
		get_nums(argc, argv, stack_a, stack_b);
	reverse_stack(stack_a);
	if (is_sorted(stack_a) == 1)
	{
		free_stack(stack_a);
		free_stack(stack_b);
		exit(0);
	}
	if (!is_empty(stack_a))
		assign_indices(stack_a);
	sp_cases(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
