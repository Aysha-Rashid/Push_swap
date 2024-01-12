/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:17:02 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/01/12 14:21:43 by ayal-ras         ###   ########.fr       */
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
	if (a->len <= 2)
		swap(a, 'a');
	if (a->len <= 3)
		sort_3(a);
	if (a->len <= 5)
		sort_5(a, b);
	else
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
	// write(1, "no_first", 8);
	if (a->stack[2] > a->stack[0] && a->stack[1] < a->stack[2])
		rotate(a, 'a');
	if (a->stack[2] < a->stack[1] && a->stack[1] > a->stack[0])
		rev_rotate(a, 'a');
	if (a->stack[2] > a->stack[1])
		swap(a, 'a');
	// printf("%d ", a->stack[0]);
	// printf("%d ", a->stack[1]);
	// printf("%d ", a->stack[2]);
	// printf("%d ", a->stack[3]);
	// printf("%d ", a->stack[4]);
	return ;
}

void	sort_5(t_data *a, t_data *b)
{
	// write(1, "1", 1);
	// (void) a;
	// (void) b;
	while (a->len > 3)
		push(a, b, 'b');
	sort_3(a);
	// printf("%d ", b->stack[2]);
	// printf("%d ", a->stack[3]);
	// printf("%d ", a->stack[4]);
	sort_in_b(b);
	// back_to_a(a);
}

void	sort_in_b(t_data *b)
{
	(void)b;
	// printf("%d ", b->stack[0]);
	// printf("%d ", b->stack[1]);
	// printf("%d ", b->stack[0]);
	// printf("%d ", b->stack[1]);
	// printf("%d ", b->stack[2]);
	// printf("%d", b->stack[0]);
	// printf("%d", b->stack[0]);
}