/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:47:56 by lserodon          #+#    #+#             */
/*   Updated: 2025/02/12 15:51:40 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

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

int     check_dups(long *array, char *str)
{
    int i;
    int j;

    i = 0;
    while(i < count_digits(str))
    {
        j = i + 1;
        while (j < count_digits(str))
            {
                if(array[i] == array[j])
                    return(0);
                j++;
            }
        i++;
    }
    return(1);
}

void    free_all(t_stack *stack, long *array, char *str)
{
    if(stack)
        free(stack);
    if(array)
        free(array);
    if(str)
        free(str);
}