/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 20:50:43 by brouane           #+#    #+#             */
/*   Updated: 2026/02/01 21:15:15 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# include "push_swap.h"
# include "get_next_line.h"

int		ft_strcmp(char *s1, char *s2);

void	ss(t_stack_node **a, t_stack_node **b, int print);
void	rr(t_stack_node **a, t_stack_node **b, int print);
void	rrr(t_stack_node **a, t_stack_node **b, int print);

int		is_sorted_stack(t_stack_node *stack);
int		exec_instruction(char *line,
			t_stack_node **a, t_stack_node **b);
int		read_and_execute(t_stack_node **a, t_stack_node **b);

void	free_and_exit(t_stack_node **a, t_stack_node **b,
			t_data *data, int ret);

#endif
