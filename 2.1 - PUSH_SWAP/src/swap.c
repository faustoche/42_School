/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:51:54 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Main swap algorithm. */

void	ft_swap(t_node **stack)
{
	t_node	*tmp;

	if (!(*stack) || !((*stack)->next))
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	swap_a(t_node **a)
{
	ft_swap(a);
	ft_printf("sa\n");
}

void	swap_b(t_node **b)
{
	ft_swap(b);
	ft_printf("sb\n");
}

void	swap_both(t_node **a, t_node **b)
{
	ft_swap(a);
	ft_swap(b);
	ft_printf("ss\n");
}
