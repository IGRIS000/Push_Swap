/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichtioui <ichtioui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:21:34 by ichtioui          #+#    #+#             */
/*   Updated: 2025/12/23 11:44:45 by ichtioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_node **head)
{
	t_node	*first;
	t_node	*last;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	last = *head;
	while (last->next)
		last = last->next;
	*head = first->next;
	(*head)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ft_ra(t_node **a, bool print)
{
	ft_rotate(a);
	if (print)
		write(1, "ra\n", 3);
}

void	ft_rb(t_node **b, bool print)
{
	ft_rotate(b);
	if (print)
		write(1, "rb\n", 3);
}

void	ft_rr(t_node **a, t_node **b, bool print)
{
	ft_rotate(a);
	ft_rotate(b);
	if (print)
		write(1, "rr\n", 3);
}
