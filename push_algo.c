/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 10:49:46 by molabhai          #+#    #+#             */
/*   Updated: 2021/06/21 10:49:50 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_head.h"

void	algo_for_three(t_stack_a stack_a)
{
	if ((stack_a.container[0] < stack_a.container[1])
		&& (stack_a.container[0] > stack_a.container[2]))
	{
		reverse_rotate_a(stack_a);
		return ;
	}
	if ((stack_a.container[1] < stack_a.container[0])
		&& (stack_a.container[1] < stack_a.container[2]) && (stack_a.container[0] < stack_a.container[2]))
	{
		swap_a(stack_a);
		return ;
	}
	if ((stack_a.container[0] > stack_a.container[1])
		&& (stack_a.container[0] > stack_a.container[2])
		&& stack_a.container[1] > stack_a.container[2])
	{
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
		return ;
	}
	if ((stack_a.container[1] < stack_a.container[0])
		&& (stack_a.container[1] < stack_a.container[2]) && (stack_a.container[2] < stack_a.container[0]))
	{
		rotate_a(stack_a);
		return ;
	}
	if ((stack_a.container[1] > stack_a.container[0]) && (stack_a.container[1] > stack_a.container[2])
		&& (stack_a.container[0] < stack_a.container[2]))
	{
		swap_a(stack_a);
		rotate_a(stack_a);
		return ;
	}
}

void	alog_for_five(t_stack_a stack_a, t_stack_b stack_b)
{

}