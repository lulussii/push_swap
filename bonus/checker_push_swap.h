/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_push_swap.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:12:51 by lserodon          #+#    #+#             */
/*   Updated: 2025/02/27 18:05:10 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_PUSH_SWAP_H
# define CHECKER_PUSH_SWAP_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

/* ----- INITIALISATION_STACK ----- */

t_stack	*new_node(int value);
t_stack	*add_to_stack_a(long *digits_array, char *str);
t_stack	*init_stack(int argc, char **argv, t_stack **stack);

/* ----- CHECKER_ERRORS ----- */

char	*check_args(int argc, char **argv);
int		check_sort_a(t_stack *stack_a);
void	free_all(t_stack **big_stack, long *array, char *str);
int		check_errors(char *str);
int		check_dups(long *array, char *str);

/* ----- CHECKER_UTILS ----- */

int		count_digits(char *str);
int		count_digits(char *str);
long	*set_up_digits_array(char *str, t_stack **stack);
long	*fill_digits_array(char *str, long *digits_array, t_stack **stack);

/* ----- INSTRUCTIONS ----- */

void	push_a(t_stack **stack, int bool);
void	push_b(t_stack **stack, int bool);
void	reverse_rotate_a(t_stack **stack, int bool);
void	reverse_rotate_b(t_stack **stack, int bool);
void	reverse_rotate_r(t_stack **stack, int bool);
void	rotate_a(t_stack **stack, int bool);
void	rotate_b(t_stack **stack, int bool);
void	rotate_r(t_stack **stack, int bool);
void	swap_a(t_stack **stack, int bool);
void	swap_b(t_stack **stack, int bool);
void	swap_s(t_stack **stack, int bool);

#endif