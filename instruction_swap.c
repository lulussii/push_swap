/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:35:34 by lserodon          #+#    #+#             */
/*   Updated: 2025/01/27 15:56:11 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **stack, int bool)
{
	int		tmp_value;
	t_stack	*head;
	t_stack	*next;

	if (!*stack || !(*stack)->next)
		return ;
	head = *stack;
	next = (head)->next;
	tmp_value = head->value;
	head->value = next->value;
	next->value = tmp_value;
	if (bool)
		write(1, "sa\n", 3);
}

void	swap_b(t_stack **stack, int bool)
{
	int		tmp_value;
	t_stack	*head;
	t_stack	*next;

	if (!*stack || !(*stack)->next)
		return ;
	head = *stack;
	next = (head)->next;
	tmp_value = head->value;
	head->value = next->value;
	next->value = tmp_value;
	if (bool)
		write(1, "sb\n", 3);
}

void	swap_s(t_stack **stack)
{
	swap_a(&stack[0], 0);
	swap_b(&stack[1], 0);
	write(1, "ss\n", 3);
}
