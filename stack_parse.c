/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichtioui <ichtioui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 11:14:19 by ichtioui          #+#    #+#             */
/*   Updated: 2026/01/03 11:51:29 by ichtioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_word(const char *s, char c)
{
	int	i;
	int	words;
	int	flag;

	flag = 0;
	i = -1;
	words = 0;
	while (s[++i])
	{
		if (s[i] == c)
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			words++;
		}
	}
	return (words);
}

static char	*ft_get_next_word(char	**s, char c)
{
	char	*word;
	int		len;
	int		i;
	char	*start;

	i = 0;
	len = 0;
	while (**s && **s == c)
		(*s)++;
	start = *s;
	while (**s && **s != c)
	{
		(*s)++;
		len++;
	}
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	while (i < len)
		word[i++] = *start++;
	word[i] = '\0';
	return (word);
}

void	*ft_free_split(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	int		words;
	char	**rtn;
	char	*ptr;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	words = ft_count_word(s, c);
	rtn = malloc(sizeof(char *) * (words + 1));
	if (!rtn)
		return (NULL);
	ptr = s;
	while (i < words)
	{
		rtn[i] = ft_get_next_word(&ptr, c);
		if (!rtn[i++])
			return (ft_free_split(rtn));
	}
	rtn[i] = NULL;
	return (rtn);
}

int	stack_parse(t_node **head, char *str)
{
	int		i;
	long	nbr;
	char	**argv;

	argv = ft_split(str, ' ');
	if (!argv || !argv[0])
		return (ft_free_split(argv), 0);
	i = -1;
	while (argv[++i])
	{
		if (ft_syntax_err(argv[i]))
			return (ft_free_split(argv), 0);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN || ft_duplicate(*head, (int)nbr))
			return (ft_free_split(argv), 0);
		ft_add_end(head, ft_create((int)nbr));
	}
	ft_free_split(argv);
	return (1);
}
