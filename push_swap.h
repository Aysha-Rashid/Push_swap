/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:29:27 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/01/12 13:34:51 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_data
{
	int	*stack;
	int	len;
	int	first;
}				t_data;

// sorting function
void	swap(t_data *a, int letter);
void	push(t_data *a, t_data	*b, int letter);
void	rotate(t_data *a, int letter);
void	rev_rotate(t_data *a, int letter);
void	both_rotate(t_data *a, t_data *b);
void	both_swap(t_data *a, t_data *b);
void	sorting(t_data *a, t_data *b);
int		sorted(t_data *a);
void	sort_3(t_data *a);
void	sort_5(t_data *a, t_data *b);
void	sort_in_b(t_data *b);
// error handling
void	ft_error_message(void);
int		free_array(char **str);
int		valid_arguments(char **argv, t_data a);
void	free_both(int *stack_a, int *stack_b);
// others
int		ft_count_number(char **argv);
int		init_stacks(char **argv, t_data *a, t_data *b);
int		fill_stack(char **argv, t_data *a, int count_numbers);
int		ft_duplicate(t_data a);
int		position(t_data a, int current);
// void	bubbleSort(int arr[], int len);
// int	ft_duplicate(char *str, char c, int len);