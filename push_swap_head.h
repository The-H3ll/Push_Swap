/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_head.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:26:05 by molabhai          #+#    #+#             */
/*   Updated: 2021/06/16 16:26:23 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_HEAD_H
#define PUSH_SWAP_HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libft/libft.h"


typedef struct s_stack_a
{
	 int	*container;
	 int 	count;
	 int 	error;
}				t_stack_a;

typedef struct s_stack_b
{
	int		*container;
	int		count;
}				t_stack_b;

typedef struct s_double_stack
{
	t_stack_b stack_b;
	t_stack_a stack_a;
}				t_double_stack;

t_stack_a	swap_a(t_stack_a stack_a);
t_stack_a	rotate_a(t_stack_a stack_a);
t_stack_a	reverse_rotate_a(t_stack_a stack_a);
t_stack_b	push_b(int *count, int *container, t_stack_b stack_b);
t_stack_b	swap_b(t_stack_b stack_b);
t_stack_b	rotate_b(t_stack_b stack_b);
t_stack_b	reverse_rotate_b(t_stack_b stack_b);
t_stack_a	push_a(int *count, int *container, t_stack_a stack_a);
void 		ss(t_stack_a stack_a, t_stack_b stack_b);
void		rr(t_stack_a stack_a, t_stack_b stack_b);
void		rrr(t_stack_a stack_a, t_stack_b stack_b);
void		algo_for_three(t_stack_a stack_a);

#endif //PUSH_SWAP_PUSH_SWAP_HEAD_H
