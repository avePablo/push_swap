/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfuto <kfuto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:48:14 by pabalvar          #+#    #+#             */
/*   Updated: 2025/02/24 16:42:35 by kfuto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../../Libft/libft.h"
# include "../../ft_printf/ft_printf.h"

// Definición de nodo de la pila
typedef struct s_node {
    int value;
    struct s_node *next;
} t_node;

// Definición de la pila
typedef struct s_stack {
    t_node *top; // Apunta al tope de la pila
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

int get_value_at_index(t_stack *stack, int index);

void set_value_at_index(t_stack *stack, int index, int value);

void quick(t_stack *stack, int min, int max);

#endif



// pinga