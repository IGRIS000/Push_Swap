/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichtioui <ichtioui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:21:31 by ichtioui          #+#    #+#             */
/*   Updated: 2025/12/23 11:44:59 by ichtioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rev_rot(t_node **head)
{
	t_node	*last;

	if (!*head || !(*head)->next)
		return ;
	last = *head;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->next = *head;
	(*head)->prev = last;
	last->prev = NULL;
	(*head) = last;
}

void	ft_rra(t_node **a, bool print)
{
	ft_rev_rot(a);
	if (print)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_node **b, bool print)
{
	ft_rev_rot(b);
	if (print)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_node **a, t_node **b, bool print)
{
	ft_rev_rot(a);
	ft_rev_rot(b);
	if (print)
		write(1, "rrr\n", 4);
}
