/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichtioui <ichtioui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:21:36 by ichtioui          #+#    #+#             */
/*   Updated: 2025/12/25 14:06:46 by ichtioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_node **head)
{
	t_node	*first;
	t_node	*second;

	if (!(*head) || !((*head)->next))
		return ;
	first = *head;
	second = first->next;
	first->prev = second;
	first->next = second->next;
	second->prev = NULL;
	second->next = first;
	if (first->next)
		first->next->prev = first;
	*head = second;
}

void	ft_sa(t_node **a, bool print)
{
	ft_swap(a);
	if (print)
		write(1, "sa\n", 3);
}

void	ft_sb(t_node **b, bool print)
{
	ft_swap(b);
	if (print)
		write(1, "sb\n", 3);
}

void	ft_ss(t_node **a, t_node **b, bool print)
{
	ft_swap(a);
	ft_swap(b);
	if (print)
		write(1, "ss\n", 3);
}
