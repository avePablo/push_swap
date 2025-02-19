/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfuto <kfuto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:47:24 by pabalvar          #+#    #+#             */
/*   Updated: 2025/02/19 19:40:54 by kfuto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función para inicializar una pila
void init_stack(t_stack *stack) 
{
    stack->top = NULL;
}

// Función para verificar si la pila está vacía
int is_empty(t_stack *stack) 
{
    return (stack->top == NULL);
}

// Función para agregar un elemento a la pila (push)
void push(t_stack *stack, int value) 
{
  
    t_node *new_node = malloc(sizeof(t_node));
    if (!new_node)
        return;
    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
}
