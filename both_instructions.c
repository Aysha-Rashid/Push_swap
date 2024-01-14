/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:08:44 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/01/14 18:38:08 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	both_rev_rotate(t_data *a, t_data *b)
{
	rev_rotate(a, 0);
	rev_rotate(b, 0);
	ft_printf("rr\n");
}

void	both_rotate(t_data *a, t_data *b)
{
	rotate(a, 0);
	rotate(b, 0);
	ft_printf("rr\n");
}

void	both_swap(t_data *a, t_data *b)
{
	swap(a, 0);
	swap(b, 0);
	ft_printf("ss\n");
}

void	rotate_a_b(t_data *a, int a_dir, t_data *b, int b_dir)
{
	if (a_dir && b_dir)
		both_rev_rotate(a, b);
	else if (!a_dir && !b_dir)
		both_rotate(a, b);
	else if (a_dir && !b_dir)
	{
		rev_rotate(a, 'a');
		rotate(b, 'b');
	}
	else if (!a_dir && b_dir)
	{
		rotate(a, 'a');
		rev_rotate(b,'b');
	}
}

void	rotate_st(t_data *st, int st_dir, char st_name)
{
	if (st_dir)
		rev_rotate(st, st_name);
	else
		rotate(st, st_name);
}

void	set_rot(int *st_rot, int st_dir, int st_top, int st_len)
{
	*st_rot = st_top;
	if (!st_dir)
		*st_rot = st_len - st_top;
}

void	rotate_both(t_data *a, int a_top, t_data *b, int b_top)
{
	int	a_dir;
	int	a_rot;
	int	b_dir;
	int	b_rot;

	a_dir = (a_top / (double)a->len) < 0.5; // 1 means it's in the bottom end of the stack
	// ft_printf(" %d\n", a_dir);
	b_dir = (b_top / (double)b->len) < 0.5; // 0 means it's in the upper end of the stack
	set_rot(&a_rot, a_dir, a_top, a->len); // 0
	set_rot(&b_rot, b_dir, b_top, b->len); // 1
	while (a_rot || b_rot)
	{
		if (a_rot && b_rot)
			rotate_a_b(a, a_dir, b, b_dir);
		else if (a_rot)
			rotate_st(a, a_dir, 'a');
		else if (b_rot)
			rotate_st(b, b_dir, 'b');
		if (a_rot)
			a_rot--;
		if (b_rot)
			b_rot--;
	}
}

void	min_top(t_data *st, char st_name)
{
	int	min_pos;

	min_pos = position(*st, min(*st)) + 1;
	if ((min_pos) / (double)st->len < 0.5)
	{
		while (min_pos)
		{
			rev_rotate(st, st_name);
			min_pos--;
		}
	}
	else
	{
		min_pos = st->len - min_pos;
		while (min_pos)
		{
			rotate(st, st_name);
			min_pos--;
		}
	}
}
