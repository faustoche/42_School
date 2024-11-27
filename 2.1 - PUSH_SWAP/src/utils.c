/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:52:27 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_correct_number(char *number)
{
	size_t	i;

	i = 0;
	if (number[i] == '-' || number[i] == '+')
		i++;
	while (number[i])
	{
		if (number[i] < '0' || number[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/* Add elements at the back of the list. */

void	add_back_lst(t_node **lst, t_node *new)
{
	t_node	*node;

	if (!new || !lst)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	node = *lst;
	while (node->next)
		node = node->next;
	node->next = new;
}

/* Add new element to the list. */

t_node	*lst_new(char *content)
{
	t_node	*new;
	long	number;

	if (!is_correct_number(content))
		return (NULL);
	number = ft_atoi(content);
	if (number == LONG_MAX)
		return (NULL);
	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->data = (int)number;
	new->index = -1;
	new->flag = 0;
	new->next = NULL;
	return (new);
}

/* Return the last element of the list. */

t_node	*lst_last(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/* Calculate the size of the stack. */

int	lst_size(t_node **stack)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
