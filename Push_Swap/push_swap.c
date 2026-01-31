/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psuh_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichtioui <ichtioui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 11:23:47 by ichtioui          #+#    #+#             */
/*   Updated: 2026/01/03 11:23:50 by ichtioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort(t_node **a, t_node **b)
{
	int	len;

	len = ft_stack_len(*a);
	if (len <= 3)
		ft_sort_three(a);
	else if (len <= 5)
		ft_sort_five(a, b);
	else
	{
		ft_index(*a);
		ft_sort_chunks(a, b, ft_stack_len(*a));
		ft_sort_back(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		i;

	b = NULL;
	a = NULL;
	i = 0;
	if (argc < 2)
		return (0);
	if (!argv[1][0])
		return (write(2, "Error\n", 6), 1);
	while (argv[++i])
		if (!stack_parse(&a, argv[i]))
			return (ft_free(&a), write(2, "Error\n", 6), 1);
	if (ft_check(a))
		ft_sort(&a, &b);
	ft_free(&a);
	return (0);
}
