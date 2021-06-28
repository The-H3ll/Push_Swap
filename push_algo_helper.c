/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 15:09:30 by molabhai          #+#    #+#             */
/*   Updated: 2021/06/27 15:09:32 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_head.h"

int	condition_one(t_stack stack_a)
{
	return ((stack_a.container[1] < stack_a.container[0])
		&& (stack_a.container[1] < stack_a.container[2])
		&& (stack_a.container[0] < stack_a.container[2]));
}

int	condition_two(t_stack stack_a)
{
	return ((stack_a.container[0] > stack_a.container[1])
		&& (stack_a.container[0] > stack_a.container[2])
		&& stack_a.container[1] > stack_a.container[2]);
}

int	condition_three(t_stack stack_a)
{
	return ((stack_a.container[1] < stack_a.container[0])
		&& (stack_a.container[1] < stack_a.container[2])
		&& (stack_a.container[2] < stack_a.container[0]));
}

int	condition_four(t_stack stack_a)
{
	return ((stack_a.container[1] > stack_a.container[0])
		&& (stack_a.container[1] > stack_a.container[2])
		&& (stack_a.container[0] < stack_a.container[2]));
}

t_stack	condition_one_h(t_stack stack_a)
{
	stack_a = reverse_rotate(stack_a);
	write(1, "rra\n", 4);
	return (stack_a);
}
