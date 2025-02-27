/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm_utils_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:29:44 by lserodon          #+#    #+#             */
/*   Updated: 2025/02/27 17:51:36 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_rotate_a(t_stack *a, t_stack *b)
{
	int	len;
	int	i;
	int	res;

	i = 0;
	res = 0;
	len = count_nodes(a);
	if ((b->value < find_number_min(a)->value)
		|| (b->value > find_number_max(a)->value))
		res = find_max_position(a);
	else if (a->value > b->value
		&& ft_lstlast(a)->value < b->value)
		return (0);
	while (a->next && !res)
	{
		i++;
		if (a->value < b->value && (a->next)->value > b->value)
			res = i;
		a = a->next;
	}
	if (!a->next && !res)
		return (-1);
	if (res > len / 2)
		return (res - len);
	return (res);
}

void	rotate_rr_or_rrr(t_stack **stack, t_stack *to_push)
{
	int	rotate;
	int	direction;

	rotate = 0;
	direction = 1;
	if (to_push->sort.rr > 0)
		rotate = to_push->sort.rr;
	else if (to_push->sort.rrr > 0)
	{
		rotate = to_push->sort.rrr;
		direction = -1;
	}
	while (rotate)
	{
		if (direction == 1)
			rotate_r(stack);
		else
			reverse_rotate_r(stack);
		rotate--;
	}
}

void	rotate_in_a(t_stack **stack, t_stack *to_push)
{
	int	rotate;
	int	direction;

	rotate = 0;
	direction = 1;
	if (to_push->sort.ra < 0)
	{
		rotate = to_push->sort.rra;
		direction = -1;
	}
	else if (to_push->sort.rra < 0)
		rotate = to_push->sort.ra;
	while (rotate)
	{
		if (direction == 1)
			rotate_a(&stack[0], 1);
		else
			reverse_rotate_a(&stack[0], 1);
		rotate--;
	}
}

void	rotate_in_b(t_stack **stack, t_stack *to_push)
{
	int	rotate;
	int	direction;

	rotate = 0;
	direction = 1;
	if (to_push->sort.rb < 0)
	{
		rotate = to_push->sort.rrb;
		direction = -1;
	}
	else if (to_push->sort.rrb < 0)
		rotate = to_push->sort.rb;
	while (rotate)
	{
		if (direction == 1)
			rotate_b(&stack[1], 1);
		else
			reverse_rotate_b(&stack[1], 1);
		rotate--;
	}
}

void	push_in_a(t_stack **stack)
{
	t_stack	*to_push;

	fill_structure(stack);
	to_push = node_to_push(stack);
	rotate_rr_or_rrr(stack, to_push);
	rotate_in_a(stack, to_push);
	rotate_in_b(stack, to_push);
	push_a(stack);
}
