/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 21:36:37 by brouane           #+#    #+#             */
/*   Updated: 2026/01/04 23:37:48 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack_node_t *rotate(stack_node_t **stack)
{
    stack_node_t *temp = *stack;
    
    *stack = temp->next;
    temp->next = NULL;
    
    stack_node_t *search = *stack;
    
    if (search)
    {
        while (search->next)
        {
            search = search->next;
        }
        search->next = temp;
    }
    return (*stack);
}

stack_node_t *reverse_rotate(stack_node_t **stack)
{
    stack_node_t *curr = *stack;
    stack_node_t *first = *stack;
    stack_node_t *prev;

    if (curr)
    {
        while (curr->next)
        {
            prev = curr;
            curr = curr->next;
        }
        curr->next = first;
        *stack = curr;
        prev->next = NULL;
    }
    return (*stack);
}

stack_node_t *ra(stack_node_t **stack_a)
{
    return (rotate(stack_a));
}

stack_node_t *rb(stack_node_t **stack_b)
{
    return (rotate(stack_b));
}

stack_node_t *rra(stack_node_t **stack_a)
{
    return (reverse_rotate(stack_a));
}

stack_node_t *rrb(stack_node_t **stack_b)
{
    return (reverse_rotate(stack_b));
}

void	ft_lstadd_bback(stack_node_t **lst, stack_node_t *new)
{
	stack_node_t	*start;

	new->next = NULL;
	if (*lst)
	{
        start = *lst;
		while (start->next)
			start = start->next;
		start->next = new;
	}
	else
		*lst = new;
}

stack_node_t *push(stack_node_t **from_stack, stack_node_t **to_stack, stack_node_t *to_push)
{

    
    stack_node_t *temp = *from_stack;
    *from_stack = temp->next;
    
    // printf("hhhhhhhhhhhhh%p\n", temp->value);
    // stack_node_t * ff = *from_stack;
    // printf("ppppppppppppppb%p\n", ff->value);
    to_push->next = *to_stack;
	*to_stack = to_push;

    // stack_node_t * fff = *to_stack;
    // printf("xxxxxxxx%p\n", fff->next);

            
    return(*from_stack);
}

stack_node_t *pb(stack_node_t **stack_a, stack_node_t **stack_b, stack_node_t *to_push)
{
    return (push(stack_a, stack_b, to_push));
}

stack_node_t *pa(stack_node_t **stack_a, stack_node_t **stack_b, stack_node_t *to_push)
{
    return (push(stack_b, stack_a, to_push));
}

// int main()
// {
//     stack_node_t	*list = NULL;
// 	stack_node_t	*tmp = NULL;

// 	stack_node_t	*one = malloc(sizeof(stack_node_t));
// 	stack_node_t	*onee = malloc(sizeof(stack_node_t));
// 	stack_node_t	*two = malloc(sizeof(stack_node_t)); 
// 	stack_node_t	*three = malloc(sizeof(stack_node_t)); 
// 	stack_node_t	*four = malloc(sizeof(stack_node_t));

// 	one->index = 5; 
// 	two->index = 10; three->index = 15; four->index = 20;

// 	ft_lstadd_bback(&list, one); 
// 	ft_lstadd_bback(&list, two); 
// 	ft_lstadd_bback(&list, three); 
// 	ft_lstadd_bback(&list, four);

// 	rotate(&list);

// 	tmp = list;
// 	while (tmp)
// 	{
// 		printf("%d -> ", tmp->index);
// 		tmp = tmp->next;
// 	}
// 	printf("NULL\n");
// }