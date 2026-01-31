/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichtioui <ichtioui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:21:40 by ichtioui          #+#    #+#             */
/*   Updated: 2026/01/03 11:15:09 by ichtioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_max_pos(t_node *stack, int *max_idx)
{
	int		max;
	int		pos;
	int		i;
	t_node	*tmp;

	if (!stack)
		return (0);
	max = -1;
	pos = 0;
	i = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index > max)
		{
			max = tmp->index;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	*max_idx = max;
	return (pos);
}

static int	ft_find_min_pos(t_node *a)
{
	int		min;
	int		pos;
	int		i;
	t_node	*tmp;

	min = a->data;
	pos = 0;
	i = 0;
	tmp = a;
	while (tmp)
	{
		if (tmp->data < min)
		{
			min = tmp->data;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

void	ft_sort_five(t_node **a, t_node **b)
{
	int	min_pos;

	while (ft_stack_len(*a) > 3)
	{
		min_pos = ft_find_min_pos(*a);
		if (min_pos <= ft_stack_len(*a) / 2)
			while (min_pos-- > 0)
				ft_ra(a, true);
		else
			while (ft_stack_len(*a) - min_pos++ > 0)
				ft_rra(a, true);
		ft_pb(b, a, true);
	}
	ft_sort_three(a);
	ft_pa(a, b, true);
	if (ft_stack_len(*b) == 1)
		ft_pa(a, b, true);
}

void	ft_sort_chunks(t_node **a, t_node **b, int len)
{
	int	i;
	int	range;

	i = 0;
	if (len <= 100)
		range = 15;
	else
		range = 35;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			ft_pb(b, a, true);
			ft_rb(b, true);
			i++;
		}
		else if ((*a)->index <= i + range)
		{
			ft_pb(b, a, true);
			i++;
		}
		else
			ft_ra(a, true);
	}
}

void	ft_sort_back(t_node **a, t_node **b)
{
	int	max_pos;
	int	max_idx;
	int	len_b;

	while (*b)
	{
		len_b = ft_stack_len(*b);
		max_pos = ft_find_max_pos(*b, &max_idx);
		if (max_pos <= len_b / 2)
			while ((*b)->index != max_idx)
				ft_rb(b, true);
		else
			while ((*b)->index != max_idx)
				ft_rrb(b, true);
		ft_pa(a, b, true);
	}
}
