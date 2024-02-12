/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:29:27 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/01/18 20:17:18 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

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
void	both_rev_rotate(t_data *a, t_data *b);
void	both_swap(t_data *a, t_data *b);
void	sorting(t_data *a, t_data *b);
int		sorted(t_data *a);
void	sort_3(t_data *a);
void	sort_5(t_data *a, t_data *b);
void	sort_b_then_sort_in_a(t_data *a, t_data *b);
int		find_best_move(t_data a, t_data b);
int		moves_pos(t_data a, int num);
void	rotate_both(t_data *a, int a_top, t_data *b, int b_top);
void	set_rot(int *st_rot, int st_dir, int st_top, int st_len);
void	rotate_st(t_data *st, int st_dir, char st_name);
void	rotate_a_b(t_data *a, int a_dir, t_data *b, int b_dir);
void	min_top(t_data *st, char st_name);
int		count_kept_in_a(t_data a, int num);
void	sort_using_median(t_data *a, t_data	*b);
// error handling
void	ft_error_message(void);
int		free_array(char **str);
int		valid_arguments(char **argv);
void	free_both(int *stack_a, int *stack_b);
// others
int		ft_count_number(char **argv);
int		init_stacks(char **argv, t_data *a, t_data *b);
int		fill_stack(char **argv, t_data *a, int count_numbers);
int		ft_duplicate(t_data a);
int		position(t_data st, int current);
int		max(t_data num);
int		min(t_data num);