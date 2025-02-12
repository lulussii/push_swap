/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:35:30 by lserodon          #+#    #+#             */
/*   Updated: 2025/02/12 16:29:13 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack[1])
		return ;
	tmp = stack[1];
	stack[1] = stack[1]->next;
	tmp->next = stack[0];
	stack[0] = tmp;
	write(1, "pa\n", 3);
}

void	push_b(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack[0])
		return ;
	tmp = stack[0];
	stack[0] = stack[0]->next;
	tmp->next = stack[1];
	stack[1] = tmp;
	write(1, "pb\n", 3);
}

