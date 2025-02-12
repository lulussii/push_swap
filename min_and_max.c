/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_and_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:30:15 by lserodon          #+#    #+#             */
/*   Updated: 2025/02/07 11:26:34 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_number_max(t_stack *stack)
{
	t_stack	*max_value;
	
	max_value = stack;
	while (stack)
	{
		stack = (stack)->next; 
		if(stack && max_value->value < (stack->value))
			max_value = stack;
	}
	return(max_value);
}

t_stack	*find_number_min(t_stack *stack)
{
	t_stack	*min_value;
	
	min_value = stack;
	while (stack)
	{
		stack = (stack)->next; 
		if(stack && min_value->value > (stack->value))
			min_value = stack;
	}
	return(min_value);
}

int	find_min_position(t_stack *stack)
{
	int	position;
	t_stack	*min;
	
	min = find_number_min(stack);
	position = 1;
	while(stack != min)
	{
		stack = stack->next;
		position ++;
	}
	return(position);	
}

int	find_max_position(t_stack *stack)
{
	int	position;
	t_stack	*max;
	
	max = find_number_max(stack);
	position = 1;
	while(stack != max)
	{
		stack = stack->next;
		position ++;
	}
	return(position);	
}