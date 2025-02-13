/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:07:55 by lserodon          #+#    #+#             */
/*   Updated: 2025/02/13 18:04:57 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     count_digits(char *str)
{
    int i;
    int count;
    
	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != ' ')
		i++;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			count++;
			while (str[i] && str[i] == ' ')
				i++;
		}
		else
			i++;
	}
	if (str[i - 1] != ' ' && i > 0)
		count++;
	return (count);
}
long    *fill_digits_array(char *str, long *digits_array)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(str[i])
    {
        digits_array[j++] = ft_atoi(&str[i]);
        if (ft_atoi(&str[i]) > INT_MAX ||ft_atoi(&str[i]) < INT_MIN)
            {
                free_all(NULL, digits_array, str);
                write(2, "Error\n", 6);
                exit(1);
            }
        if (str[i] == '-')
			i++;
		while (str[i] && (str[i] >= '0' && str[i] <= '9'))
			i++;
        while (str[i] && (str[i] == ' '))
            i++;
    }
    return(digits_array);
}

long     *set_up_digits_array(char *str)
{
    long *digits_array;

    digits_array = malloc(sizeof(long) * count_digits(str));
    if (!digits_array)
        return(NULL);
    if(!ft_isdigit(str))
        {
            free_all(NULL, digits_array, str);
            write(2, "Error\n", 6);
            exit(1);
        }
    fill_digits_array(str, digits_array);
    return(digits_array);
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("Value: %d\n", stack->value);
		stack = stack->next;
	}
} 

int	check_sort_a(t_stack *stack_a)
{
	while (stack_a && (stack_a)->next)
	{
		if ((stack_a)->value > ((stack_a)->next)->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int count_nodes(t_stack *stack)
{
	int	i;

	i = 0;
	while(stack)
	{
		i++;
		stack = stack->next;
	}
	return(i);
}

void    sort_algorithm(t_stack **stack)
{
    if(count_nodes(stack[0]) == 2)
    {
        if(!check_sort_a(stack[0]))
            swap_a(&stack[0], 1);
    }
    else if(count_nodes(stack[0]) == 3)
        algorithm_for_three(&stack[0]);
    else if(count_nodes(stack[0]) <= 5)
        algorithm_for_five(&stack[0]);
    else
        big_algorithm(&stack[0]);
}

int main(int argc, char **argv)
{
    t_stack **stack;
    
    if(argc <= 1)
        return(0);
    stack = malloc(sizeof(t_stack) * 2);
	if (!stack)
		return (0);
    stack[0] = init_stack(argc, argv);
    stack[1] = NULL;
    sort_algorithm(stack);
    free_stack(&stack[0]);
}
