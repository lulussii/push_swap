/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:15:51 by lserodon          #+#    #+#             */
/*   Updated: 2025/02/18 11:22:44 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_ra(t_stack **stack, t_stack *node)
{
	int	rotate;

	rotate = count_rotate_a(stack[0], node);
	if (rotate < 0)
		node->sort.ra = -1;
	else
		node->sort.ra = rotate;
}

void	fill_rra(t_stack **stack, t_stack *node)
{
	int	rotate;

	rotate = count_rotate_a(stack[0], node);
	if (rotate > 0)
		node->sort.rra = -1;
	else
		node->sort.rra = rotate * -1;
}

void	fill_rb(t_stack **stack, t_stack *node)
{
	int	rotate;

	rotate = find_node_place(stack[1], node);
	if (rotate < 0)
		node->sort.rb = -1;
	else
		node->sort.rb = rotate - 1;
}

void	fill_rrb(t_stack **stack, t_stack *node)
{
	int	rotate;

	rotate = find_node_place(stack[1], node);
	if (rotate > 0)
		node->sort.rrb = -1;
	else
		node->sort.rrb = (rotate * -1) + 1;
}

void	fill_structure(t_stack **stack)
{
	t_stack	*stack_b;

	stack_b = stack[1];
	while (stack_b)
	{
		fill_ra(stack, stack_b);
		fill_rb(stack, stack_b);
		fill_rra(stack, stack_b);
		fill_rrb(stack, stack_b);
		stack_b = stack_b->next;
	}
}
