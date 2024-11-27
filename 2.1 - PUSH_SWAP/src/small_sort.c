/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:52:17 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Sort the stack when there is two numbers. */
/* */

void	sort_two_numbers(t_node **stack)
{
	if (is_sorted(stack) && (*stack)->data > (*stack)->next->data)
		swap_a(stack);
}

/* Sort the stack when there is 3 numbers. */

void	sort_three_numbers(t_node **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->data;
	b = (*stack)->next->data;
	c = (*stack)->next->next->data;
	if (a > b && b < c && a < c)
		swap_a(stack);
	else if (a > b && b > c)
	{
		swap_a(stack);
		reverse_rotate_a(stack);
	}
	else if (a > b && b < c && a > c)
		rotate_a(stack);
	else if (a < b && b > c && a < c)
	{
		swap_a(stack);
		rotate_a(stack);
	}
	else if (a < b && b > c && a > c)
		reverse_rotate_a(stack);
}

void	sort_four_numbers(t_node **a, t_node **b)
{
	if (is_sorted(a))
	{
		push_to_according_min(a, b);
		sort_three_numbers(a);
		push_a(a, b);
	}
}

/* Sort the stack when there is 5 numbers. */

void	sort_five_numbers(t_node **a, t_node **b)
{
	if (is_sorted(a))
	{
		push_to_according_min(a, b);
		push_to_according_min(a, b);
		sort_three_numbers(a);
		while (lst_size(b) > 0)
			push_a(a, b);
	}
}
