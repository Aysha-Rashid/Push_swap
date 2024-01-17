/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:52:16 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/01/17 13:21:10 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_message(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

int	free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (0);
}

void	free_both(int *stack_a, int *stack_b)
{
	free(stack_a);
	free(stack_b);
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
