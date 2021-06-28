/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo_helper_five.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 19:03:03 by molabhai          #+#    #+#             */
/*   Updated: 2021/06/27 19:03:05 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_head.h"

t_stack	push_b(int *count, int *container, t_stack stack_b)
{
	int	*temp;
	int	i;
	int	j;

	i = 1;
	j = 0;
	stack_b.count += 1;
	if (stack_b.container == NULL)
	{
		stack_b.container = malloc(sizeof(int) * stack_b.count);
		stack_b.container[0] = container[0];
		organise(container, count);
		write(1, "pb\n", 3);
		return (stack_b);
	}
	temp = fill_container(stack_b.container, stack_b.count - 1);
	free(stack_b.container);
	stack_b.container = malloc(sizeof (int) * stack_b.count);
	stack_b.container[0] = container[0];
	while (j < stack_b.count - 1)
		stack_b.container[i++] = temp[j++];
	free(temp);
	organise(container, count);
	write(1, "pb\n", 3);
	return (stack_b);
}

t_stack	push_a(int *count, int *container, t_stack stack_a)
{
	int	*temp;
	int	i;
	int	j;

	i = 1;
	j = 0;
	stack_a.count += 1;
	if (stack_a.container == NULL)
	{
		stack_a.container = malloc(sizeof(int) * stack_a.count);
		stack_a.container[0] = container[0];
		organise(container, count);
		return (stack_a);
	}
	temp = fill_container(stack_a.container, stack_a.count - 1);
	free(stack_a.container);
	stack_a.container = malloc(sizeof (int) * stack_a.count);
	stack_a.container[0] = container[0];
	while (j < stack_a.count - 1)
		stack_a.container[i++] = temp[j++];
	organise(container, count);
	free(temp);
	write(1, "pa\n", 3);
	return (stack_a);
}

int	dont_sort(t_stack stack_a)
{
	int	check;
	int	i;

	check = 0;
	i = 0;
	while (i < stack_a.count)
	{
		if (i + 1 <= stack_a.count)
		{
			if (stack_a.container[i] > stack_a.container[i + 1])
				check = 1;
		}
		i += 1;
	}
	return (check);
}
