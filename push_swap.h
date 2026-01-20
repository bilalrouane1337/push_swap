/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 16:49:59 by brouane           #+#    #+#             */
/*   Updated: 2026/01/20 18:48:49 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct stack_node
{
    int value;
    int index;
    void *next;
    
} stack_node_t;


#include <stdio.h>



#include <unistd.h>
#include <stdlib.h>
#include <limits.h>


int		check_for_errors(char ***array, long **numbers, int c);
int		ft_count_words(char const *str, char c);
int		find_index(int value, long *numbers, int c);
size_t	ft_strlen(const char *s);
int		free_array(char **ptr, int i);
void	free_pointers(char **array, long **numbers, long **unordered_numbers, int len);
void	free_stack(stack_node_t **stack);
void	free_all_stacks(stack_node_t **stack_a, stack_node_t **stack_b);
long	ft_atoi(const char *nptr, int *flag);
int		ft_lstadd_back(stack_node_t **lst, long value, int index);
void	ft_print(char *str);
stack_node_t	*ra(stack_node_t **stack_a);
stack_node_t	*rb(stack_node_t **stack_b);
stack_node_t	*rra(stack_node_t **stack_a);
stack_node_t	*rrb(stack_node_t **stack_b);
stack_node_t	*pb(stack_node_t **stack_a, stack_node_t **stack_b,
			stack_node_t *to_push);
stack_node_t	*pa(stack_node_t **stack_a, stack_node_t **stack_b,
			stack_node_t *to_push);
stack_node_t	*sa(stack_node_t **stack_a);
stack_node_t	*sb(stack_node_t **stack_b);
int		count_all_nums(char **argv, int argc);
char	**array_manager(char **argv, int argc, int count);
void	numbers_manager(char	***array, int count, long **numbers, long **unordered_numbers);
void	numbers_copy(long *numbers, long *unordered_numbers, int c);
int		sort_numbers(long *numbers, int c);
int		assign_to_stack(stack_node_t **stack, long *unordered_numbers,
			long *numbers, int c);
void	operations_manager(stack_node_t **stack_a, stack_node_t **stack_b,
			int c);
void	three_sorter(stack_node_t **stack_a);
void	push_back_to_a(stack_node_t **stack_a, stack_node_t **stack_b, int c);
void	push_from_a(stack_node_t **stack_a, stack_node_t **stack_b, int c);
void	push_to_b(stack_node_t **stack_a, stack_node_t **stack_b, int c);
int		split_them(char const *s, char **s2, int word);

#endif