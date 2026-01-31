/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 20:50:43 by brouane           #+#    #+#             */
/*   Updated: 2026/01/31 20:50:44 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# include "push_swap.h"
# include "get_next_line.h"

/* ===== STRING ===== */
int     ft_strcmp(char *s1, char *s2);

/* ===== DOUBLE OPS ===== */
void    ss(t_stack_node **a, t_stack_node **b, int print);
void    rr(t_stack_node **a, t_stack_node **b, int print);
void    rrr(t_stack_node **a, t_stack_node **b, int print);

#endif
