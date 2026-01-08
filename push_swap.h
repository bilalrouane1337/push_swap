/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 16:49:59 by brouane           #+#    #+#             */
/*   Updated: 2026/01/07 23:55:38 by brouane          ###   ########.fr       */
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

size_t	ft_strlen(const char *s);
int split_them(char const *s, char **s2, char c, int word);
int error_checker(char *str);
int	ft_count_words(char const *str, char c);
char	*ft_putword(char *word, char const *s, int i, int word_len);
long	ft_atoi(const char *nptr);
int free_array(char **ptr, int i);
void free_pointers(char ***array, long **numbers, long **unordered_numbers, int len);
void free_stack(stack_node_t **stack);
int ft_lstadd_back(stack_node_t **lst, long value, int index);

void ft_print(char *str);

stack_node_t *ra(stack_node_t **stack_a);
stack_node_t *rb(stack_node_t **stack_b);

stack_node_t *rra(stack_node_t **stack_a);
stack_node_t *rrb(stack_node_t **stack_b);

stack_node_t *pb(stack_node_t **stack_a, stack_node_t **stack_b, stack_node_t *to_push, int *count);
stack_node_t *pa(stack_node_t **stack_a, stack_node_t **stack_b, stack_node_t *to_push);

stack_node_t *sa(stack_node_t **stack_a);
stack_node_t *sb(stack_node_t **stack_b);

#endif