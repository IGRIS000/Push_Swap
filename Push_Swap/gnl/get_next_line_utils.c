/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichtioui <ichtioui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:49:25 by ichtioui          #+#    #+#             */
/*   Updated: 2025/11/20 14:33:27 by ichtioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlen(char *s)
{
	char	*i;

	if (!s)
		return (0);
	i = s;
	while (*i)
		i++;
	return (i - s);
}

char	*gnl_strjoin(char *s1, char *s2, int stash_len, int read_len)
{
	char	*new_str;
	char	*src;
	char	*ptr;

	new_str = malloc(stash_len + read_len + 1);
	if (!new_str)
	{
		free(s1);
		return (NULL);
	}
	ptr = new_str;
	if (s1)
	{
		src = s1;
		while (*src)
			*ptr++ = *src++;
	}
	src = s2;
	while (*src)
		*ptr++ = *src++;
	*ptr = '\0';
	free(s1);
	return (new_str);
}

char	*gnl_strchr(char *i, char c)
{
	if (!i)
		return (NULL);
	while (*i)
	{
		if (c == *i)
			return (i);
		i++;
	}
	if (c == *i)
		return (i);
	return (NULL);
}
