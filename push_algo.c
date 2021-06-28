/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 10:49:46 by molabhai          #+#    #+#             */
/*   Updated: 2021/06/26 16:02:04 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_head.h"

t_stack	algo_for_three(t_stack stack_a)
{
	if ((stack_a.container[0] < stack_a.container[1])
		&& (stack_a.container[0] > stack_a.container[2]))
		return (condition_one_h(stack_a));
	if (condition_one(stack_a))
		return (condition_two_h(stack_a));
	if (condition_two(stack_a))
		return (condition_three_h(stack_a));
	if (condition_three(stack_a))
		return (condition_four_h(stack_a));
	if (condition_four(stack_a))
		return (condition_five_h(stack_a));
	return (stack_a);
}

int	min_index(t_stack stack_a)
{
	int	i;
	int	index;
	int	min;

	i = 0;
	min = 0;
	index = 0;
	while (i < stack_a.count)
	{
		if (i == 0)
			min = stack_a.container[i];
		else
		{
			if (min > stack_a.container[i])
			{
				min = stack_a.container[i];
				index = i;
			}
		}
		i += 1;
	}
	return (index);
}

t_stack	algo_for_two(t_stack stack_a)
{
	if (stack_a.container[0] > stack_a.container[1])
	{
		swap(stack_a);
		write(1, "sa\n", 3);
	}
	return (stack_a);
}

t_stack	algo_for_five(t_stack stack_a, t_stack stack_b)
{
	int	stack_len;
	int	count;
	int	index_min;

	stack_len = stack_a.count / 2;
	count = stack_a.count;
	while (stack_a.count != 3)
	{
		index_min = min_index(stack_a);
		if (index_min > stack_len && index_min != 0)
		{
			reverse_rotate(stack_a);
			write(1, "rra\n", 4);
		}
		else if (index_min <= stack_len && index_min != 0)
		{
			rotate(stack_a);
			write(1, "ra\n", 3);
		}
		if (index_min == 0)
			stack_b = push_b(&stack_a.count, stack_a.container, stack_b);
	}
	stack_a = algo_five_helper(stack_a, stack_a, count);
	free (stack_b.container);
	return (stack_a);
}
