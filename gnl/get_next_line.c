/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichtioui <ichtioui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 09:36:00 by ichtioui          #+#    #+#             */
/*   Updated: 2026/01/02 19:05:32 by ichtioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_read(int fd, char **stash)
{
	char	*buff;
	int		read_len;
	int		stash_len;

	read_len = 1;
	buff = malloc(BUFFER_SIZE + 1);
	buff[0] = '\0';
	if (!buff)
		return ;
	stash_len = gnl_strlen(*stash);
	while (!gnl_strchr(buff, '\n') && read_len > 0)
	{
		read_len = read(fd, buff, BUFFER_SIZE);
		if (read_len == -1)
		{
			free(buff);
			free(*stash);
			*stash = NULL;
			return ;
		}
		buff[read_len] = '\0';
		*stash = gnl_strjoin(*stash, buff, stash_len, read_len);
		stash_len += read_len;
	}
	free(buff);
}

char	*ft_replace(char *stash)
{
	char	*rep;
	int		len;
	int		i;

	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len++] == '\0')
	{
		free(stash);
		return (NULL);
	}
	i = gnl_strlen(stash);
	rep = malloc(i - len + 1);
	i = 0;
	if (!rep)
	{
		free(stash);
		return (NULL);
	}
	while (stash[len])
		rep[i++] = stash[len++];
	rep[i] = '\0';
	free(stash);
	return (rep);
}

char	*ft_get_line(char *stash)
{
	char	*line;
	int		i;
	int		len;

	i = -1;
	len = 0;
	if (stash[0] == '\0')
		return (NULL);
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	while (++i < len)
		line[i] = stash[i];
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash || !gnl_strchr(stash, '\n'))
		ft_read(fd, &stash);
	if (!stash)
		return (NULL);
	line = ft_get_line(stash);
	stash = ft_replace(stash);
	return (line);
}
