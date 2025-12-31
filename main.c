/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 16:53:12 by brouane           #+#    #+#             */
/*   Updated: 2025/12/31 21:06:38 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_putwordd(char const *s, int i, int word_len)
{
	int	j;
    char *word = malloc(word_len + 1);

	j = 0;
	while (word_len > i)
	{
		word[j] = s[i];
		j++;
		i++;
	}
	word[j] = '\0';
	return (word);
}

int count_all_nums(char **argv, int argc)
{
    int i = 0;
    int c = 0;
    while(argc - 1 > i)
    {
        c += ft_count_words(*(argv + i), ' ');
        i++;
    }
    return (c);
}

char **first(char **argv, int argc, int c)
{
    int i = 0;
    
    char **array = (char **)malloc(sizeof(char *) * (c + 1));
    if(!array)
        return (NULL);
    i = 0;
    int word = 0;
    while(argc - 1 > i)
        word = split_them(*(argv + i++), array, ' ', word);
    return(array);
}

int min_max_dup_errors(int c, long *numbers)
{
    int i = 0;
    
    while(c > i)
    {
        if(numbers[i] > 2147483647 || numbers[i] < -2147483648)
            return (1);
        int j = 0;
        while(c > j)
        {
            if(numbers[i] == numbers[j] && i != j)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int check_for_errors(char **array, long *numbers, int c)
{
    int max;
    
    max = 0;
    while (array[max])
    {   
        if (error_checker(array[max]))
            return (1);
        numbers[max] = ft_atoi(array[max]);
        max++;
    }
    if(min_max_dup_errors(c, numbers))
        return (1);
    return (0);
}

int push_swap(int argc, char **argv)
{
    char **array;
    long *numbers;
    int c;
    
    if (argc == 1 || (argc == 2 && !**(argv + 1)))
        return (1);
    c = count_all_nums(argv + 1, argc);
    array = first(argv + 1, argc, c);
    numbers = (long *)malloc(sizeof(long) * c);
    if(!numbers)
    {
        free(array);
        return 0;
    }
    if(check_for_errors(array, numbers, c))
    {
        printf("error\n");
        free(array);
        free(numbers);
    }    
    return (0);
}

int main(int argc, char **argv)
{
    push_swap(argc, argv);
}