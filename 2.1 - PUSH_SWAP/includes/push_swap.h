/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:51:40 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<limits.h>
# include <math.h>
# include "ft_printf.h"

/* Structures */

typedef struct s_node
{
	struct s_node	*next;
	int				data;
	int				index;
	int				flag;
}	t_node;

typedef struct s_stack
{
	int	next;
	int	max;
	int	pivot;
	int	flag;
}	t_stack;

/* Main */

int		handle_one_arg(char *arg, t_node **a);
int		handle_multiple_arg(int ac, char **av, t_node **a);
void	process_sorting(t_node **a);

/* Small sort */

void	sort_two_numbers(t_node **stack);
void	sort_three_numbers(t_node **stack);
void	sort_four_numbers(t_node **a, t_node **b);
void	sort_five_numbers(t_node **a, t_node **b);

/* Quick sort */

void	push_to_according_min(t_node **a, t_node **b);
void	quick_sort(t_node **a, int count);

/* Init */

void	init_sorting(t_node **a, t_node **b, t_stack *stack, int count);
void	find_next(t_node **a, t_node **b, t_stack *stack);
void	push_a(t_node **a, t_node **b);
void	push_b(t_node **a, t_node **b);
void	keep_sorting(t_node **a, t_node **b, int count);

/* Commands */

void	swap_a(t_node **stack);
void	swap_b(t_node **stack);
void	swap_both(t_node **a, t_node **b);
void	rotate_a(t_node **stack);
void	rotate_b(t_node **stack);
void	rotate_both(t_node **a, t_node **b);
void	reverse_rotate_a(t_node **stack);
void	reverse_rotate_b(t_node **stack);
void	reverse_rotate_both(t_node **a, t_node **b);

/* Errors */

int		has_duplicates(t_node **a);
int		is_a_sorted(t_node **a, int count);
void	find_index(t_node **a);
void	free_stack(t_node *stack, int i);
void	free_both_stacks(t_node *a, t_node *b, int i);

/* Lst utils*/

t_node	*find_min(t_node **stack);
t_node	*find_max(t_node **stack);
int		find_position(t_node **stack, t_node *min);
int		is_sorted(t_node **a);

/* Utils */

void	add_back_lst(t_node **lst, t_node *new);
t_node	*lst_new(char *content);
t_node	*lst_last(t_node *lst);
int		lst_size(t_node **stack);

/* Atoi */

long	ft_atoi(char *str);
int		check_sign(char *str);

/* Split */

int		count_word(char const *s, char c);
int		count_char(char const *s, char c);
char	**free_split(char **dst);
char	**other_split(char **dst, const char *s, char c);
char	**ft_split(char const *s, char c);

/* SPlit utils */

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char *src);
int		ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);

#endif