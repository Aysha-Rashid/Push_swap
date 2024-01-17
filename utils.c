/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 21:01:34 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/01/17 13:27:32 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_arguments(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != ' ')
			{
				if (argv[i][j] == '-')
					j++;
				if (!ft_isdigit(argv[i][j]))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_duplicate(t_data a)
{
	int	i;

	i = 0;
	while (a.len > i)
	{
		if (position(a, a.stack[i]) != i)
			return (1);
		i++;
	}
	return (0);
}

int	position(t_data st, int current)
{
	int	i;

	i = 0;
	while (st.len > i)
	{
		if (st.stack[i] == current)
			return (i);
		i++;
	}
	return (0);
}

int	find_best_move(t_data a, t_data b)
{
	int	i;
	int	best_move;
	int	no_of_op;
	int	best_move_pos;

	i = 0;
	best_move = -1;
	best_move_pos = -1;
	while (i < b.len)
	{
		no_of_op = moves_pos(a, b.stack[b.len - 1 - i]);
		if (no_of_op / (double)a.len >= 0.5)
			no_of_op = a.len - no_of_op;
		if (i / (double)b.len < 0.5)
			no_of_op += i;
		else
			no_of_op += b.len - i;
		if (best_move < 0 || no_of_op < best_move)
		{
			best_move = no_of_op;
			best_move_pos = b.stack[b.len - 1 - i];
		}
		i++;
	}
	return (best_move_pos);
}

int	moves_pos(t_data a, int num)
{
	int	i;
	int	previous;
	int	current;

	i = 0;
	previous = -1;
	current = -1;
	while (a.len > i)
	{
		current = a.stack[i];
		if (i == 0)
			previous = a.stack[a.len - 1];
		else
			previous = a.stack[i - 1];
		if (num > max(a) && current == max(a))
			return (i);
		else if (num < min(a) && previous == min(a))
			return (i);
		else if (num > current && num < previous)
			return (i);
		i++;
	}
	return (0);
}
