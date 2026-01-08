/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 16:53:12 by brouane           #+#    #+#             */
/*   Updated: 2026/01/08 01:15:31 by brouane          ###   ########.fr       */
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

char **first(char **argv, int argc, int c, long **numbers, long **unordered_numbers)
{
    int i;
    int temp;
    char **array;
    int index_reached;
    
    index_reached = 0;
    array = (char **)malloc(sizeof(char *) * (c + 1)); // from c + 1 to c 
    if(c == 0 || !array)
        return (free_array(array, index_reached), NULL);
    i = 0;
    while(argc - 1 > i)
    {
        temp = index_reached;
        index_reached = split_them(*(argv + i++), array, ' ', index_reached);
        if (index_reached == temp || index_reached == -1)
            return(free_array(array, index_reached), NULL);
    }
    *numbers = (long *)malloc(sizeof(long) * c);
    *unordered_numbers = (long *)malloc(sizeof(long) * c);
    if (!*numbers || !*unordered_numbers)
        return (free_array(array, index_reached), free(*numbers), free(*unordered_numbers), NULL);
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

int check_for_errors(char ***array, long **numbers, int c)
{
    int max;
    int flag;

    max = 0;
    flag = 0;
    while ((*array)[max])
    {
        if (error_checker((*array)[max]))
        {
            flag = 1;
            break;
        }
        (*numbers)[max] = ft_atoi((*array)[max]);
        max++;
    }
    if (flag == 0)
    {
        if (min_max_dup_errors(c, *numbers))
            return (1);
    }
    else
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

int assign_to_stack(stack_node_t **stack, long *unordered_numbers, long *numbers, int c)
{
    int i = 0;
    while (c > i)
    {
        int index = find_index(unordered_numbers[i], numbers, c);
        if (ft_lstadd_back(stack, unordered_numbers[i], index))
            return (1);
        i++;
    }
    return (0);
}

int set_max_range(int count)
{
    if (count == 5)
    {
        return 1;
    }
    
}

void push_to_b(stack_node_t **stack_a, stack_node_t **stack_b, int c)
{
    stack_node_t *temp = *stack_a;
    
    int min_range = 0;
    int max_range = 2;
    int count = 0;
    while (*stack_a && max_range >= count)
    {
        if ((*stack_a)->index >= min_range && (*stack_a)->index <= max_range)
            pb(stack_a, stack_b, (*stack_a), &count);
        else
            ra(stack_a);
        if(max_range < count)
        {
            int temp_min_range = min_range;
            min_range = max_range + 1;
            max_range = max_range + (max_range - temp_min_range) + 1;
        }
    }
}

int which_position(stack_node_t *stack_b, int real_len)
{
    int pos = 0;
    while (stack_b && stack_b->index != real_len)
    {
        stack_b = stack_b->next;
        pos++;
    }
    return pos;
}

// void push_back_to_a(stack_node_t **stack_a, stack_node_t **stack_b, int c)
// {
//     int real_len;
//     int position;

//     real_len = c - 1;
//     position = 0;
//     while (*stack_b)
//     {
//         if ((*stack_b)->index == real_len)
//         {
//             pa(stack_a, stack_b, *stack_b);
//             real_len--;
//         }
//         else
//         {
//             position = which_position(*stack_b, real_len);
//             if (position < real_len / 2)
//             {
//                 while (*stack_b && position > 0)
//                 {
//                     rb(stack_b);
//                     position--;
//                 }
//                 if (*stack_b)
//                 {
//                     pa(stack_a, stack_b, *stack_b); 
//                     real_len--;
//                 }
//             }
//             else
//             {
//                 while (*stack_b && position <= real_len) // while
//                 {
//                     rrb(stack_b);
//                     position++;
//                 }
//                 if (*stack_b)
//                 {
//                     pa(stack_a, stack_b, *stack_b);
//                     real_len--;
//                 }
//             }
//         }
//     }   
// }











void	push_using_rb(stack_node_t **stack_a,
							stack_node_t **stack_b,
							int *position,
							int *real_len)
{
	while (*stack_b && *position > 0)
	{
		rb(stack_b);
		(*position)--;
	}
	if (*stack_b)
	{
		pa(stack_a, stack_b, *stack_b);
		(*real_len)--;
	}
}

void	push_using_rrb(stack_node_t **stack_a,
							 stack_node_t **stack_b,
							 int *position,
							 int *real_len)
{
	while (*stack_b && *position <= *real_len)
	{
		rrb(stack_b);
		(*position)++;
	}
	if (*stack_b)
	{
		pa(stack_a, stack_b, *stack_b);
		(*real_len)--;
	}
}

void	push_back_to_a(stack_node_t **stack_a,
						stack_node_t **stack_b,
						int c)
{
	int	real_len;
	int	position;

	real_len = c - 1;
	while (*stack_b)
	{
		if ((*stack_b)->index == real_len)
		{
			pa(stack_a, stack_b, *stack_b);
			real_len--;
		}
		else
		{
			position = which_position(*stack_b, real_len);
			if (position < real_len / 2)
				push_using_rb(stack_a, stack_b, &position, &real_len);
			else
				push_using_rrb(stack_a, stack_b, &position, &real_len);
		}
	}
}


















void two_sorter(stack_node_t **stack_a)
{
    ra(stack_a);
}

void three_sorter(stack_node_t **stack_a)
{
    stack_node_t *second = (*stack_a)->next;
    stack_node_t *third = second->next;
    
    int a = (*stack_a)->index;
    int b = second->index;
    int c = third->index;

    if (a > b && b < c && a < c) // 5 0 7
        sa(stack_a);
    else if (a > b && b > c)
    {
        sa(stack_a);
        rra(stack_a);
    }
    else if (a > b && b < c && a > c)
        ra(stack_a);
    else if (a < b && b > c && a < c)
    {
        sa(stack_a);
        ra(stack_a);
    }
    else if (a < b && b > c && a > c)
        rra(stack_a);
}

void operations_manager(stack_node_t **stack_a, stack_node_t **stack_b, int c)
{
    if (c == 2)
        two_sorter(stack_a);
    else if (c == 3)
        three_sorter(stack_a);
    // else if (c <= 5)
    //     five_sorter();
    // else
    //     chunk_sorter();
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
    array = first(argv + 1, argc, c, &numbers, &unordered_numbers);
    if (array == NULL)
        return (1);
    if(check_for_errors(&array, &numbers, c))
    {
        printf("Error\n");
        free_pointers(&array, &numbers, &unordered_numbers, c);
        return (1);
    }
    numbers_copy(numbers, unordered_numbers, c);
    if(!sort_numbers(numbers, c) || assign_to_stack(&stack_a, unordered_numbers, numbers, c))
    {
        free_pointers(&array, &numbers, &unordered_numbers, c);
        free_stack(&stack_a);
        return (1);
    }
    operations_manager(&stack_a, &stack_b, c);
    push_to_b(&stack_a, &stack_b, c);
    push_back_to_a(&stack_a, &stack_b, c);
    stack_node_t *tmp = stack_a;
	while (tmp)
	{
		printf("value: %d -> \n", tmp->value);
		printf("index: %d -> \n", tmp->index);
		printf("##################\n");
		tmp = tmp->next;
	}
    // printf("@@@@@@@@@@@@@@@@@@@@@@@@\n");
	// while (tmp)
	// {
	// 	printf("value: %d -> \n", tmp->value);
	// 	printf("index: %d -> \n", tmp->index);
	// 	printf("##################\n");
	// 	tmp = tmp->next;
	// }
    //     // printf("jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj\n");
printf("jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj\n");
    free(numbers);
    free(unordered_numbers);
    free_array(array, c);
    free_stack(&stack_a);
    free_stack(&stack_b);
    printf("g\n");
    return (0);
}

int main(int argc, char **argv)
{
    push_swap(argc, argv);
    // printf("a\n");
}