/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:27:40 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/01/14 14:17:09 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sort from smallest to largest
// instruction must be seperated by \n
// maximum number of operations tolerated.
// if no parameters are specified, the program displays nothing and
// give immediate response
// in case of error, it should display 'Error\n' 
// error such as:
// 1. not integers
// 2. duplicate integer, argument being bigger than an integer

// to create a stack, we will need to create a linked list
// we will need doubly linked list (has a reference to the previous node)
// handling the integers in double or in single; they should be taken
// as seperate integer

int	main(int argc, char **argv)
{
	t_data	a;
	t_data	b;

	if (argc < 2)
		exit(0);
	else if (!init_stacks(argv, &a, &b))
		ft_error_message(&a, &b);
	else if (!valid_arguments(argv))
		ft_error_message(&a, &b);
	else if (ft_duplicate(a))
		ft_error_message(&a, &b);
	else
		sorting(&a, &b);
	free_both(a.stack, b.stack);
}
