/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:07:55 by lserodon          #+#    #+#             */
/*   Updated: 2025/03/02 15:05:50 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_digits(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str[i])
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

int	count_nodes(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	sort_algorithm(t_stack **stack)
{
	if (count_nodes(stack[0]) == 2)
	{
		if (!check_sort_a(stack[0]))
			swap_a(&stack[0], 1);
	}
	else if (count_nodes(stack[0]) == 3)
		algorithm_for_three(&stack[0]);
	else if (count_nodes(stack[0]) <= 5)
		algorithm_for_five(&stack[0]);
	else
		big_algorithm(&stack[0]);
}

int	main(int argc, char **argv)
{
	t_stack	**stack;

	if (argc <= 1)
		return (0);
	stack = malloc(sizeof(t_stack) * 2);
	if (!stack)
		return (0);
	stack[0] = init_stack(argc, argv, stack);
	stack[1] = NULL;
	if (!check_sort_a(stack[0]))
		sort_algorithm(stack);
	free_stack(stack);
}
