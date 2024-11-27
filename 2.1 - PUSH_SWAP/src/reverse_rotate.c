/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:51:47 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Main reverse_rotate algorithm. */

static void	ft_reverse_rotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*end;

	if (!(*stack) || !((*stack)->next))
		return ;
	tmp = *stack;
	end = lst_last(*stack);
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	end->next = tmp;
	(*stack)->next = NULL;
	*stack = end;
}

void	reverse_rotate_a(t_node **a)
{
	ft_reverse_rotate(a);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_node **b)
{
	ft_reverse_rotate(b);
	ft_printf("rrb\n");
}

void	reverse_rotate_both(t_node **a, t_node **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	ft_printf("rrr\n");
}
