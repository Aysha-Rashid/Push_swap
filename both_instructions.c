/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:08:44 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/01/17 17:42:29 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	both_rev_rotate(t_data *a, t_data *b)
{
	rev_rotate(a, 0);
	rev_rotate(b, 0);
	ft_printf("rrr\n");
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

void	rotate_both(t_data *a, int a_top, t_data *b, int b_top)
{
	int	a_dir;
	int	a_rot;
	int	b_dir;
	int	b_rot;

	a_dir = (a_top / (double)a->len) < 0.5;
	b_dir = (b_top / (double)b->len) < 0.5;
	set_rot(&a_rot, a_dir, a_top, a->len);
	set_rot(&b_rot, b_dir, b_top, b->len);
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
