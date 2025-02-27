/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:47:56 by lserodon          #+#    #+#             */
/*   Updated: 2025/02/27 17:51:36 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*check_args(int argc, char **argv)
{
	int		i;
	char	*str;

	str = NULL;
	i = 1;
	if (argc > 2)
	{
		while (i < argc)
			str = ft_strjoin(str, argv[i++]);
	}
	else
		str = ft_strdup(argv[1]);
	return (str);
}

int	check_dups(long *array, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (i < count_digits(str))
	{
		j = i + 1;
		while (j < count_digits(str))
		{
			if (array[i] == array[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_errors(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && ((str[i]) != '-'
				&& str[i] != '+'))
			return (0);
		else if ((str[i] == '-' || str[i] == '+') && !ft_isdigit(str[i + 1]))
			return (0);
		else if (i > 0 && (str[i] == '-' || str[i] == '+') && str[i - 1] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack)
	{
		free(stack);
		return ;
	}
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	free(stack);
}

void	free_all(t_stack **big_stack, long *array, char *str)
{
	if (big_stack)
		free(big_stack);
	if (array)
		free(array);
	if (str)
		free(str);
}
