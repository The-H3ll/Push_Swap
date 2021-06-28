/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instruction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 12:00:41 by molabhai          #+#    #+#             */
/*   Updated: 2021/06/21 19:25:00 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_head.h"

t_stack	swap(t_stack stack)
{
	int	i;
	int	temp;

	i = 0;
	if (stack.count > 1)
	{
		temp = stack.container[i];
		stack.container[i] = stack.container[i + 1];
		stack.container[i + 1] = temp;
	}
	return (stack);
}

t_stack	rotate(t_stack stack)
{
	int	i;
	int	temp;

	i = 0;
	if (stack.count > 1)
	{
		temp = stack.container[i];
		while (i < stack.count)
		{
			if ((i + 1) < (stack.count + 1))
				stack.container[i] = stack.container[i + 1];
			i += 1;
		}
		stack.container[stack.count - 1] = temp;
	}
	return (stack);
}

t_stack	reverse_rotate(t_stack stack)
{
	int	i;
	int	temp;

	i = stack.count - 1;
	if (stack.count > 1)
	{
		temp = stack.container[stack.count - 1];
		while (i >= 0)
		{
			if ((i - 1) >= 0)
				stack.container[i] = stack.container[i - 1];
			i -= 1;
		}
		stack.container[0] = temp;
	}
	return (stack);
}

void	organise(int *container, int *count)
{
	int	i;

	i = 0;
	*count -= 1;
	while (i < *count)
	{
		if ((i + 1) <= *count)
		{
			container[i] = container[i + 1];
		}
		i += 1;
	}
}

int	*fill_container(int *container, int count)
{
	int	i;
	int	*conta;

	i = 0;
	conta = malloc(sizeof (int *) * count);
	while (i < count)
	{
		conta[i] = container[i];
		i += 1;
	}
	return (conta);
}
