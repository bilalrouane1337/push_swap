/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 21:36:37 by brouane           #+#    #+#             */
/*   Updated: 2026/01/03 23:49:06 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(stack_node_t **stack)
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
}

void ra(stack_node_t **stack_a)
{
    rotate(stack_a);
}

void rb(stack_node_t **stack_b)
{
    rotate(stack_b);
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

stack_node_t *pb(stack_node_t **stack_a, stack_node_t **stack_b, stack_node_t *to_push)
{

    
    stack_node_t *temp = *stack_a;
    // printf("hhhhhhhhhhhhh%p\n", temp->value);
    *stack_a = temp->next;
    // free(temp);

        stack_node_t * ff = *stack_a;
            // printf("ppppppppppppppb%p\n", ff->value);
    to_push->next = *stack_b;
	*stack_b = to_push;

    stack_node_t * fff = *stack_b;
            // printf("xxxxxxxx%p\n", fff->next);

            
    return(*stack_a);
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