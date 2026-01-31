/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichtioui <ichtioui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:56:24 by ichtioui          #+#    #+#             */
/*   Updated: 2026/01/02 11:03:45 by ichtioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_syntax_err(char	*str)
{
	if (!(*str))
		return (1);
	if (*str == '+' || *str == '-')
		str++;
	if (!(*str))
		return (1);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}

int	ft_duplicate(t_node *head, int s)
{
	if (!head)
		return (0);
	while (head)
	{
		if (head->data == s)
			return (1);
		head = head->next;
	}
	return (0);
}

void	ft_free(t_node **head)
{
	t_node	*tmp;
	t_node	*current;

	if (!head || !(*head))
		return ;
	current = (*head);
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*head = NULL;
}

void	ft_err_free(t_node **head)
{
	ft_free(head);
	write(2, "Error\n", 6);
	exit(1);
}
