/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:52:01 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Check if some numbers are duplicates. */
/* Iterate into the stack and compare every data. */
/* If there is a double, return 1.*/

int	has_duplicates(t_node **a)
{
	t_node	*current;
	t_node	*cmp;
	int		i;

	current = *a;
	i = lst_size(a);
	while (i > 0)
	{
		cmp = current->next;
		while (cmp)
		{
			if (current->data == cmp->data)
				return (1);
			cmp = cmp->next;
		}
		current = current->next;
		i--;
	}
	return (0);
}

/* Check if the stack a is sorted or not. */
/* Call the fonction "is sorted" to see if the stack is sorted */
/* Function is_sorted doesn't work by itself. DOn't know why. */

int	is_a_sorted(t_node **a, int count)
{
	int	len;

	len = lst_size(a);
	if (len != count)
		return (0);
	if (is_sorted(a) == 1)
		return (0);
	return (1);
}

/* Find index of the number depending on the value of the element.*/
/* For {20, 10, 30} : 10 = [0], 20 = [1], etc. */
/* Iterate through the list to find the smallest value with no index.*/
/* When found, the smallest value get the current index who is increased.*/

void	find_index(t_node **a)
{
	t_node			*current;
	t_node			*min_node;
	long long int	min_value;
	int				size;
	int				index;

	size = lst_size(a);
	index = 0;
	while (index < size)
	{
		min_value = LLONG_MAX;
		current = *a;
		while (current)
		{
			if ((current->data < min_value) && (current->index == -1))
			{
				min_value = current->data;
				min_node = current;
			}
			current = current->next;
		}
		min_node->index = index;
		index++;
	}
}

/* Free only one specific stack. */
/* Iterate through every node with a tmp variable in order to free them. */

void	free_stack(t_node *stack, int i)
{
	t_node	*tmp;

	if (i == 1)
		ft_printf("Error\n");
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	exit(0);
}

/* Free both of the stacks. */
/* Iterate in the first stack with tmp variable to free. */
/* Iterate in the second stack to free too. */

void	free_both_stacks(t_node *a, t_node *b, int i)
{
	if (i == 1)
		ft_printf("Error\n");
	free_stack(a, 0);
	free_stack(b, 0);
	exit(0);
}
