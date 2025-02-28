#include "push_swap.h"
// Encontrar el valor del pivote en la pila sin usar arrays
int find_pivot(t_stack *stack, int size)
{
    t_node *current = stack->top;
    int min = current->value;
    int max = current->value;
    int i = 0;

    while (current && i < size)
    {
        if (current->value < min)
            min = current->value;
        if (current->value > max)
            max = current->value;
        current = current->next;
        i++;
    }
    return (min + max) / 2; // Aproximación al pivote
}

// Mover elementos menores o iguales al pivote a B
void push_to_b(t_stack *a, t_stack *b, int pivot)
{
    int size = stack_length(a);
    int i = 0;
    while (i < size)
    {
        if (get_value_at_index(a, 0) <= pivot)
        {
            pb(a, b);
            rb(b);
        }
        else
            ra(a);
        i++;
    }
}

// Buscar y traer el máximo de B a la cima
void move_max_to_top(t_stack *b)
{
    int max_value = get_value_at_index(b, 0);
    int i = 1;
    while (i < stack_length(b))
    {
        if (get_value_at_index(b, i) > max_value)
            max_value = get_value_at_index(b, i);
        i++;
    }
    while (get_value_at_index(b, 0) != max_value)
        rb(b);
}

// Mover los elementos de vuelta a A en orden
void push_back_to_a(t_stack *a, t_stack *b)
{
    while (!is_empty(b))
    {
        move_max_to_top(b);
        pa(a, b);
    }
}

// Implementar K-sort en Push Swap usando solo A y B
void k_sort(t_stack *a, t_stack *b)
{
    int size = stack_length(a);
    int pivot = find_pivot(a, size);

    push_to_b(a, b, pivot);
    push_back_to_a(a, b);
}
