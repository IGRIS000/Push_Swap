/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichtioui <ichtioui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:36:18 by ichtioui          #+#    #+#             */
/*   Updated: 2026/01/03 10:59:15 by ichtioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

static void	ft_bonus_free(t_node **a, t_node **b, char *s)
{
	ft_free(a);
	ft_free(b);
	free(s);
	write(2, "Error\n", 6);
	exit(1);
}

static void	ft_exec(t_node **a, t_node **b, char *s)
{
	if (!ft_strcmp(s, "sa\n"))
		ft_sa(a, false);
	else if (!ft_strcmp(s, "sb\n"))
		ft_sb(b, false);
	else if (!ft_strcmp(s, "ss\n"))
		ft_ss(a, b, false);
	else if (!ft_strcmp(s, "pa\n"))
		ft_pa(a, b, false);
	else if (!ft_strcmp(s, "pb\n"))
		ft_pb(b, a, false);
	else if (!ft_strcmp(s, "ra\n"))
		ft_ra(a, false);
	else if (!ft_strcmp(s, "rb\n"))
		ft_rb(b, false);
	else if (!ft_strcmp(s, "rr\n"))
		ft_rr(a, b, false);
	else if (!ft_strcmp(s, "rra\n"))
		ft_rra(a, false);
	else if (!ft_strcmp(s, "rrb\n"))
		ft_rrb(b, false);
	else if (!ft_strcmp(s, "rrr\n"))
		ft_rrr(a, b, false);
	else
		ft_bonus_free(a, b, s);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		i;
	char	*line;

	i = 0;
	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	while (argv[++i])
		if (!stack_parse(&a, argv[i]))
			return (ft_free(&a), write(2, "Error\n", 6), 1);
	line = get_next_line(0);
	while (line)
	{
		ft_exec(&a, &b, line);
		free(line);
		line = get_next_line(0);
	}
	if (!ft_check(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (ft_free(&a), ft_free(&b), 0);
}
