/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichtioui <ichtioui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:21:20 by ichtioui          #+#    #+#             */
/*   Updated: 2026/01/01 18:42:54 by ichtioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_last(t_node *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

t_node	*ft_create(int a)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = a;
	node->index = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	ft_add_end(t_node **head, t_node *node)
{
	t_node	*last;

	if (!(*head))
		(*head) = node;
	else
	{
		last = ft_last(*head);
		last->next = node;
		node->prev = last;
	}
}

int	ft_stack_len(t_node *head)
{
	int	count;

	count = 0;
	if (!head)
		return (0);
	while (head)
	{
		head = head->next;
		count++;
	}
	return (count);
}

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	rslt;

	i = 0;
	sign = 1;
	rslt = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		rslt = rslt * 10 + (str[i++] - '0');
	return (rslt * sign);
}
