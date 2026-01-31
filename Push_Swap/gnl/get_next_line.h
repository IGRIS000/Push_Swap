/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichtioui <ichtioui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:08:35 by ichtioui          #+#    #+#             */
/*   Updated: 2025/11/20 14:29:32 by ichtioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
void	ft_read(int fd, char **stash);
char	*ft_replace(char *stash);
char	*ft_get_line(char *stash);
char	*gnl_strjoin( char *s1, char *s2, int stash_len, int read_len);
char	*gnl_strchr(char *i, char c);
int		gnl_strlen(char *s);

#endif
