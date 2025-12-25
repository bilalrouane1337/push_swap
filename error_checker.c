/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 16:51:59 by brouane           #+#    #+#             */
/*   Updated: 2025/12/24 18:33:36 by brouane          ###   ########.fr       */
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

int ft_isspace(char s)
{
    if(s == 32)
        return (1);
    return (0);
}

int error_checker(char *str)
{
    int i = 0;
    char **array;
    
    while (str[i])
    {
        if (!(ft_isdigit(str[i]) || ft_issign(str[i]) || ft_isspace(str[i])))
            return (1);
        if (ft_issign(str[i]) && !((i != 0 && ft_isspace(str[i - 1])) || i == 0))
            return (1);
        if (ft_isspace(str[i]))
        {
            printf("|-");
            int j = 0;
            array = ft_split(str, 32);
            while (array[j])
            {
                // printf("%s\n", array[j]);
                // printf("-------\n");
                // printf("|-");
                error_checker(array[j]);
                j++;
            }    
        }
        // printf("%s", str[i]);
        i++;
    }
    return (0);
}