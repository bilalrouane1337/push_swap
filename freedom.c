/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:28:25 by brouane           #+#    #+#             */
/*   Updated: 2026/01/08 22:46:05 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_pointers(char ***array, long **numbers, long **unordered_numbers, int len)
{
    free_array(*array, len);
    free(*numbers);
    free(*unordered_numbers);
}

void free_stack(stack_node_t **stack)
{
    stack_node_t *temp;

    temp = *stack;
    if (!stack)
        return ;
    while (*stack)
    {
        temp = (*stack)->next;
        free(*stack);
        *stack = temp;
    }
}

void free_all_stacks(stack_node_t **stack_a, stack_node_t **stack_b)
{
    free_stack(stack_a);
    free_stack(stack_b);
}

void free_all(stack_node_t **stack_a, stack_node_t **stack_b, char ***array, long **numbers, long **unordered_numbers, int c)
{
    free_stack(stack_a);
    free_stack(stack_b);
    free_pointers(array, numbers, unordered_numbers, c);
}