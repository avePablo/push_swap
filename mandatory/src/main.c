/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <pabalvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:47:26 by pabalvar          #+#    #+#             */
/*   Updated: 2025/03/21 17:07:39 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	comprove_int(char **num)
{
	int		i;
	char	*str;
	long	number;

	i = 0;
	while (num[i] != NULL)
	{
		str = num[i];
		if (str == NULL || *str == '\0')
		{
			free_matrix(num);
			ft_printf("vacío\n");
			exit(1);
		}
		number = ft_atol(str);
		if (number > INT_MAX || number < INT_MIN)
		{
			free_matrix(num);
			ft_printf("mucho int\n");
			exit(1);
		}
		i++;
	}
}

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
		k_sort(stack_a);
}

int	node_repeat(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current && current->next)
	{
		if (current->value == current->next->value)
		{
			ft_printf("repes\n");
			exit(1);
		}
		current = current->next;
	}
	return (0);
}

int	get_nums(int argc, char *argv[], t_stack *stack_a)
{
	char			**args;
	long long int	num;
	int				i;
	int				j;

	i = 1;
	while (i < argc)
	{
		args = ft_split(argv[i], ' ');
		comprove_int(args);
		j = 0;
		while (args[j] != NULL)
		{
			if (ft_isvalid(args) == 0)
			{
				ft_printf("%s\n", "caracter no vale");
				exit(1);
			}
			num = ft_atoi(args[j]);
			push(stack_a, num);
			j++;
		}
		i++;
	}
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
		get_nums(argc, argv, stack_a);
	reverse_stack(stack_a);
	if (is_sorted(stack_a) == 1)
		exit(0);
	if (!is_empty(stack_a))
		assign_indices(stack_a);
	node_repeat(stack_a);
	sp_cases(stack_a, stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}
