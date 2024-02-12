/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:27:40 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/01/19 19:22:15 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	a;
	t_data	b;

	if (argc < 2)
		return (0);
	else if (!init_stacks(argv, &a, &b))
		ft_error_message();
	else if (!valid_arguments(argv))
	{
		free_both(a.stack, b.stack);
		ft_error_message();
	}
	else if (ft_duplicate(a))
	{
		free_both(a.stack, b.stack);
		ft_error_message();
	}
	else
		sorting(&a, &b);
	free_both(a.stack, b.stack);
}
