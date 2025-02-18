/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:26:53 by lserodon          #+#    #+#             */
/*   Updated: 2025/02/18 14:20:47 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_quarts(t_quart *quarts, t_stack *stack)
{
	quarts->q1 = find_number_max(stack)->value * 0.25;
	quarts->median = find_number_max(stack)->value * 0.5;
	quarts->q3 = find_number_max(stack)->value * 0.75;
}

int	check_quarts(t_quart *quarts, t_stack *stack)
{
	while (stack)
	{
		if (stack->value >= quarts->q1 && stack->value <= quarts->q3)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	sort_to_b(t_stack **stack, t_quart *quarts)
{
	int	check;

	check = check_quarts(quarts, stack[0]);
	if (stack[0]->value < quarts->q1 || stack[0]->value > quarts->q3)
		rotate_a(&stack[0], 1);
	else if (stack[0]->value >= quarts->q1 && stack[0]->value <= quarts->median)
	{
		push_b(stack);
		rotate_b(&stack[1], 1);
	}
	else if (stack[0]->value <= quarts->q3 && stack[0]->value > quarts->median)
		push_b(stack);
	if (!check)
	{
		if (stack[0]->value < quarts->q1)
		{
			push_b(stack);
			rotate_b(&stack[1], 1);
		}
		else if (stack[0]->value > quarts->q3)
			push_b(stack);
	}
}

void	push_maximum(t_stack **stack)
{
	int	len;

	len = find_max_position(stack[1]) - 1;
	while (len)
	{
		rotate_b(&stack[1], 1);
		len--;
	}
	push_a(stack);
}
