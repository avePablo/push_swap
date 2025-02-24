#include "push_swap.h"

void quick(t_stack *stack, int min, int max) {
    if (min >= max) // Caso base: Si la subpila tiene 1 o 0 elementos, no hacer nada
        return;

    int i = min;
    int j = max;
    int pivot = get_value_at_index(stack, (min + max) / 2); // Obtener el pivote

    do {
        // Buscar elemento mayor que el pivote desde la izquierda
        while (get_value_at_index(stack, i) < pivot && i < max)
            i++;

        // Buscar elemento menor que el pivote desde la derecha
        while (get_value_at_index(stack, j) > pivot && j > min)
            j--;

        // Si hay elementos para intercambiar, hazlo
        if (i <= j) {
            int temp = get_value_at_index(stack, i);
            set_value_at_index(stack, i, get_value_at_index(stack, j));
            set_value_at_index(stack, j, temp);
            i++;
            j--;
        }
    } while (i <= j);

    // Llamadas recursivas para ordenar las dos mitades
    if (min < j)
        quick(stack, min, j);
    if (i < max)
        quick(stack, i, max);
}


// Función para obtener el valor de un nodo en un índice específico
int get_value_at_index(t_stack *stack, int index)
{
    t_node *current = stack->top;
    int i = 0;

    // Recorre la pila hasta encontrar el nodo en la posición deseada
    while (current && i < index)
    {
        current = current->next;
        i++;
    }

    // Si encontramos el nodo, retornamos su valor
    if (current)
        return current->value;

    // Si el índice es inválido, retornamos -1 o un valor de error
    return -1;
}

// Función para establecer el valor de un nodo en un índice específico
void set_value_at_index(t_stack *stack, int index, int value)
{
    t_node *current = stack->top;
    int i = 0;

    // Recorre la pila hasta encontrar el nodo en la posición deseada
    while (current && i < index)
    {
        current = current->next;
        i++;
    }

    // Si encontramos el nodo, cambiamos su valor
    if (current)
    {
        current->value = value;
    }
}



int	ft_isvalid(char *args[])
{
	int i;
	int j;

	i = 0;
	j = 0;

	while(args[i])
	{
		j = 0;
		while(args[i][j])
			{
				if (args[i][j] == '-')
					j++;
				if (!(args[i][j] >= '0' && args[i][j] <= '9'))
					return (0);
				j++;
			}
	i++;
	}
	return (1);
}

// Reverse rotate simultáneo (rra y rrb)
void rrr(t_stack *stack_a, t_stack *stack_b)
{
    rra(stack_a);
    rrb(stack_b);
}