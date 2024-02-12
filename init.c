/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:15:45 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/01/18 20:17:48 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stacks(char **argv, t_data *a, t_data *b)
{
	int	fill_stacks;
	int	count_number;

	count_number = ft_count_number(argv);
	if (!count_number)
		return (0);
	a->stack = (int *)malloc(sizeof(int) * count_number);
	a->len = ft_count_number(argv);
	if (!a->stack)
		exit(1);
	b->stack = (int *)malloc(sizeof(int) * count_number);
	b->len = 0;
	if (!b->stack)
	{
		free(a->stack);
		exit(1);
	}
	fill_stacks = fill_stack(argv, a, count_number);
	if (!fill_stacks)
	{
		free_both(a->stack, b->stack);
		return (0);
	}
	return (1);
}

int	ft_count_number(char **argv)
{
	int	count;
	int	i;
	int	j;

	if (!argv || !*argv)
		return (0);
	i = 1;
	count = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] != ' ') && ((argv[i][j + 1] == ' ') ||
				argv[i][j + 1] == '\0'))
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	fill_stack(char **argv, t_data *a, int count_numbers)
{
	long	num;
	int		i;
	int		j;
	char	**split_num;

	i = 1;
	while (count_numbers)
	{
		j = 0;
		split_num = ft_split(argv[i++], ' ');
		if (!split_num || !*split_num)
			return (free_array(split_num));
		while (split_num[j])
		{
			num = ft_atoi(split_num[j++]);
			if (num < -2147483648 || num > 2147483647)
				return (free_array(split_num));
			a->stack[count_numbers-- - 1] = (int)num;
		}
		free_array(split_num);
	}
	a->first = a->stack[a->len - 1];
	return (1);
}

int	count_kept_in_a(t_data a, int num)
{
	int	median;
	int	i;
	int	count;

	count = 0;
	median = position(a, num);
	i = median;
	while (i-- > 0)
	{
		if (a.stack[i] > num)
		{
			num = a.stack[i];
			count++;
		}
	}
	return (count);
}

void	sort_using_median(t_data *a, t_data	*b)
{
	int	median;
	int	last_kept;

	median = a->first;
	last_kept = median;
	rotate(a, 'a');
	while (a->first != median)
	{
		if (a->first > last_kept)
		{
			last_kept = a->first;
			rotate(a, 'a');
		}
		else
			push(a, b, 'b');
	}
	sort_b_then_sort_in_a(a, b);
}
