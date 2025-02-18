/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:51:08 by lserodon          #+#    #+#             */
/*   Updated: 2025/02/18 11:22:03 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm_for_three(t_stack **stack)
{
	int	nb_one;
	int	nb_two;
	int	nb_three;

	nb_one = stack[0]->value;
	nb_two = ((stack[0])->next)->value;
	nb_three = (((stack[0])->next)->next)->value;
	if (nb_one < nb_two && nb_one < nb_three && nb_two > nb_three)
	{
		swap_a(&stack[0], 1);
		rotate_a(&stack[0], 1);
	}
	if (nb_one > nb_two && nb_two > nb_three)
	{
		rotate_a(&stack[0], 1);
		swap_a(&stack[0], 1);
	}
	else if (nb_one > nb_two && nb_one > nb_three)
		rotate_a(&stack[0], 1);
	else if (nb_one > nb_two && nb_two < nb_three)
		swap_a(&stack[0], 1);
	else if (nb_one < nb_two && nb_one > nb_three)
		reverse_rotate_a(&stack[0], 1);
}
