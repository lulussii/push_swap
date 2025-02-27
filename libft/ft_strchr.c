/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 08:59:15 by lserodon          #+#    #+#             */
/*   Updated: 2025/02/27 12:49:18 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	tmp_c;

	i = 0;
	tmp_c = (char)c;
	while (s[i])
	{
		if (s[i] == tmp_c)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == tmp_c)
		return ((char *) &s[i]);
	return (0);
}
