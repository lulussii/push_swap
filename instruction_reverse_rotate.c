/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_reverse_rotate.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:35:28 by lserodon          #+#    #+#             */
/*   Updated: 2025/01/24 15:38:19 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack **stack, int bool)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next && (tmp->next)->next)
		tmp = tmp->next;
	current = tmp->next;
	tmp->next = NULL;
	current->next = *stack;
	*stack = current;
	if (bool)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack **stack, int bool)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next && (tmp->next)->next)
		tmp = tmp->next;
	current = tmp->next;
	tmp->next = NULL;
	current->next = *stack;
	*stack = current;
	if (bool)
		write(1, "rrb\n", 4);
}

void	reverse_rotate_r(t_stack **stack)
{
	reverse_rotate_a(&stack[0], 0);
	reverse_rotate_b(&stack[1], 0);
	write(1, "rrr\n", 4);
}
