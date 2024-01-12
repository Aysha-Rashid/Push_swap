/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:24:08 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/01/12 13:54:40 by ayal-ras         ###   ########.fr       */
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
		// printf("%d", a->stack[0]);
		// printf("%d", a->stack[1]);
		// printf("%d", a->stack[2]);
	if (letter)
		ft_printf("rr%c\n", letter);
}