/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:07:53 by lserodon          #+#    #+#             */
/*   Updated: 2025/02/27 13:26:06 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <ctype.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct quartiles
{
	int	q1;
	int	median;
	int	q3;
}		t_quart;

/* ----- BIG_ALGORITHM_UTILS ----- */

int		check_quarts(t_quart *quarts, t_stack *stack);
int		count_rotate_a(t_stack *a, t_stack *b);
void	calc_quarts(t_quart *quarts, t_stack *stack);
void	push_in_a(t_stack **stack);
void	push_maximum(t_stack **stack);
void	rotate_in_a(t_stack **stack, t_stack *to_push);
void	rotate_in_b(t_stack **stack, t_stack *to_push);
void	rotate_rr_or_rrr(t_stack **stack, t_stack *to_push);
void	sort_to_b(t_stack **stack, t_quart *quarts);
void	big_algorithm(t_stack **stack);
void	set_up_a(t_stack **stack);
int		find_node_place(t_stack *stack, t_stack *node);
t_stack	*node_to_push(t_stack **stack);
int		calculate_cost(t_stack *current);

/* ----- CHECK_ERRORS ----- */

char	*check_args(int argc, char **argv);
int		check_dups(long *array, char *str);
int		check_errors(char *str);
void	free_all(t_stack **big_stack, long *array, char *str);
void	free_stack(t_stack **stack);

/* ----- INITIALISATION_STACK ----- */

t_stack	*new_node(int value);
t_stack	*add_to_stack_a(long *digits_array, char *str);
t_stack	*init_stack(int argc, char **argv, t_stack **stack);

/* ----- INSTRUCTIONS */

void	push_a(t_stack **stack);
void	push_b(t_stack **stack);
void	reverse_rotate_a(t_stack **stack, int bool);
void	reverse_rotate_b(t_stack **stack, int bool);
void	reverse_rotate_r(t_stack **stack);
void	rotate_a(t_stack **stack, int bool);
void	rotate_b(t_stack **stack, int bool);
void	rotate_r(t_stack **stack);
void	swap_a(t_stack **stack, int bool);
void	swap_b(t_stack **stack, int bool);
void	swap_s(t_stack **stack);

/* ----- MAIN ----- */

int		count_digits(char *str);
int		check_sort_a(t_stack *stack_a);
int		count_nodes(t_stack *stack);
void	sort_algorithm(t_stack **stack);

/* ----- MID_ALGORITHM ----- */

int		find_mid(t_stack *stack, int position);
void	push_min_in_b(t_stack **stack);
void	algorithm_for_five(t_stack **stack);

/* ----- MIN_AND_MAX ----- */

t_stack	*find_number_max(t_stack *stack);
t_stack	*find_number_min(t_stack *stack);
int		find_min_position(t_stack *stack);
int		find_max_position(t_stack *stack);

/* ----- OPTIMISATION ------ */

void	fill_ra(t_stack **stack, t_stack *node);
void	fill_rra(t_stack **stack, t_stack *node);
void	fill_rb(t_stack **stack, t_stack *node);
void	fill_rrb(t_stack **stack, t_stack *node);
void	fill_rr(t_stack *node);
void	fill_rrr(t_stack *node);
void	fill_structure(t_stack **stack);

/* ----- SETUP_DIGIT_ARRAY ----- */

long	*fill_digits_array(char *str, long *digits_array, t_stack **stack);
long	*set_up_digits_array(char *str, t_stack **stack);

/* ----- SMALL_ALGORITHM ----- */

void	algorithm_for_three(t_stack **stack);

#endif