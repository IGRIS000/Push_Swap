/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichtioui <ichtioui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:21:43 by ichtioui          #+#    #+#             */
/*   Updated: 2026/01/03 11:51:54 by ichtioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "gnl/get_next_line.h"

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

int		ft_syntax_err(char	*str);
int		ft_duplicate(t_node *head, int s);
void	ft_free(t_node **head);
void	ft_err_free(t_node **head);

void	ft_add_end(t_node **head, t_node *node);
t_node	*ft_create(int a);
t_node	*ft_last(t_node *head);

long	ft_atol(const char *str);
int		ft_stack_len(t_node *head);
int		ft_check(t_node *a);
void	ft_index(t_node *head);

void	*ft_free_split(char **s);
char	**ft_split(char *s, char c);
int		stack_parse(t_node **head, char *argv);

void	ft_pa(t_node **a, t_node **b, bool print);
void	ft_pb(t_node **b, t_node **a, bool print);
void	ft_sa(t_node **a, bool print);
void	ft_sb(t_node **b, bool print);
void	ft_ss(t_node **a, t_node **b, bool print);
void	ft_ra(t_node **a, bool print);
void	ft_rb(t_node **b, bool print);
void	ft_rr(t_node **a, t_node **b, bool print);
void	ft_rra(t_node **a, bool print);
void	ft_rrb(t_node **b, bool print);
void	ft_rrr(t_node **a, t_node **b, bool print);

void	ft_sort_three(t_node **head);
void	ft_sort_five(t_node **a, t_node **b);
void	ft_sort_chunks(t_node **a, t_node **b, int len);
void	ft_sort_back(t_node **a, t_node **b);

#endif