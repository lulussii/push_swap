/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:53:06 by lserodon          #+#    #+#             */
/*   Updated: 2025/02/27 17:51:36 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_cost(t_stack *current)
{
	int	tmp;

	tmp = 0;
	if (current->sort.rr != -1)
		tmp += current->sort.rr;
	else if (current->sort.rrr != -1)
		tmp += current->sort.rrr;
	if (current->sort.ra != -1)
		tmp += current->sort.ra;
	else if (current->sort.rra != -1)
		tmp += current->sort.rra;
	if (current->sort.rb != -1)
		tmp += current->sort.rb;
	else if (current->sort.rrb != -1)
		tmp += current->sort.rrb;
	return (tmp);
}

t_stack	*node_to_push(t_stack **stack)
{
	t_stack	*to_push;
	t_stack	*current;
	int		tmp;
	int		cmp;

	current = stack[1];
	cmp = INT_MAX;
	while (current)
	{
		tmp = calculate_cost(current);
		if (tmp < cmp)
		{
			cmp = tmp;
			to_push = current;
		}
		current = current->next;
	}
	return (to_push);
}

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
	int		count;

	count = count_nodes(stack[0]);
	quarts = malloc(sizeof(t_quart));
	if (!quarts)
		return ;
	calc_quarts(quarts, stack[0]);
	while (count_nodes (stack[0]) > 3)
	{
		if (count <= 250)
			push_b(stack);
		else
			sort_to_b(stack, quarts);
	}
	if (!check_sort_a(stack[0]))
		algorithm_for_three(stack);
	while (stack[1])
		push_in_a(stack);
	set_up_a(stack);
	free(quarts);
}
