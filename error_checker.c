/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 16:51:59 by brouane           #+#    #+#             */
/*   Updated: 2026/01/08 23:22:29 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_isdigit(char d)
{
    if(d >= 48 && 57 >= d)
        return (1);
    return (0);
}

int ft_issign(char s)
{
    if(s == 43 || s == 45)
        return (1);
    return (0);
}

int error_checker(char *str)
{
    int i = 0;
    
    while (str[i])
    {
        if (!(ft_isdigit(str[i]) || ft_issign(str[i])))
            return (1);
        if (ft_issign(str[i]) && (i != 0 || (i == 0 && ft_strlen(str) == 1)))
            return (1);
        i++;
    }
    return (0);
}