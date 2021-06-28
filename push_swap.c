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

	if ((s[0] == '-' && ft_isdigit(s[1]) == 0)
		|| (s[0] == '+' && ft_isdigit(s[1]) == 0))
		return (1);
	i = s[0] - '0';
	if (i == 0 || i == -3 || i == -5)
		return (0);
	return (1);
}

t_stack 	fill_check_dup(t_stack stack_a, int *j, long number)
{
	int	i;

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

t_stack	check_error(int ac, char **av, t_stack stack_a)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		if ((ft_atoi(av[i]) == 0 && check_zero(av[i]) == 1)
			|| ft_atoi(av[i]) > INT32_MAX || ft_atoi((av[i])) < INT32_MIN)
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

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a.count = ac - 1;
	stack_a.container = malloc(sizeof (int ) * stack_a.count);
	stack_a.error = 0;
	stack_a = check_error(ac, av, stack_a);
	ft_memset(&stack_b, 0, sizeof (t_stack));
	if (stack_a.error == 1)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	if (stack_a.count == 1 || dont_sort(stack_a) == 0)
		return (0);
	else if (stack_a.count == 2)
		stack_a = algo_for_two(stack_a);
	else if (stack_a.count == 3)
		stack_a = algo_for_three(stack_a);
	else if (stack_a.count > 3 && stack_a.count <= 5)
		stack_a = algo_for_five(stack_a, stack_b);
	else
		stack_a = algo_for_(stack_a, stack_b);
	return (0);
}
