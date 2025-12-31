/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 16:53:12 by brouane           #+#    #+#             */
/*   Updated: 2025/12/31 18:10:17 by brouane          ###   ########.fr       */
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

char **prezero_remover(int count, char **numbers)
{
    int max = 1;
    int j = 0;
    char **array = (char **)malloc(count - 1);
    
    while(count > max)
    {
        int i = 0;
        if (numbers[max][i] == 43 || numbers[max][i] == 45)
            i++;
        while (numbers[max][i] == 48)
            i++;
        array[j] = ft_putwordd(numbers[max], i, ft_strlen(numbers[max]));
        max++;
        j++;
    }
    return (array);
}

void first(char **argv, int argc)
{
    int i = 0;
    int c = 0;
    while(argc - 1 > i)
    {
        c += ft_count_words(*(argv + i), ' ');
        i++;
    }
    char **array = (char **)malloc(sizeof(char *) * (c + 1));
    i = 0;
    int word = 0;
    while(argc - 1 > i)
    {
        word = ft_split_c(*(argv + i), array, ' ', word);
        printf("w:%d\n", word);
        i++;
    }
    i = 0;
    while(c > i)
    {
        printf("s%d: %s\n", i, array[i]);
        i++;
    }
    printf("cc:%d\n", c);
}

int main(int argc, char **argv)
{
    char **array;
    if (argc == 1 || (argc == 2 && !**(argv + 1)))
        return (1);
    int max = 1;
    first(argv + 1, argc);
    
    // while (argc > max)
    // {   
    //     printf("l:%d\n", argc);
    //     array = ft_split(argv[max], ' ');
    //     // while()
    //     // {
            
    //         printf("s: %s\n", array[max - 1]);
    //     // }
    //     if (error_checker(array[max - 1]))
    //         write(1, "e", 1);
    //     else
    //         write(1, "g", 1);
    //     write(1, "\n", 1);
    //     max++;
    // }
    // // array = prezero_remover(argc, argv);
    // max = 0;
    // printf("W:%d\n", words);
    // while (words > max)
    // {
    //     printf("%s\n", array[max]);
    //     max++;
    // }
    // duplicate_checker()
}
