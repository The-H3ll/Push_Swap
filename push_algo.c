/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 10:49:46 by molabhai          #+#    #+#             */
/*   Updated: 2021/06/22 18:37:28 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_head.h"

t_stack	algo_for_three(t_stack stack_a)
{
	if ((stack_a.container[0] < stack_a.container[1])
		&& (stack_a.container[0] > stack_a.container[2]))
	{
		reverse_rotate(stack_a);
		write(1, "rra\n", 4);
		return (stack_a);
	}
	if ((stack_a.container[1] < stack_a.container[0])
		&& (stack_a.container[1] < stack_a.container[2]) && (stack_a.container[0] < stack_a.container[2]))
	{
		swap(stack_a);
		write(1, "sa\n", 3);
		return (stack_a);
	}
	if ((stack_a.container[0] > stack_a.container[1])
		&& (stack_a.container[0] > stack_a.container[2])
		&& stack_a.container[1] > stack_a.container[2])
	{
		swap(stack_a);
		write(1, "sa\n", 3);
		reverse_rotate(stack_a);
		write(1, "rra\n", 3);
		return (stack_a);
	}
	if ((stack_a.container[1] < stack_a.container[0])
		&& (stack_a.container[1] < stack_a.container[2]) && (stack_a.container[2] < stack_a.container[0]))
	{
		rotate(stack_a);
		write(1, "ra\n", 3);
		return (stack_a);
	}
	if ((stack_a.container[1] > stack_a.container[0]) && (stack_a.container[1] > stack_a.container[2])
		&& (stack_a.container[0] < stack_a.container[2]))
	{
		swap(stack_a);
		write(1, "sa\n", 3);
		rotate(stack_a);
		write(1, "ra\n", 3);
		return (stack_a);
	}
	return (stack_a);
}

int		min_index(t_stack stack_a)
{
	int i;
	int index;
	int min;

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
	int stack_len;
	int count;
	int index_min;
	int i;

	i = 0;
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
			write(1, "ra\n", 4);
		}
		if (index_min == 0)
			stack_b = push_b(&stack_a.count, stack_a.container, stack_b);
	}
	algo_for_three(stack_a);
	stack_a = push_a(&stack_b.count, stack_b.container, stack_a);
	if (count == 5)
		stack_a = push_a(&stack_b.count, stack_b.container, stack_a);
	return (stack_a);
}

int		check_stack_b(t_stack_b stack_b, int chunk_number)
{
	if (stack_b.count == chunk_number)
		return (1);
	return (0);
}

/*
int	bigger_or_smaller(t_stack stack_a, t_stack stack_b)
{
	int min;
	int max;
	int	i;

	i = 0;
	min = 0;
	max = 0;
	while (i < stack_b.count)
	{
		if (stack_a.container[0] > stack_b.container[i])
			max += 1;
		else if (stack_a.container[0] < stack_b.container[i])
			min += 1;
	}
	if (max == stack_b.count)
	{

	}
}*/


t_stack	find_best_one(t_stack *stack_a, t_chunk chunk, t_stack stack_b)
{
	int top;
	int t;
	int b;
	int bottom;

	t = 0;
	b = 0;
	top = 0;
	bottom = (*stack_a).count - 1;
	printf("top ==> %d || stack --> %d\n", (*stack_a).container[top], (*stack_a).container[bottom]);
	while (top < (*stack_a).count && bottom >= 0)
	{
		if ((*stack_a).container[top] >= chunk.min && (*stack_a).container[top] <= chunk.max
			/*&& ds.stack_a.container[top] <= ((ds.stack_a.count - 1) / 2)*/)
		{
			t = 1;
			break ;
		}
		else if ((*stack_a).container[bottom] >= chunk.min && (*stack_a).container[bottom] <= chunk.max
				/*&& ds.stack_a.container[bottom] > ((ds.stack_a.count - 1) / 2)*/)
		{
			b = 1;
			break ;
		}
		top += 1;
		bottom -= 1;
	}
	if (t == 1)
	{
		if (top == 0)
		{
			stack_b = push_b(&(*stack_a).count, (*stack_a).container, stack_b);
			return (stack_b);
		}
		rotate(*stack_a);
		write(1, "ra\n", 3);
	}
	else if (b == 1)
	{
		reverse_rotate(*stack_a);
		write(1, "rra\n", 4);
	}
	for (int o = 0; o < (*stack_a).count; o++)
		printf("scc ==> %d\n", (*stack_a).container[o]);
	return (stack_b);
}


int	search_for_min(t_stack stack_a)
{
	int i;
	int min;

	i = 0;
	min = stack_a.container[0];
	while (i < stack_a.count)
	{
		if (min > stack_a.container[i])
			min = stack_a.container[i];
		i += 1;
	}
	return (min);
}

int	search_for_max(t_stack stack_a, int without)
{
	int i;
	int min;

	i = 0;
	min = stack_a.container[0];
	while (i < stack_a.count)
	{
		if (min > stack_a.container[i] && stack_a.container[i] > without)
			min = stack_a.container[i];
		i += 1;
	}
	return (min);
}

t_chunk	intervall(t_stack stack_a, int chunk_start, t_chunk chunk)
{
	int hold;
	int i;
	static int time = 0;

	i = 0;

	chunk.min = search_for_min(stack_a);
	hold = chunk.min;
	while (i <= chunk_start)
	{
		chunk.max = search_for_max(stack_a, chunk.min);
		hold = chunk.max;
		i += 1;
	}
	time += 1;
	return (chunk);
} 

int		find_the_big(t_stack stack_b)
{
	int max;
	int i;

	i = 0;
	max = stack_b.container[0];
	while (i < stack_b.count)
	{
		if (max < stack_container[i])
			max = stack_container[i];
		i += 1;
	}
	return (max);
}

t_stack	return_big(t_stack stack_a, t_stack stack_b)
{
	int top;
	int t;
	int bottom;
	int	to_find;
	int	b;

	top = 0;
	t = 0;
	b = 0;
	bottom = stack_b.count - 1;
	to_find = find_the_big(stack_b);
	while (top < (stack_b.count) && bottom >= 0)
	{
		if (stack_b.container[top] == to_find)
		{
			t = 1;
			break ;
		}
		else if (stack_b.container[bottom] == to_find)
		{
			b = 1;
			break ;
		}
		top += 1;
		bottom -= 1;
	}
	if (t == 1)
	{
		if (top == 0)
		{
			
		}
	}
}

t_stack	algo_for_(t_stack stack_a, t_stack stack_b)
{
	int chunks;
	int hold;
	int chunk_start;
	int numbers;
	t_chunk chunk;
	int	time;
	int	take;

	time = 0;
	take = stack_a.count;
	numbers = stack_a.count - 1;
	chunk_start = 0;
	if ((stack_a.count - 1) <= 100)
		chunk_start = stack_a.count / 5;
	hold = chunk_start;
	chunks = 5 + (stack_a.count % 5);
	while (time < chunks)
	{
		while (stack_b.count < take)
		{
			chunk = intervall(stack_a, hold, chunk);
			stack_b = find_best_one(&stack_a, chunk, stack_b);
		}
		hold += chunk_start;
		time += 1;
	}

	return (stack_a);
}
