/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:51:50 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Main rotate algorithm. */

static void	ft_rotate(t_node **stack)
{
	t_node	*head;

	head = *stack;
	if (!(*stack) || !((*stack)->next))
		return ;
	*stack = head->next;
	head->next = NULL;
	lst_last(*stack)->next = head;
}

void	rotate_a(t_node **a)
{
	ft_rotate(a);
	ft_printf("ra\n");
}

void	rotate_b(t_node **b)
{
	ft_rotate(b);
	ft_printf("rb\n");
}

void	rotate_both(t_node **a, t_node **b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_printf("rr\n");
}
