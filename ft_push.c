/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichtioui <ichtioui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:21:27 by ichtioui          #+#    #+#             */
/*   Updated: 2025/12/23 11:45:28 by ichtioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_node **a, t_node **b)
{
	t_node	*node_pushed;

	if (!(*b))
		return ;
	node_pushed = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	node_pushed->prev = NULL;
	if (!*a)
	{
		*a = node_pushed;
		node_pushed->next = NULL;
	}
	else
	{
		node_pushed->next = *a;
		node_pushed->next->prev = node_pushed;
		*a = node_pushed;
	}
}

void	ft_pa(t_node **a, t_node **b, bool print)
{
	ft_push(a, b);
	if (print)
		write(1, "pa\n", 3);
}

void	ft_pb(t_node **b, t_node **a, bool print)
{
	ft_push(b, a);
	if (print)
		write(1, "pb\n", 3);
}
