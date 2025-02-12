/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:47:29 by lserodon          #+#    #+#             */
/*   Updated: 2025/02/12 15:57:51 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

t_stack *add_to_stack_a(long *digits_array, char *str)
{
    int i;
    t_stack *node;
    t_stack *stack_a;

    i = 0;
    stack_a = NULL;
    while(i < count_digits(str))
    {
        node = new_node(digits_array[i]);
        if(!node)
            return (NULL);
        ft_lstadd_back(&stack_a, node);
        i++; 
    }
    free_all(NULL, digits_array, str);
    return(stack_a);
}

t_stack *init_stack(int argc, char **argv)
{
    long    *digits_array;
    char    *str;
    t_stack *stack_a = NULL;
    
    str = check_args(argc, argv);
    digits_array = set_up_digits_array(str);
    if(!check_dups(digits_array, str))
        {
            free_all(stack_a, digits_array, str);
            write(2, "Error\n", 6);
            exit(1);
        }
    stack_a = add_to_stack_a(digits_array, str);
    print_stack(stack_a);
    return (stack_a);
}