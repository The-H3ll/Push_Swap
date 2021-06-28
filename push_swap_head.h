/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_head.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:26:05 by molabhai          #+#    #+#             */
/*   Updated: 2021/06/21 19:01:58 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_HEAD_H
# define PUSH_SWAP_HEAD_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "Libft/libft.h"

typedef struct s_stack
{
	int	*container;
	int	count;
	int	error;
}				t_stack;

typedef struct s_chunk
{
	int	min;
	int	max;
}				t_chunk;

typedef struct s_var
{
	int	top;
	int	t;
	int	b;
	int	bottom;
	int	to_find;
}				t_var;

t_stack			swap(t_stack stack_a);
t_stack			rotate(t_stack stack_a);
t_stack			reverse_rotate(t_stack stack_a);
t_stack			push_b(int *count, int *container, t_stack stack_b);
t_stack			push_a(int *count, int *container, t_stack stack_a);
t_stack			algo_for_three(t_stack stack_a);
t_stack			algo_for_five(t_stack stack_a, t_stack stack_b);
t_stack			algo_for_two(t_stack stack_a);
t_stack			algo_for_(t_stack stack_a, t_stack stack_b);
int				condition_one(t_stack stack_a);
int				condition_two(t_stack stack_a);
int				condition_three(t_stack stack_a);
int				condition_four(t_stack stack_a);
t_stack			condition_one_h(t_stack stack_a);
t_stack			condition_two_h(t_stack stack_a);
t_stack			condition_three_h(t_stack stack_a);
t_stack			condition_four_h(t_stack stack_a);
t_stack			condition_five_h(t_stack stack_a);
t_stack			algo_five_helper(t_stack stack_a, t_stack stack_b, int count);
t_stack			find_helper(t_stack *stack_a, t_stack stack_b, t_var var);
t_stack			big_helper(t_stack stack_a, t_stack *stack_b, t_var var);
int				search_for_min(t_stack stack_a, int in);
int				search_for_max(t_stack stack_a, int min);
t_chunk			intervall(t_stack stack_a, int chunk_start, t_chunk chunk);
int				find_the_big(t_stack stack_b);
t_stack			return_big(t_stack stack_a, t_stack *stack_b);
int				no_find(int min, int max, t_stack stack_a);
t_stack			algo_for_(t_stack stack_a, t_stack stack_b);
t_stack			find_best_one(t_stack *stack_a, t_chunk chunk, t_stack stack_b);
int				*fill_container(int *container, int count);
void			organise(int *container, int *count);
int				dont_sort(t_stack stack_a);

#endif //PUSH_SWAP_PUSH_SWAP_HEAD_H
