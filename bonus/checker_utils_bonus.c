/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:28:17 by lserodon          #+#    #+#             */
/*   Updated: 2025/02/28 14:27:44 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap_bonus.h"

int	count_digits(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != ' ')
		i++;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			count++;
			while (str[i] && str[i] == ' ')
				i++;
		}
		else
			i++;
	}
	if (str[i - 1] != ' ' && i > 0)
		count++;
	return (count);
}

long	*fill_digits_array(char *str, long *digits_array, t_stack **stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		digits_array[j++] = ft_atoi(&str[i]);
		if (ft_atoi(&str[i]) > INT_MAX || ft_atoi(&str[i]) < INT_MIN)
		{
			free_all(stack, digits_array, str);
			write(2, "Error\n", 6);
			exit(1);
		}
		if (str[i] == '-' || str[i] == '+')
			i++;
		while (str[i] && (str[i] >= '0' && str[i] <= '9'))
			i++;
		while (str[i] && (str[i] == ' '))
			i++;
	}
	return (digits_array);
}

long	*set_up_digits_array(char *str, t_stack **stack)
{
	long	*digits_array;

	digits_array = malloc(sizeof(long) * count_digits(str));
	if (!digits_array)
		return (NULL);
	fill_digits_array(str, digits_array, stack);
	return (digits_array);
}
