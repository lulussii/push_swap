/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:53:06 by lserodon          #+#    #+#             */
/*   Updated: 2025/02/12 18:59:28 by lserodon         ###   ########.fr       */
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
		if (stack->value > quarts->q1 && stack->value < quarts->q3)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	sort_to_b(t_stack **stack, t_quart *quarts)
{
	int check;

	check = check_quarts(quarts, stack[0]);
	
	if (stack[0]->value < quarts->q1 || stack[0]->value > quarts->q3)
		rotate_a(&stack[0], 1);
	else if (stack[0]->value >= quarts->q1 && stack[0]->value <= quarts->median)
	{
		push_b(stack);
		rotate_b(&stack[1], 1);
	}
	else if (stack[0]->value <= quarts->q3 && stack[0]->value >= quarts->median)
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

int	find_node_place(t_stack *stack, t_stack *node)
{
	int	i;
	int	res;
	int	len;

	i = 0;
	res = 0;
	len = count_nodes(stack);
	if (node->value > find_number_max(stack)->value || node->value < 
	find_number_min(stack)->value)
		res = find_max_position(stack) + 1;
	else 
	{
		while(stack)
		{
			i++;
			if(stack->value < node->value)
				res = i;
			stack = stack->next;
		}
	}
	if (i > len / 2)
		res = i - len;
	else
		res = i;
	return (res);
}

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
	else if (stack_a->value > stack_b->value && ft_lstlast(stack_a)->value < stack_b->value)
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
		if (current->sort.ra < 0 && current->sort.rb < 0)
			tmp = current->sort.rra + current->sort.rrb;
		else if (current->sort.rra < 0 && current->sort.rb < 0)
			tmp = current->sort.ra + current->sort.rrb;
		else if (current->sort.ra < 0 && current->sort.rrb < 0)
			tmp = current->sort.rra + current->sort.rb;
		else if (current->sort.rra < 0 && current->sort.rrb < 0)
			tmp = current->sort.ra + current->sort.rb;
		if(tmp < cmp || cmp == -1)
		{
			cmp = tmp;
			to_push = current;	
		}
		current = current->next;
	}
	return(to_push);
}

void	rotate_in_a(t_stack **stack, t_stack *to_push)
{
	int	rotate;
	int	direction;

	rotate = 0;
	direction = 1;	
	if(to_push->sort.ra < 0)
	{
		rotate = to_push->sort.rra;
		direction = -1;
	}
	else if(to_push->sort.rra < 0)
		rotate = to_push->sort.ra;
	while(rotate)
	{
		if(direction == 1)
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
	if(to_push->sort.rb < 0)
	{
		rotate = to_push->sort.rrb;
		direction = -1;
	}
	else if(to_push->sort.rrb < 0)
		rotate = to_push->sort.rb;
	while(rotate)
	{
		if(direction == 1)
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
	rotate_in_a(stack, to_push);
	rotate_in_b(stack, to_push);
	push_a(stack);
}

void	push_maximum(t_stack **stack)
{
	int	len;

	len = find_max_position(stack[1]) - 1;
	while(len)
		{
			rotate_b(&stack[1], 1);
			len--;
		}
	push_a(stack);
}

void	set_up_a(t_stack **stack)
{
	t_stack *min;

	min = find_number_min(stack[0]);
	while(stack[0] != min)
		rotate_a(&stack[0], 1);
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
	while(stack[1])
		push_in_a(stack);
	set_up_a(stack);
}
