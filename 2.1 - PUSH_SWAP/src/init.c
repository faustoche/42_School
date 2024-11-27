/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:52:05 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Initialize the stack and the sorting around the pivot value. */
/* If index in a is smaller or egal to pivot, pushed to b. */
/* Else, if index of the first value of b is smaller than half of the pivot. */
/* Rotate both. If none of these, rotate_a. */

void	init_sorting(t_node **a, t_node **b, t_stack *stack, int count)
{
	int	i;

	i = -1;
	while (++i < count)
	{
		if ((*a)->index <= stack->pivot)
			push_b(a, b);
		else
		{
			if (lst_size(b) > 1 && (((*b)->index) < (stack->pivot / 2)))
				rotate_both(a, b);
			else
				rotate_a(a);
		}
	}
	stack->max = stack->pivot;
	stack->pivot = (stack->max - stack->next) / 2 + stack->next;
	stack->flag++;
}

/* Find where to send the next element according to the smallest index. */
/* If 1st element of b is the one we're looking for at index, push_a */
/* If 1st element of a have the wanted index, flag = -1 anc rotate_a */
/* If last element of b is at wanted index, rrb to put it first */
/* If  2nd element of a is at wanted index, swap_a */
/* If 2 first elements of a and b are the wanted index, swap_both.*/

void	find_next(t_node **a, t_node **b, t_stack *stack)
{
	if (lst_size(b) > 0 && ((*b)->index == stack->next))
		push_a(a, b);
	else if ((*a)->index == stack->next)
	{
		(*a)->flag = -1;
		rotate_a(a);
		stack->next++;
	}
	else if ((lst_size(b)) > 2
		&& lst_last(*b)->index == stack->next)
		reverse_rotate_b(b);
	else if ((*a)->next->index == stack->next)
		swap_a(a);
	else if ((lst_size(a)) > 1 && ((*a)->next->index == stack->next)
		&& ((*b)->next->index == stack->next + 1))
		swap_both(a, b);
	else
		return ;
	find_next(a, b, stack);
}

/* Push from b to a according to the conditions. */
/* Check for each element : */
/* If index is equal to next and call find next*/
/* If index is bigger of equal to pivot then push_a */
/* If index is smaller to pivot then rotate_b */

void	push_to_a(t_node **a, t_node **b, t_stack *push)
{
	int	count_b;
	int	i;

	i = -1;
	count_b = lst_size(b);
	while (lst_size(b) && ++i < count_b)
	{
		if ((*b)->index == push->next)
			find_next(a, b, push);
		else if ((*b)->index >= push->pivot)
		{
			(*b)->flag = push->flag;
			push_a(a, b);
		}
		else if ((*b)->index < push->pivot)
			rotate_b(b);
	}
	push->max = push->pivot;
	push->pivot = (push->max - push->next) / 2 + push->next;
	push->flag++;
}

/* Push from a to b according to the conditions.*/
/* Gather the elements according to the way they are flagged. */
/* Sort the elements by calling find next to sort them in a. */
/* Update pivot in order to sort several groups of elements. */

void	push_to_b(t_node **a, t_node **b, t_stack *push)
{
	int	current_flag;

	current_flag = (*a)->flag;
	if ((*a)->flag != 0)
	{
		while ((*a)->flag == current_flag)
		{
			if ((*a)->index != push->next)
				push_b(a, b);
			find_next(a, b, push);
		}
	}
	else if ((*a)->flag == 0)
	{
		while ((*a)->flag != -1)
		{
			if ((*a)->index != push->next)
				push_b(a, b);
			find_next(a, b, push);
		}
	}
	if (lst_size(b))
		push->max = (find_max(b))->index;
	push->pivot = (push->max - push->next) / 2 + push->next;
}

/* Initialize the structure and call function for the sort. */
/* Assign index to each a node. */
/* Define the initial values of next and max using the min and max index. */
/* Call init sorting to divide elements of a and b around pivot. */

void	keep_sorting(t_node **a, t_node **b, int count)
{
	t_stack	push;

	find_index(a);
	push.next = find_min(a)->index;
	push.max = find_max(a)->index;
	push.pivot = push.max / 2 + push.next;
	push.flag = 0;
	init_sorting(a, b, &push, count);
	while (!(is_a_sorted(a, count)))
	{
		if (lst_size(b) == 0)
			push_to_b(a, b, &push);
		else
			push_to_a(a, b, &push);
	}
}
