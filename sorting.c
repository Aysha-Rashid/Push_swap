/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:17:02 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/01/17 19:07:30 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_data *a, t_data *b)
{
	if (sorted(a))
		return ;
	else if (a->len == 2)
		swap(a, 'a');
	else if (a->len <= 3)
		sort_3(a);
	else if (a->len <= 5)
		sort_5(a, b);
	else
	{
		if (count_kept_in_a(*a, a->first) > 3)
			sort_using_median(a, b);
		else
			sort_5(a, b);
	}
}

int	sorted(t_data *a)
{
	int	i;

	i = 0;
	while (a->len - 1 > i)
	{
		if (a->stack[i] < a->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sort_3(t_data *a)
{
	if (a->stack[2] > a->stack[0] && a->stack[1] < a->stack[2])
		rotate(a, 'a');
	if (a->stack[2] < a->stack[1] && a->stack[1] > a->stack[0])
		rev_rotate(a, 'a');
	if (a->stack[2] > a->stack[1])
		swap(a, 'a');
	return ;
}

void	sort_5(t_data *a, t_data *b)
{
	while (a->len > 3)
		push(a, b, 'b');
	sort_3(a);
	sort_b_then_sort_in_a(a, b);
}

void	sort_b_then_sort_in_a(t_data *a, t_data *b)
{
	int	best_move;
	int	move_pos;

	while (b->len)
	{
		best_move = find_best_move(*a, *b);
		move_pos = moves_pos(*a, best_move);
		rotate_both(a, move_pos, b, position(*b, best_move) + 1);
		push(b, a, 'a');
	}
	min_top(a, 'a');
}
