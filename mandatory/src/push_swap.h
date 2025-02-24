/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfuto <kfuto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:48:14 by pabalvar          #+#    #+#             */
/*   Updated: 2025/02/24 11:56:10 by kfuto            ###   ########.fr       */
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


#endif



// pinga