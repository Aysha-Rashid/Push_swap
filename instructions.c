/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:06:01 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/01/13 13:29:49 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_data *a, int letter)
{
	int	temp;

	if (a->len > 1)
	{
		temp = a->stack[a->len - 1];
		a->stack[a->len - 1] = a->stack[a->len - 2];
		a->stack[a->len - 2] = temp;
	}
	a->first = a->stack[a->len - 1];
	if (letter)
		ft_printf("s%c\n", letter);
}

void	rotate(t_data *a, int letter)
{
	int	first;
	int	i;

	i = a->len - 1;
	first = a->stack[a->len - 1];
	while (i > 0)
	{
		a->stack[i] = a->stack[i - 1];
		i--;
	}
	a->stack[0] = first;
	if (letter)
		ft_printf("r%c\n", letter);
}

void	push(t_data *a, t_data	*b, int letter)
{
	b->stack[b->len] = a->stack[a->len - 1];
	// printf("%d ", b->len);
	b->len++;
	a->len--;
	b->first = b->stack[b->len - 1];
	ft_printf("p%c\n", letter);
}
