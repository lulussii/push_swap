/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:33:08 by lserodon          #+#    #+#             */
/*   Updated: 2025/02/28 14:28:11 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap_bonus.h"

void	rotate_a(t_stack **stack, int bool)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	current = *stack;
	while (current->next)
		current = current->next;
	current->next = tmp;
	if (bool)
		write(1, "ra\n", 3);
}

void	rotate_b(t_stack **stack, int bool)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	current = *stack;
	while (current->next)
		current = current->next;
	current->next = tmp;
	if (bool)
		write(1, "rb\n", 3);
}

void	rotate_r(t_stack **stack, int bool)
{
	rotate_a(&stack[0], 0);
	rotate_b(&stack[1], 0);
	if (bool)
		write(1, "rr\n", 3);
}
