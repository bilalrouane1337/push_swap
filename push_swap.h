/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 16:49:59 by brouane           #+#    #+#             */
/*   Updated: 2025/12/31 18:10:01 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>



#include <unistd.h>
#include <stdlib.h>

int ft_split_c(char const *s, char **s2, char c, int word);
char	**ft_split(char const *s, char c);
int error_checker(char *str);
int	ft_count_words(char const *str, char c);
char	*ft_putword(char *word, char const *s, int i, int word_len);

#endif