/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:57:05 by lserodon          #+#    #+#             */
/*   Updated: 2025/02/27 13:36:51 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	if (!s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen_until(s1, '\0') + ft_strlen_until(s2, '\0')
				+ 1));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	free(s1);
	return (str);
}

size_t	ft_strlen_until(char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != c && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

void	fill_stash(char *buffer, char *stash)
{
	int	i;
	int	j;

	i = 0;
	if (!buffer || !stash)
		return ;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	j = 0;
	while (buffer[i])
		stash[j++] = buffer[i++];
	while (j < BUFFER_SIZE)
		stash[j++] = '\0';
}

char	*fill_line(int fd, char *stash)
{
	int		bytes_read;
	char	*res;

	bytes_read = 1;
	res = ft_strdup(stash);
	if (!res)
		return (NULL);
	while (bytes_read != 0 && !ft_strchr(res, '\n'))
	{
		bytes_read = read(fd, stash, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			ft_bzero(stash, BUFFER_SIZE);
			free(res);
			return (NULL);
		}
		stash[bytes_read] = '\0';
		res = ft_strjoin_gnl(res, stash);
		if (!res)
			return (NULL);
		if (ft_strchr(res, '\0') && bytes_read == 0)
			break ;
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = fill_line(fd, stash);
	fill_stash(buffer, stash);
	line = ft_substr(buffer, 0, ft_strlen_until(buffer, '\n'));
	free(buffer);
	if (!ft_strlen_until(line, '\0'))
	{
		free(line);
		return (NULL);
	}
	return (line);
}
