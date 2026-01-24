/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 16:49:59 by brouane           #+#    #+#             */
/*   Updated: 2026/01/24 19:06:55 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	struct s_stack_node	*next;
}	t_stack_node;

int				check_for_errors(char ***array, long **numbers, int c);
int				ft_count_words(char const *str, char c);
int				find_index(int value, long *numbers, int c);
size_t			ft_strlen(const char *s);
int				free_array(char **ptr, int i);
void			free_pointers(char **array, long **numbers,
					long **unordered_numbers, int len);
void			free_stack(t_stack_node **stack);
void			free_all_stacks(t_stack_node **stack_a, t_stack_node **stack_b);
long			ft_atoi(const char *nptr, int *flag);
int				ft_lstadd_back(t_stack_node **lst, long value, int index);
void			ft_print(char *str);
t_stack_node	*ra(t_stack_node **stack_a);
t_stack_node	*rb(t_stack_node **stack_b);
t_stack_node	*rra(t_stack_node **stack_a);
t_stack_node	*rrb(t_stack_node **stack_b);
t_stack_node	*pb(t_stack_node **stack_a, t_stack_node **stack_b,
					t_stack_node *to_push);
t_stack_node	*pa(t_stack_node **stack_a, t_stack_node **stack_b,
					t_stack_node *to_push);
t_stack_node	*sa(t_stack_node **stack_a);
t_stack_node	*sb(t_stack_node **stack_b);
int				count_all_nums(char **argv, int argc);
char			**array_manager(char **argv, int argc, int count);
void			numbers_manager(char ***array, int count,
					long **numbers, long **unordered_numbers);
void			numbers_copy(long *numbers, long *unordered_numbers, int c);
int				sort_numbers(long *numbers, int c);
int				assign_to_stack(t_stack_node **stack,
					long *unordered_numbers, long *numbers, int c);
void			operations_manager(t_stack_node **stack_a,
					t_stack_node **stack_b, int c);
void			three_sorter(t_stack_node **stack_a);
void			push_back_to_a(t_stack_node **stack_a,
					t_stack_node **stack_b, int c);
void			push_from_a(t_stack_node **stack_a,
					t_stack_node **stack_b, int c);
void			push_to_b(t_stack_node **stack_a,
					t_stack_node **stack_b, int c);
int				split_them(char const *s, char **s2, int word);

#endif
