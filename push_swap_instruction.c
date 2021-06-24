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
	int i;
	int	temp;

	co++;
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
	int i;
	int temp;

	co++;
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

	co++;
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

void	organise(int *container, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		if ((i + 1) <= count)
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

t_stack	push_b(int *count, int *container, t_stack stack_b)
{
	int	*temp;
	int	i;
	int	j;

	co++;
	i = 1;
	j = 0;
	stack_b.count += 1;
	if (stack_b.container == NULL)
	{
		stack_b.container = malloc(sizeof(int) * stack_b.count);
		stack_b.container[0] = container[0];
		*count -= 1;
		organise(container, *count);
		write(1, "pb\n", 3);
		return (stack_b);
	}
	temp = fill_container(stack_b.container, stack_b.count - 1);
	free(stack_b.container);
	stack_b.container = malloc(sizeof (int) * stack_b.count);
	stack_b.container[0] = container[0];
	while (j < stack_b.count - 1)
	{
		stack_b.container[i++] = temp[j++];
	}
	*count -= 1;
	organise(container, *count);
	write(1, "pb\n", 3);
	return (stack_b);
}

t_stack	push_a(int *count, int *container, t_stack stack_a)
{
	int	*temp;
	int	i;
	int	j;

	co++;
	i = 1;
	j = 0;
	stack_a.count += 1;
	if (stack_a.container == NULL)
	{
		stack_a.container = malloc(sizeof(int) * stack_a.count);
		stack_a.container[0] = container[0];
		*count -= 1;
		organise(container, *count);
		return (stack_a);
	}
	temp = fill_container(stack_a.container, stack_a.count - 1);
	free(stack_a.container);
	stack_a.container = malloc(sizeof (int) * stack_a.count);
	stack_a.container[0] = container[0];
	while (j < stack_a.count - 1)
	{
		stack_a.container[i++] = temp[j++];
	}
	*count -= 1;
	organise(container, *count);
	write(1, "pa\n", 3);
	return (stack_a);
}



// t_stack_b	swap_b(t_stack_b stack_b)
// {
// 	int i;
// 	int	temp;

// 	co++;
// 	i = 0;
// 	if (stack_b.count > 1)
// 	{
// 		temp = stack_b.container[i];
// 		stack_b.container[i] = stack_b.container[i + 1];
// 		stack_b.container[i + 1] = temp;
// 	}
// 	write(1, "sb\n", 3);
// 	return (stack_b);
// }

// t_stack_b	rotate_b(t_stack_b stack_b)
// {
// 	int i;
// 	int temp;

// 	co++;
// 	i = 0;
// 	if (stack_b.count > 1)
// 	{
// 		temp = stack_b.container[i];
// 		while (i < stack_b.count)
// 		{
// 			if ((i + 1) < stack_b.count)
// 				stack_b.container[i] = stack_b.container[i + 1];
// 			i += 1;
// 		}
// 		stack_b.container[stack_b.count - 1] = temp;
// 	}
// 	write(1, "rb\n", 3);
// 	return (stack_b);
// }

// t_stack_b	reverse_rotate_b(t_stack_b stack_b)
// {
// 	int	i;
// 	int	temp;

// 	co++;
// 	i = stack_b.count - 1;
// 	if (stack_b.count > 1)
// 	{
// 		temp = stack_b.container[stack_b.count - 1];
// 		while (i >= 0)
// 		{
// 			if ((i - 1) >= 0)
// 				stack_b.container[i] = stack_b.container[i - 1];
// 			i -= 1;
// 		}
// 		stack_b.container[0] = temp;
// 	}
// 	write(1, "rrb\n", 4);
// 	return (stack_b);
// }

// t_stack_a	push_a(int *count, int *container, t_stack_a stack_a)
// {
// 	int	*temp;
// 	int	i;
// 	int	j;

// 	co++;
// 	i = 1;
// 	j = 0;
// 	stack_a.count += 1;
// 	if (stack_a.container == NULL)
// 	{
// 		stack_a.container = malloc(sizeof(int) * stack_a.count);
// 		stack_a.container[0] = container[0];
// 		*count -= 1;
// 		organise(container, *count, 1);
// 		return (stack_a);
// 	}
// 	temp = fill_container(stack_a.container, stack_a.count - 1);
// 	free(stack_a.container);
// 	stack_a.container = malloc(sizeof (int) * stack_a.count);
// 	stack_a.container[0] = container[0];
// 	while (j < stack_a.count - 1)
// 	{
// 		stack_a.container[i++] = temp[j++];
// 	}
// 	*count -= 1;
// 	organise(container, *count, 1);
// 	write(1, "pa\n", 3);
// 	return (stack_a);
// }

// void 	ss(t_stack_a stack_a, t_stack_b stack_b)
// {
// 	co++;
// 	swap_a(stack_a);
// 	swap_b(stack_b);
// 	write(1, "ss\n", 3);
// }

// void	rr(t_stack_a stack_a, t_stack_b stack_b)
// {
// 	co++;
// 	rotate_a(stack_a);
// 	rotate_b(stack_b);
// 	write(1, "rr\n", 3);
// }

// void	rrr(t_stack_a stack_a, t_stack_b stack_b)
// {
// 	co++;
// 	reverse_rotate_a(stack_a);
// 	reverse_rotate_b(stack_b);
// 	write(1, "rrr\n", 3);
// }
