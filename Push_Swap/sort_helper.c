/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichtioui <ichtioui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 14:36:54 by ichtioui          #+#    #+#             */
/*   Updated: 2026/01/03 12:46:28 by ichtioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*ft_biggest(t_node *a)
{
	t_node	*biggest;
	int		big;

	biggest = a;
	big = a->data;
	while (a)
	{
		if (a->data > big)
		{
			big = a->data;
			biggest = a;
		}
		a = a->next;
	}
	return (biggest);
}

void	ft_sort_three(t_node **head)
{
	t_node	*biggest;

	if (!(*head)->next)
		return ;
	biggest = ft_biggest(*head);
	if (*head == biggest)
		ft_ra(head, true);
	else if ((*head)->next == biggest)
		ft_rra(head, true);
	if ((*head)->data > (*head)->next->data)
		ft_sa(head, true);
}

int	ft_check(t_node *a)
{
	while (a->next)
	{
		if (a->data > a->next->data)
			return (1);
		a = a->next;
	}
	return (0);
}

void	ft_index(t_node *head)
{
	int		count;
	t_node	*current;
	t_node	*tmp;

	current = head;
	while (current)
	{
		count = 0;
		tmp = head;
		while (tmp)
		{
			if (tmp->data < current->data)
				count++;
			tmp = tmp->next;
		}
		current->index = count;
		current = current->next;
	}
}
