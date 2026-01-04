/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 16:53:12 by brouane           #+#    #+#             */
/*   Updated: 2026/01/05 00:03:01 by brouane          ###   ########.fr       */
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

char **first(char **argv, int argc, int *c)
{
    int i = 0;
    int temp;
    
    char **array = (char **)malloc(sizeof(char *) * (*c + 1));
    if(!array)
        return (NULL);
    i = 0;
    int word = 0;
    while(argc - 1 > i)
    {
        temp = word;
        word = split_them(*(argv + i++), array, ' ', word);
        if (word == temp)
            *c = -1;
    }
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

void numbers_copy(long *numbers, long *unordered_numbers, int c){
    int i;

    i = 0;
    while (i < c)
    {
        unordered_numbers[i] = numbers[i];
        i++;
    }
}

int sort_numbers(long *numbers, int c)
{
    int flag = 0;
    int i = 0;
    while (i < c - 1)
    {
        int j = i + 1;
        while (j <= c - 1)
        {
            if (numbers[i] > numbers[j])
            {
                long temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
                flag = 1;
            }
            j++;
        }
        i++;
    }
    return (flag);
}

int find_index(int value, long *numbers, int c)
{
    int index = 0;
    while (c > index)
    {
        if(value == numbers[index])
            return index;
        index++;
    }
}

void assign_to_stack(stack_node_t **stack, long *unordered_numbers, long *numbers, int c)
{
    int i = 0;
    while (c > i)
    {
        int index = find_index(unordered_numbers[i], numbers, c);
        ft_lstadd_back(stack, unordered_numbers[i], index);
        i++;
    }
}

void push_to_b(stack_node_t **stack_a, stack_node_t **stack_b)
{
    stack_node_t *temp = *stack_a;
    
    int min_range = 0;
    int max_range = 2;
    int count = 0;
    while (temp && max_range >= count)
    {
        // printf("while: %d", temp->value);
        // printf("   %d\n", temp->index);
        if (temp->index >= min_range && temp->index <= max_range)
        {
            printf("pb\n");
            temp = pb(stack_a, stack_b, temp);
            count++;
        }
        else
        {
            printf("ra\n");
            // temp = temp->next;
            temp = ra(stack_a);
        }
        if(max_range < count)
        {
            int temp_min_range = min_range;
            min_range = max_range + 1;
            max_range = max_range + (max_range - temp_min_range) + 1;
            printf("------------------------------------\n");
        }
    }
    // printf("count: %d\n", count);
}

int which_position(stack_node_t *stack_b, int right_index)
{
    int pos = 0;
    while (stack_b && stack_b->index != right_index)
    {
        stack_b = stack_b->next;
        pos++;
    }
    return pos;
}

void push_back_to_a(stack_node_t **stack_a, stack_node_t **stack_b, int c)
{
    stack_node_t *temp = *stack_b;
    int right_index = c - 1;
    int position = 0;
    int y = 0;
    while (temp) // while
    {
        if (temp->index == right_index)
        {
            temp = pa(stack_a, stack_b, temp);
            right_index--;
        }
        else
        {
            stack_node_t *tt = *stack_b;
            printf("-----------------stack_b %d\n", tt->value);
            printf("-----------------temp %d\n", temp->value);
            printf("position: %d\n", position);
            position = which_position(*stack_b, right_index); // 
            printf("position: %d\n", position);
            if (position < right_index / 2)
            {
                while (temp && position > 0) // while
                {
                    temp = rb(stack_b);
                    printf("rb\n");
                    position--;
                }
                if (temp)
                {
                    temp = pa(stack_a, stack_b, temp); 
                    right_index--;
                    printf("pa\n");
                }
            }
            else
            {
                // break;
                printf("position: %d\n", position);
                printf("right_index: %d\n", right_index);
                while (temp && position >= right_index) // while
                {
                    temp = rrb(stack_b);
                    stack_node_t *pp = *stack_b;
                    printf("dddddddddddddddddddddddddddddddddddd%d\n", temp->value);
                    printf("pppppppppppppppppppppppppppppppppppp%d\n", pp->value);
                    position--;
                }
                if (temp)
                {
                    temp = pa(stack_a, stack_b, temp);
                    right_index--;
                }
            }
        }
        y++;
        printf("y workedddddddddddddddddddddddddddddddddddddddddddddd\n");
    }
    
}

int push_swap(int argc, char **argv)
{
    stack_node_t *stack_a = NULL;
    stack_node_t *stack_b = NULL;
    
    char **array;
    long *numbers;
    long *unordered_numbers;
    int c;
    
    if (argc == 1 || (argc == 2 && !**(argv + 1)))
        return (1);
    c = count_all_nums(argv + 1, argc);
    array = first(argv + 1, argc, &c);
    if (c == -1)
        return 0;
    
    numbers = (long *)malloc(sizeof(long) * c);
    unordered_numbers = (long *)malloc(sizeof(long) * c);
    if(!numbers || !unordered_numbers)
    {
        free(unordered_numbers);
        free(numbers);
        free(array);
        return 0;
    }
    if(check_for_errors(array, numbers, c))
    {
        printf("error\n");
        free(array);
        free(numbers);
        return (1);
    }
    int i = 0;
    numbers_copy(numbers, unordered_numbers, c);
    if(!sort_numbers(numbers, c))
        return (0);
    assign_to_stack(&stack_a, unordered_numbers, numbers, c);
    push_to_b(&stack_a, &stack_b);
    printf("jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj\n");
    push_back_to_a(&stack_a, &stack_b, c);
    stack_node_t *tmp = stack_b;
	while (tmp)
	{
		printf("value: %d -> \n", tmp->value);
		printf("index: %d -> \n", tmp->index);
		printf("##################\n");
		tmp = tmp->next;
	}
    printf("@@@@@@@@@@@@@@@@@@@@@@@@\n");
    tmp = stack_a;
	while (tmp)
	{
		printf("value: %d -> \n", tmp->value);
		printf("index: %d -> \n", tmp->index);
		printf("##################\n");
		tmp = tmp->next;
	}
        // printf("jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj\n");


    
    return (0);
}

int main(int argc, char **argv)
{
    push_swap(argc, argv);
}