/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:17:02 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/01/14 18:38:03 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
// ss : sa and sb at the same time.
// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
// rr : ra and rb at the same time.
// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
// rrr : rra and rrb at the same time.

void	sorting(t_data *a, t_data *b)
{
	// (void)b;
	if (sorted(a))
		return ;
	else if (a->len <= 2)
		swap(a, 'a');
	else if (a->len <= 3)
		sort_3(a);
	else if (a->len <= 5)
		sort_5(a, b);
	else if (a->len > 5)
		ft_printf("not sorted");
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
	// (void) a;
	// (void) b;
	while (a->len > 3)
		push(a, b, 'b');
	sort_3(a);
	sort_b_then_sort_in_a(a, b);
}

void	sort_b_then_sort_in_a(t_data *a, t_data *b)
{
	int	best_move;
	int	move_pos;

	while(b->len)
	{
		best_move = find_best_move(*a, *b);
		move_pos = moves_pos(*a, best_move);
		rotate_both(a, move_pos, b, position(*b, best_move) + 1);
		push(b, a,'a');
	}
	min_top(a, 'a');
}

int	find_best_move(t_data a, t_data b)
{
	int i;
	int	best_move;
	int	no_of_op;
	int	best_move_pos;

	i = 0;
	while (i < b.len)
	{
		no_of_op = moves_pos(a, b.stack[b.len - 1 - i]);
		if (no_of_op / (double)a.len >= 0.5)
			no_of_op = a.len - no_of_op;
		if (i / (double)b.len < 0.5)
			no_of_op +=  i;
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

int	max(t_data num)
{
	int	i;
	int	max;

	i = 0;
	max = num.stack[i];
	while (i < num.len)
	{
		if (max < num.stack[i])
			max = num.stack[i];
		i++;
	}
	return (max);
}

int	min(t_data num)
{
	int	i;
	int	min;

	i = 0;
	min = num.stack[i];
	while (i < num.len)
	{
		if (min > num.stack[i])
			min = num.stack[i];
		i++;
	}
	return (min);
}
