/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo_helper_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:03:14 by molabhai          #+#    #+#             */
/*   Updated: 2021/06/27 17:03:18 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_head.h"

t_stack	condition_two_h(t_stack stack_a)
{
	stack_a = swap(stack_a);
	write(1, "sa\n", 3);
	return (stack_a);
}

t_stack	condition_three_h(t_stack stack_a)
{
	stack_a = swap(stack_a);
	write(1, "sa\n", 3);
	stack_a = reverse_rotate(stack_a);
	write(1, "rra\n", 4);
	return (stack_a);
}

t_stack	condition_four_h(t_stack stack_a)
{
	stack_a = rotate(stack_a);
	write(1, "ra\n", 3);
	return (stack_a);
}

t_stack	condition_five_h(t_stack stack_a)
{
	stack_a = swap(stack_a);
	write(1, "sa\n", 3);
	stack_a = rotate(stack_a);
	write(1, "ra\n", 3);
	return (stack_a);
}

t_stack	algo_five_helper(t_stack stack_a, t_stack stack_b, int count)
{
	algo_for_three(stack_a);
	stack_a = push_a(&stack_b.count, stack_b.container, stack_a);
	if (count == 5)
		stack_a = push_a(&stack_b.count, stack_b.container, stack_a);
	return (stack_a);
}
