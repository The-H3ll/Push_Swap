/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo_helper_four.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:01:12 by molabhai          #+#    #+#             */
/*   Updated: 2021/06/27 17:01:15 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_head.h"

t_chunk	intervall(t_stack stack_a, int chunk_start, t_chunk chunk)
{
	int	hold;
	int	i;

	i = 0;
	chunk.min = INT32_MIN;
	while (i < stack_a.count && chunk_start > 0)
	{
		chunk.min = search_for_min(stack_a, chunk.min);
		hold = chunk.min;
		chunk_start--;
		i += 1;
	}
	chunk.max = hold;
	return (chunk);
}

int	find_the_big(t_stack stack_b)
{
	int	max;
	int	i;

	i = 0;
	max = stack_b.container[0];
	while (i < stack_b.count)
	{
		if (max < stack_b.container[i])
			max = stack_b.container[i];
		i += 1;
	}
	return (max);
}

t_stack	return_big(t_stack stack_a, t_stack *stack_b)
{
	t_var	var;

	ft_memset(&var, 0, sizeof(t_var));
	var.bottom = (*stack_b).count - 1;
	var.to_find = find_the_big(*stack_b);
	while (var.top < ((*stack_b).count) && var.bottom >= 0)
	{
		if ((*stack_b).container[var.top] == var.to_find)
		{
			var.t = 1;
			break ;
		}
		else if ((*stack_b).container[var.bottom] == var.to_find)
		{
			var.b = 1;
			break ;
		}
		var.top += 1;
		var.bottom -= 1;
	}
	stack_a = big_helper(stack_a, stack_b, var);
	return (stack_a);
}

int	no_find(int min, int max, t_stack stack_a)
{
	int	i;
	int	in;

	i = 0;
	in = 0;
	min = 0;
	while (i < stack_a.count)
	{
		if (max == stack_a.container[i])
			in = 1;
		i += 1;
	}
	return (in);
}

t_stack	algo_for_(t_stack stack_a, t_stack stack_b)
{
	int		hold;
	int		chunk_start;
	t_chunk	chunk;
	int		take;

	take = stack_a.count;
	chunk_start = 0;
	if (stack_a.count <= 100)
		chunk_start = stack_a.count / 5;
	else if (stack_a.count > 100)
		chunk_start = stack_a.count / 20;
	hold = chunk_start;
	while (stack_b.count != take)
	{
		chunk = intervall(stack_a, chunk_start, chunk);
		while (stack_b.count < hold
			&& no_find(chunk.min, chunk.max, stack_a) == 1)
			stack_b = find_best_one(&stack_a, chunk, stack_b);
		hold += chunk_start;
	}
	take = stack_b.count;
	while (stack_a.count < take)
		stack_a = return_big(stack_a, &stack_b);
	free(stack_b.container);
	return (stack_a);
}
