/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimisation_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:56:10 by lserodon          #+#    #+#             */
/*   Updated: 2025/02/27 17:51:36 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_rr(t_stack *node)
{
	if (node->sort.ra > 0 && node->sort.rb > 0)
	{
		node->sort.rr = 0;
		if (node->sort.ra >= node->sort.rb)
		{
			while (node->sort.rb > 0)
			{
				node->sort.rr++;
				node->sort.ra--;
				node->sort.rb--;
			}
		}
		else if (node->sort.rb > node->sort.ra)
		{
			while (node->sort.ra > 0)
			{
				node->sort.rr++;
				node->sort.ra--;
				node->sort.rb--;
			}
		}
	}
	else
		node->sort.rr = -1;
}

void	fill_rrr(t_stack *node)
{
	if (node->sort.rra > 0 && node->sort.rrb > 0)
	{
		node->sort.rrr = 0;
		if (node->sort.rra >= node->sort.rrb)
		{
			while (node->sort.rrb > 0)
			{
				node->sort.rrr++;
				node->sort.rra--;
				node->sort.rrb--;
			}
		}
		else if (node->sort.rrb > node->sort.rra)
		{
			while (node->sort.rra > 0)
			{
				node->sort.rrr++;
				node->sort.rra--;
				node->sort.rrb--;
			}
		}
	}
	else
		node->sort.rrr = -1;
}
