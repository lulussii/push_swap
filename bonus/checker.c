/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:16:28 by lserodon          #+#    #+#             */
/*   Updated: 2025/02/28 14:10:36 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"

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

void	print_error(t_stack **stack, char *line)
{
	write(2, "Error\n", 6);
	free_stack(stack);
	free(line);
	exit(1);
}

void	execute_instructions(t_stack **stack, char *line)
{
	if (!ft_strncmp(line, "sa\n", 4))
		swap_a(&stack[0], 0);
	else if (!ft_strncmp(line, "sb\n", 4))
		swap_b(&stack[1], 0);
	else if (!ft_strncmp(line, "ss\n", 4))
		swap_s(stack, 0);
	else if (!ft_strncmp(line, "pa\n", 4))
		push_a(stack, 0);
	else if (!ft_strncmp(line, "pb\n", 4))
		push_b(stack, 0);
	else if (!ft_strncmp(line, "ra\n", 4))
		rotate_a(&stack[0], 0);
	else if (!ft_strncmp(line, "rb\n", 4))
		rotate_b(&stack[1], 0);
	else if (!ft_strncmp(line, "rr\n", 4))
		rotate_r(stack, 0);
	else if (!ft_strncmp(line, "rra\n", 4))
		reverse_rotate_a(&stack[0], 0);
	else if (!ft_strncmp(line, "rrb\n", 4))
		reverse_rotate_b(&stack[1], 0);
	else if (!ft_strncmp(line, "rrr\n", 4))
		reverse_rotate_r(stack, 0);
	else
		print_error(stack, line);
}

void	check_instructions(t_stack **stack)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		execute_instructions(stack, line);
		free(line);
		line = get_next_line(0);
	}
	if (!check_sort_a(stack[0]) || stack[1] != NULL)
	{
		write(2, "KO\n", 3);
		free_stack(stack);
		exit(1);
	}
	else
		write(1, "OK\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	**stack;

	if (argc <= 1)
		return (0);
	stack = malloc(sizeof(t_stack) * 2);
	if (!stack)
		return (0);
	stack[0] = init_stack(argc, argv, stack);
	stack[1] = NULL;
	check_instructions(stack);
	free_stack(stack);
}
