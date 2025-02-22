/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:15:51 by lserodon          #+#    #+#             */
/*   Updated: 2025/02/22 17:39:52 by lserodon         ###   ########.fr       */
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

void	fill_rr(t_stack *node)
{
	if (node->sort.ra > 0 && node->sort.rb > 0)
	{	
		node->sort.rr = 0;
		if(node->sort.ra >= node->sort.rb)
		{
			while(node->sort.rrb > 0)
			{
				node->sort.rr++;
				node->sort.ra--;
				node->sort.rb--;
			}		
		}
		else if(node->sort.rb > node->sort.ra)
		{
			while(node->sort.ra > 0 )
			{
				node->sort.rr++;
				node->sort.ra--;
				node->sort.rb--;
			}
		}
	}
	else
		node->sort.rr = 0;
}

void	fill_rrr(t_stack * node)
{
	if (node->sort.rra > 0 && node->sort.rrb > 0)
	{
		node->sort.rrr = 0;
		if(node->sort.rra >= node->sort.rrb)
		{
			while(node->sort.rrb  > 0)
			{
				node->sort.rrr++;
				node->sort.rra--;
				node->sort.rrb--;
			}		
		}
		else if(node->sort.rrb > node->sort.rra)
		{
			while(node->sort.rra > 0)
			{
				node->sort.rrr++;
				node->sort.rra--;
				node->sort.rrb--;
			}
		}
	}
	else
		node->sort.rrr = 0;
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
		fill_rr(stack_b);
		fill_rrr(stack_b);
		stack_b = stack_b->next;
	}
}
