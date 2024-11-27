/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:52:14 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Push elements according to the minimum */

void	push_to_according_min(t_node **a, t_node **b)
{
	while (lst_size(a) > 3)
	{
		if ((find_position(a, find_min(a))) == 0)
			push_b(a, b);
		else if ((find_position(a, find_min(a)))
			< (lst_size(a) / 2 + 1))
			rotate_a(a);
		else
			reverse_rotate_a(a);
	}
}

/* Main function for sorting. */

void	quick_sort(t_node **a, int count)
{
	t_node	*b;

	b = NULL;
	if (!is_sorted(a))
		free_both_stacks(*a, b, 0);
	keep_sorting(a, &b, count);
	free_both_stacks(*a, b, 0);
}
