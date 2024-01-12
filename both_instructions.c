/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:08:44 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/01/11 16:41:27 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	both_rev_rotate(t_data *a, t_data *b)
{
	rev_rotate(a, 0);
	rev_rotate(b, 0);
	ft_printf("rr");
}

void	both_rotate(t_data *a, t_data *b)
{
	rotate(a, 0);
	rotate(b, 0);
	ft_printf("rr");
}

void	both_swap(t_data *a, t_data *b)
{
	swap(a, 0);
	swap(b, 0);
	ft_printf("ss");
}
