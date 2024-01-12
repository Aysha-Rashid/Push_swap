/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 21:01:34 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/01/10 21:12:39 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_message(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

int	valid_arguments(char **argv, t_data a)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != ' ')
			{
				if (argv[i][j] == '-')
					j++;
				if (!ft_isdigit(argv[i][j]) || ft_duplicate(a))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_duplicate(t_data a)
{
	int	i;

	i = 0;
	while (a.len > i)
	{
		if (position(a, a.stack[i]) != i)
			return (1);
		i++;
	}
	return (0);
}

int	position(t_data a, int current)
{
	int	i;

	i = 0;
	while (a.len > i)
	{
		if (a.stack[i] == current)
			return (i);
		i++;
	}
	return (0);
}
