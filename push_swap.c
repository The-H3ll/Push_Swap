/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:25:15 by molabhai          #+#    #+#             */
/*   Updated: 2021/06/23 11:33:11 by molabhai         ###   ########.fr       */
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

t_stack 	fill_check_dup(t_stack stack_a, int *j, long number)
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

t_stack	check_error(int ac, char **av)
{
	int i;
	int j;
	t_stack stack_a;

	i = 1;
	stack_a.count = ac - 1;
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
	t_stack stack_a;
	t_stack stack_b;
	//t_double_stack ds;
	//t_double_stack stack_d;

	int	i;

	co = 0;
	i = 0;
	stack_a = check_error(ac, av);
	ft_memset(&stack_b, 0, sizeof (t_stack_b));
	if (stack_a.error == 1)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	if (stack_a.count == 2)
	 	stack_a = algo_for_two(stack_a);
	if (stack_a.count == 3)
	 	stack_a = algo_for_three(stack_a);
	 if (stack_a.count > 3 && stack_a.count <= 5)
	 	stack_a = algo_for_five(stack_a, stack_b);
	if (stack_a.count > 5 && stack_a.count <= 100)
		algo_for_(stack_a, stack_b);
	//stack_a = ds.stack_a;
	//stack_b = ds.stack_b;
	//reverse_rotate(stack_a);
	//reverse_rotate(stack_a);
	//rotate(stack_a);
// 	/*while (i < stack_a.count)
// 	{
// 		printf("A ==> %d\n", stack_a.container[i]);
// 		i +=1;
// 	}
// 	i = 0;
// 	printf("\n\n");
// 	while (i < stack_b.count)
// 	{
// 		printf("B ==> %d\n", stack_b.container[i]);
// 		i +=1;
// 	}
// /*	stack_a = rotate_a(stack_a);
// 	stack_a = swap_a(stack_a);*/
// 	printf("=================\ncount ==> %d\n", co);
	return (0);
}
