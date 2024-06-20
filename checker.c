/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 21:10:39 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/06/20 21:48:00 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char	*s1, const char	*s2)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] && s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char) s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	compare(char *line, t_data	*a, t_data	*b)
{
	if (!(ft_strcmp(line, "sa\n")))
		swap(a, 0);
	else if (!(ft_strcmp(line, "sb\n")))
		swap(b, 0);
	else if (!(ft_strcmp(line, "ss\n")))
		both_swap(a, b, 0);
	else if (!(ft_strcmp(line, "rrr\n")))
		both_rev_rotate(a, b, 0);
	else if (!(ft_strcmp(line, "rr\n")))
		both_rotate(a, b, 0);
	else if (!(ft_strcmp(line, "ra\n")))
		rotate(a, 0);
	else if (!(ft_strcmp(line, "rb\n")))
		rotate(b, 0);
	else if (!(ft_strcmp(line, "pa\n")))
		push(a, b, 0);
	else if (!(ft_strcmp(line, "pb\n")))
		push(b, a, 0);
	else
	{
		if (line[0] != '\0' || ft_strcmp(line, "\n"))
			(ft_putstr_fd("ERROR\n", 2), exit(0));
	}
}

int	main(int argc, char **argv)
{
	t_data	a;
	t_data	b;
	char	*line;

	(void)argc;
	if (argc < 2)
		return (0);
	if (!init_stacks(argv, &a, &b))
		ft_error_message();
	else if (!valid_arguments(argv))
		(free_both(a.stack, b.stack), ft_error_message());
	else if (ft_duplicate(a))
		(free_both(a.stack, b.stack), ft_error_message());
	line = get_next_line(0);
	while (line)
	{
		(compare(line, &a, &b), free(line));
		line = get_next_line(0);
	}
	if (sorted(&a))
		ft_putstr_fd("OK\n", 2);
	else
		ft_putstr_fd("KO\n", 2);
	free_both(a.stack, b.stack);
}
