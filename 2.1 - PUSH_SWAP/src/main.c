/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:52:11 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*a;

	a = NULL;
	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		if (handle_one_arg(av[1], &a))
			return (1);
	}
	else
	{
		if (handle_multiple_arg(ac, av, &a))
			return (1);
	}
	process_sorting(&a);
	return (0);
}

/* Handle one argument with split. */
/* If there's is one string of numbers, split into substrings. */
/* Create a new node for each of them and add them at the back of the list. */

int	handle_one_arg(char *arg, t_node **a)
{
	char	**str;
	t_node	*new_node;
	int		i;

	i = 0;
	str = ft_split(arg, ' ');
	if (!str)
		return (1);
	while (str[i])
	{
		new_node = lst_new(str[i++]);
		if (!new_node)
		{
			free_split(str);
			free_stack(*a, 1);
			return (1);
		}
		add_back_lst(a, new_node);
	}
	free_split(str);
	return (0);
}

/* Handle multiples arguments. */
/* Create a new node for each number and add them at the back. */

int	handle_multiple_arg(int ac, char **av, t_node **a)
{
	t_node	*new_node;
	int		i;

	i = 1;
	while (i < ac)
	{
		new_node = lst_new(av[i]);
		if (!new_node)
		{
			free_stack(*a, 1);
			return (1);
		}
		add_back_lst(a, new_node);
		i++;
	}
	return (0);
}

/* Process the sorting. */
/* Check if there is duplicates in the list. If so, free the stack. */
/* Start sorting depending on the numbers of arguments*/

void	process_sorting(t_node **a)
{
	int		size;
	t_node	*b;

	b = NULL;
	size = lst_size(a);
	if (has_duplicates(a))
		free_stack(*a, 1);
	else
	{
		if (size == 2)
			sort_two_numbers(a);
		else if (size == 3)
			sort_three_numbers(a);
		else if (size == 4)
			sort_four_numbers(a, &b);
		else if (size == 5)
			sort_five_numbers(a, &b);
		else
			quick_sort(a, size);
		free_stack(*a, 0);
	}
}
