/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 16:51:59 by brouane           #+#    #+#             */
/*   Updated: 2026/02/01 20:55:37 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char d)
{
	if (d >= 48 && 57 >= d)
		return (1);
	return (0);
}

int	ft_issign(char s)
{
	if (s == 43 || s == 45)
		return (1);
	return (0);
}

int	dig_sign_checker(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i]) || ft_issign(str[i])))
			return (1);
		if (ft_issign(str[i]) && (i != 0
				|| (i == 0 && ft_strlen(str) == 1)))
			return (1);
		i++;
	}
	return (0);
}

int	dup_errors(int count, long *nums)
{
	int	i;
	int	j;

	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (nums[i] == nums[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_for_errors(char ***array, long **original_numbers, int count)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while ((*array)[i])
	{
		if (dig_sign_checker((*array)[i]))
		{
			flag = 1;
			break ;
		}
		(*original_numbers)[i] = ft_atoi((*array)[i], &flag);
		if (flag == 1)
			break ;
		i++;
	}
	if (flag == 0)
	{
		if (dup_errors(count, *original_numbers))
			return (ft_print("Error"), 1);
	}
	else
		return (ft_print("Error"), 1);
	return (0);
}
