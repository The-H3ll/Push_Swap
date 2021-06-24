/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_head.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:26:05 by molabhai          #+#    #+#             */
/*   Updated: 2021/06/21 19:01:58 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_HEAD_H
#define PUSH_SWAP_HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libft/libft.h"


typedef struct s_stack
{
	 int	*container;
	 int 	count;
	 int 	error;
}				t_stack;

typedef struct s_stack_b
{
	int		*container;
	int		count;
}				t_stack_b;


typedef struct	s_chunk
{
	int min;
	int max;
}				t_chunk;

int	co;
t_stack	swap(t_stack stack_a);
t_stack	rotate(t_stack stack_a);
t_stack	reverse_rotate(t_stack stack_a);
t_stack	push_b(int *count, int *container, t_stack stack_b);
t_stack_b	swap_b(t_stack_b stack_b);
t_stack_b	rotate_b(t_stack_b stack_b);
t_stack_b	reverse_rotate_b(t_stack_b stack_b);
t_stack	push_a(int *count, int *container, t_stack stack_a);
void 		ss(t_stack stack_a, t_stack_b stack_b);
void		rr(t_stack stack_a, t_stack_b stack_b);
void		rrr(t_stack stack_a, t_stack_b stack_b);
t_stack		algo_for_three(t_stack stack_a);
t_stack		algo_for_five(t_stack stack_a, t_stack stack_b);
t_stack		algo_for_two(t_stack stack_a);
t_stack		algo_for_(t_stack stack_a, t_stack stack_b);

#endif //PUSH_SWAP_PUSH_SWAP_HEAD_H
