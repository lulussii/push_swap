/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm_utils_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:29:44 by lserodon          #+#    #+#             */
/*   Updated: 2025/02/22 17:44:25 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_rotate_a(t_stack *stack_a, t_stack *stack_b)
{
	int	len;
	int	i;
	int	res;

	i = 0;
	res = 0;
	len = count_nodes(stack_a);
	if (stack_b->value < find_number_min(stack_a)->value)
		res = find_max_position(stack_a);
	else if (stack_a->value > stack_b->value
		&& ft_lstlast(stack_a)->value < stack_b->value)
		return (0);
	while (stack_a->next && !res)
	{
		i++;
		if (stack_a->value < stack_b->value
			&& (stack_a->next)->value > stack_b->value)
			res = i;
		stack_a = stack_a->next;
	}
	if (!stack_a->next && !res)
		return (-1);
	if (res > len / 2)
		return (res - len);
	return (res);
}

t_stack	*node_to_push(t_stack **stack)
{
	t_stack	*to_push;
	t_stack	*current;
	int		tmp;
	int		cmp;

	current = stack[1];
	cmp = -1;
	while (current)
	{
		if (current->sort.ra <= 0 && current->sort.rb <= 0)
			tmp = current->sort.rrr + current->sort.rra + current->sort.rrb;
		else if (current->sort.rra <= 0 && current->sort.rb <= 0)
			tmp = current->sort.ra + current->sort.rrb;
		else if (current->sort.ra <= 0 && current->sort.rrb <= 0)
			tmp = current->sort.rra + current->sort.rb;
		else if (current->sort.rra <= 0 && current->sort.rrb <= 0)
			tmp = current->sort.rr + current->sort.ra + current->sort.rb;
		if (cmp == -1 || tmp < cmp)
		{
			cmp = tmp;
			to_push = current;
		}
		current = current->next;
	}
	return (to_push);
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
