/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:25:15 by molabhai          #+#    #+#             */
/*   Updated: 2021/06/16 16:25:16 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap_head.h"


int	check_zero(char *s)
{
	int	i;

	i = s[0] - '0';
	if (i == 0)
		return (0);
	return (1);
}

t_stack_a 	fill_check_dup(t_stack_a stack_a, int *j, long number)
{
	int i;

	i = -1;
	if (*j == 0)
	{
		stack_a.container[*j] = number;
		*j += 1;
	}
	else
	{
		while (++i < *j)
		{
			if (number == stack_a.container[i])
			{
				stack_a.error = 1;
				break ;
			}
		}
		if (stack_a.error == 0)
		{
			stack_a.container[*j] = number;
			*j += 1;
		}
	}
	return (stack_a);
}

t_stack_a	check_error(int ac, char **av)
{
	int i;
	int j;
	t_stack_a stack_a;

	i = 1;
	stack_a.count = ac;
	stack_a.container = malloc(sizeof (int ) * stack_a.count);
	stack_a.error = 0;
	j = 0;
	while (i < ac)
	{
		if ((ft_atoi(av[i]) == 0 && check_zero(av[i]) == 1) || ft_atoi(av[i]) > INT32_MAX || ft_atoi((av[i])) < INT32_MIN)
		{
			if (j > 0)
				free(stack_a.container);
			stack_a.error = 1;
			return (stack_a);
		}
		stack_a = fill_check_dup(stack_a, &j, ft_atoi(av[i]));
		if (stack_a.error == 1)
		{
			free(stack_a.container);
			return (stack_a);
		}
		i += 1;
	}
	return (stack_a);
}

int main(int ac, char **av)
{
	t_stack_a stack_a;
	t_stack_b stack_b;
	//t_double_stack stack_d;

	int	i;

	i = 0;
	stack_a = check_error(ac, av);
	ft_memset(&stack_b, 0, sizeof (t_stack_b));
	if (stack_a.error == 1)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
//	while (i < (stack_a.count - 1))
//	{
//		printf("SA ==> %d\n", stack_a.container[i]);
//		i +=1;
//	}
//	i = 0;
//	printf("\n\n");
	algo_for_three(stack_a);
	while (i < (stack_a.count - 1))
	{
		printf("A ==> %d\n", stack_a.container[i]);
		i +=1;
	}
	i = 0;
	printf("\n\n");
	while (i < stack_b.count )
	{
		printf("B ==> %d\n", stack_b.container[i]);
		i +=1;
	}
/*	stack_a = rotate_a(stack_a);
	stack_a = swap_a(stack_a);*/
	return (0);
}
