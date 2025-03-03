/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfuto <kfuto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:48:14 by pabalvar          #+#    #+#             */
/*   Updated: 2025/03/03 19:59:42 by kfuto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../../Libft/libft.h"
# include "../../ft_printf/ft_printf.h"

typedef struct s_node {
    int value;
    int index;
    struct s_node *next;
} t_node;

typedef struct s_stack {
    t_node *top;
} t_stack;

int	ft_isvalid(char *args[]);

void init_stack(t_stack *stack);

int is_empty(t_stack *stack);

void push(t_stack *stack, int value);

void sa(t_stack *stack_a);

void sb(t_stack *stack_b);

void ss(t_stack *stack_a, t_stack *stack_b);

void pa(t_stack *stack_a, t_stack *stack_b);

void pb(t_stack *stack_a, t_stack *stack_b);

void ra(t_stack *stack_a);

void rb(t_stack *stack_b);

void rr(t_stack *stack_a, t_stack *stack_b);

void rra(t_stack *stack_a);

void rrb(t_stack *stack_b);

void rrr(t_stack *stack_a, t_stack *stack_b);

int stack_length(t_stack *stack);

void assign_indices(t_stack *stack_a);

void store_nodes(t_stack *stack_a, t_node **nodes, int size);

void sort_nodes(t_node **nodes, int size);

void assign_sorted_indices(t_node **nodes, int size);

void k_sort(t_stack *stack_a, int k);

void partial_sort(t_stack *stack_a, int k);

void rebuild_stack(t_stack *stack_a, t_node **nodes, int size);

double sqrt(double nbr); 

#endif