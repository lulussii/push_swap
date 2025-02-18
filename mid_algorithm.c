/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:38:01 by lserodon          #+#    #+#             */
/*   Updated: 2025/02/18 11:23:28 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_mid(t_stack *stack, int position)
{
	int	total_nodes;

	total_nodes = count_nodes(stack) / 2;
	if (position > total_nodes)
		return (1);
	return (0);
}

void	push_min_in_b(t_stack **stack)
{
	t_stack	*minimum_value;
	int		minimum_position;
	int		median;

	minimum_value = find_number_min(stack[0]);
	minimum_position = find_min_position(stack[0]);
	median = find_mid(stack[0], minimum_position);
	while (stack[0] != minimum_value)
	{
		if (median == 1)
			reverse_rotate_a(&stack[0], 1);
		else
			rotate_a(&stack[0], 1);
	}
	push_b(stack);
}

void	algorithm_for_five(t_stack **stack)
{
	push_min_in_b(stack);
	if (count_nodes(stack[0]) == 4)
		push_min_in_b(stack);
	if (!check_sort_a(stack[0]))
		algorithm_for_three(stack);
	while (stack[1])
		push_a(stack);
}
