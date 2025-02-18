/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:53:06 by lserodon          #+#    #+#             */
/*   Updated: 2025/02/18 14:20:45 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_node_place(t_stack *stack, t_stack *node)
{
	int	i;
	int	res;
	int	len;

	i = 0;
	res = 0;
	len = count_nodes(stack);
	if (node->value > find_number_max(stack)->value
		|| node->value < find_number_min(stack)->value)
		res = find_max_position(stack) + 1;
	else
	{
		while (stack)
		{
			i++;
			if (stack->value == node->value)
				res = i;
			stack = stack->next;
		}
	}
	if (res > len / 2)
		res -= len;
	return (res);
}

void	set_up_a(t_stack **stack)
{
	int		min;
	t_stack	*min_node;

	min_node = find_number_min(stack[0]);
	min = find_min_position(stack[0]);
	while (stack[0] != min_node)
	{
		if (min > count_nodes(stack[0]) / 2)
			reverse_rotate_a(&stack[0], 1);
		else
			rotate_a(&stack[0], 1);
	}
}

void	big_algorithm(t_stack **stack)
{
	t_quart	*quarts;

	quarts = malloc(sizeof(t_quart));
	if (!quarts)
		return ;
	calc_quarts(quarts, stack[0]);
	while (count_nodes(stack[0]) > 3)
		sort_to_b(stack, quarts);
	if (!check_sort_a(stack[0]))
		algorithm_for_three(stack);
	if (find_number_max(stack[0])->value < find_number_max(stack[1])->value)
	{
		push_maximum(stack);
		rotate_a(&stack[0], 1);
	}
	while (stack[1])
		push_in_a(stack);
	set_up_a(stack);
	free(quarts);
}
