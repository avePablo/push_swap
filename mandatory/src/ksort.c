#include "push_swap.h"

void partial_sort(t_stack *stack_a, int k)
{
    int i = 0;
    int size = stack_length(stack_a);
    while (i < size - 1)
    {
        int j = i + 1;
        while (j < size && j <= i + k)
        {
            t_node *first = stack_a->top;
            t_node *second = first->next;
            int count = 0;
            while (count < j - i && second)
            {
                first = second;
                second = second->next;
                count++;
            }
            if (second && first->index > second->index)
                sa(stack_a);
            j++;
        }
        i++;
    }
}

void rebuild_stack(t_stack *stack_a, t_node **nodes, int size)
{
    stack_a->top = nodes[0];
    t_node *current = stack_a->top;
    int i = 1;
    while (i < size)
    {
        current->next = nodes[i];
        current = current->next;
        i++;
    }
    current->next = NULL;
}

void k_sort(t_stack *stack_a, int k)
{
    if (!stack_a || !stack_a->top)
        return;
    
    int size = stack_length(stack_a);
    t_node **nodes = malloc(size * sizeof(t_node *));
    if (!nodes)
        return;
    
    store_nodes(stack_a, nodes, size);
    partial_sort(stack_a, k);
    rebuild_stack(stack_a, nodes, size);
    
    free(nodes);
}
