/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo_helper_three.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:01:52 by molabhai          #+#    #+#             */
/*   Updated: 2021/06/27 17:01:55 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_head.h"

t_stack	find_helper(t_stack *stack_a, t_stack stack_b, t_var var)
{
	if (var.t == 1)
	{
		if (var.top == 0)
		{
			stack_b = push_b(&(*stack_a).count, (*stack_a).container, stack_b);
			return (stack_b);
		}
		rotate(*stack_a);
		write(1, "ra\n", 3);
	}
	else if (var.b == 1)
	{
		reverse_rotate(*stack_a);
		write(1, "rra\n", 4);
	}
	return (stack_b);
}

t_stack	big_helper(t_stack stack_a, t_stack *stack_b, t_var var)
{
	if (var.t == 1)
	{
		if (var.top == 0)
		{
			stack_a = push_a(&(*stack_b).count, (*stack_b).container, stack_a);
			return (stack_a);
		}
		rotate(*stack_b);
		write(1, "rb\n", 3);
	}
	else if (var.b == 1)
	{
		reverse_rotate(*stack_b);
		write(1, "rrb\n", 4);
	}
	return (stack_a);
}

t_stack	find_best_one(t_stack *stack_a, t_chunk chunk, t_stack stack_b)
{
	t_var	var;

	ft_memset(&var, 0, sizeof(t_var));
	var.bottom = (*stack_a).count - 1;
	while (var.top < (*stack_a).count && var.bottom >= 0)
	{
		if ((*stack_a).container[var.top] <= chunk.max)
		{
			var.t = 1;
			break ;
		}
		else if ((*stack_a).container[var.bottom] <= chunk.max)
		{
			var.b = 1;
			break ;
		}
		var.top += 1;
		var.bottom -= 1;
	}
	stack_b = find_helper(stack_a, stack_b, var);
	return (stack_b);
}

int	search_for_min(t_stack stack_a, int in)
{
	int	i;
	int	min;

	i = 0;
	min = INT32_MAX;
	while (i < stack_a.count)
	{
		if (stack_a.container[i] < min && stack_a.container[i] > in)
			min = stack_a.container[i];
		i += 1;
	}
	return (min);
}

int	search_for_max(t_stack stack_a, int min)
{
	int	i;
	int	index;

	index = INT32_MAX;
	i = 0;
	while (i < stack_a.count)
	{
		if (stack_a.container[i] > min && stack_a.container[i] < index)
			index = stack_a.container[i];
		i += 1;
	}
	return (index);
}
