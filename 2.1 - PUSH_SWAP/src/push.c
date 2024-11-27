/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:51:44 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Push the first element on top of b and put it on a. */

void	push_a(t_node **a, t_node **b)
{
	t_node	*push_to_b;

	if (!(*b))
		return ;
	push_to_b = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = push_to_b;
	ft_printf("pa\n");
}

/* Push the first element on top of a and put it on b. */

void	push_b(t_node **a, t_node **b)
{
	t_node	*push_to_a;

	if (!(*a))
		return ;
	push_to_a = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = push_to_a;
	ft_printf("pb\n");
}
