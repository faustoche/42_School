/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:52:08 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Iterate through the list to compare the nodes. */
/* Find the smallest element. */

t_node	*find_min(t_node **stack)
{
	t_node	*min;
	t_node	*tmp;

	min = *stack;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->data < min->data)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

/* Iterate through the list to compare the nodes. */
/* Find the biggest element. */

t_node	*find_max(t_node **stack)
{
	t_node	*max;
	t_node	*tmp;

	max = *stack;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->data > max->data)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

/* Find the position of an element in the stack. */

int	find_position(t_node **stack, t_node *target_node)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while ((tmp != target_node) && tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

/* Check if the stack is sorted. */

int	is_sorted(t_node **a)
{
	t_node	*tmp;

	tmp = *a;
	while (tmp && tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
