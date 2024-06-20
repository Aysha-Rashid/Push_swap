/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:24:08 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/06/20 21:22:57 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_data *a, int letter)
{
	int	last;
	int	i;

	last = a->stack[0];
	i = 0;
	while (i < a->len - 1)
	{
		a->stack[i] = a->stack[i + 1];
		i++;
	}
	a->stack[a->len - 1] = last;
	a->first = a->stack[a->len - 1];
	if (letter)
		ft_printf("rr%c\n", letter);
}

void	rotate_a_b(t_data *a, int a_dir, t_data *b, int b_dir)
{
	if (a_dir && b_dir)
		both_rev_rotate(a, b, 1);
	else if (!a_dir && !b_dir)
		both_rotate(a, b, 1);
	else if (a_dir && !b_dir)
	{
		rev_rotate(a, 'a');
		rotate(b, 'b');
	}
	else if (!a_dir && b_dir)
	{
		rotate(a, 'a');
		rev_rotate(b, 'b');
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
