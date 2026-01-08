/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pointers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:41:32 by brouane           #+#    #+#             */
/*   Updated: 2026/01/07 17:45:10 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_pointers(char ***array, long **numbers, long **unordered_numbers, int len)
{
    free_array(*array, len);
    free(*numbers);
    free(*unordered_numbers);
}
