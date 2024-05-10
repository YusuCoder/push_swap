/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ryusupov.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:21:53 by ryusupov          #+#    #+#             */
/*   Updated: 2024/05/10 19:04:36 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RYUSUPOV_H
# define RYUSUPOV_H
/*-----Text Style------*/
# define BOLD "\x1b[1m"
# define UNDERLINE "\x1b[4m"
# define ITALIC "\x1b[3m"
# define RESET "\x1b[0m"
/*-----Text Color-----*/
# define COLOR_RED "\x1b[31m"
# define COLOR_GREEN "\x1b[32m"
# define COLOR_YELLOW "\x1b[33m"
# define COLOR_BLUE "\x1b[24m"
# define COLOR_MAGENTA "\x1b[35m"
# define COLOR_CYAN "\x1b[36m"
# define COLOR_WHITE "\x1b[97m"
# define RESET "\x1b[0m"
/*-----Helper libs------*/
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
/*-----------------LEAK DEDECTOR-----------------*/
// # include "../leak_detector/mem.h"
/*-----------------FT_PRINTF---------------------*/
# include "./printf/ft_printf.h"
/*---------------LBFT FUNCTIONS------------------*/
# include "libftt/libft.h"
/*-----------------------Initializations-----------------------*/
t_ryusupov	*stack_new(int str);
void		small_sorting(t_ryusupov **r_stack);
void		buttom_stack(t_ryusupov **r_stach_a, t_ryusupov *new);
void		content_index(t_ryusupov *r_stack_a, int size);
void		*stack_contents(int argc, char **argv);
void		push_swap(t_ryusupov **r_stack_a, t_ryusupov **r_stack_b,
				int stack_size);
void		huge_sorting(t_ryusupov **r_stack_a, t_ryusupov **r_stack_b);
void		position(t_ryusupov **r_stack_a, t_ryusupov **r_stack_b);
void		costs(t_ryusupov **r_stack_a, t_ryusupov **r_stack_b);
void	make_cheapest_move(t_ryusupov **r_stack_a,
						t_ryusupov **r_stack_b);
void		move(t_ryusupov **r_stack_a, t_ryusupov **r_stack_b, int cost_a,
				int cost_b);
/*-----------------------The rules-----------------------*/
void		rule_sa_sb(t_ryusupov **r_stack, char option);
void		rule_ss(t_ryusupov **r_stack, t_ryusupov **r_stack_b);
void		rule_rb(t_ryusupov **r_stack);
void		rule_ra(t_ryusupov **r_stack);
void		rule_rr(t_ryusupov **r_stack_a, t_ryusupov **r_stack_b);
void		rule_rra(t_ryusupov **r_stack);
void		rule_rrb(t_ryusupov **r_stack);
void		rule_pb(t_ryusupov **r_stack_a, t_ryusupov **r_stack_b);
void		rule_pa(t_ryusupov **r_stack_a, t_ryusupov **r_stack_b);
void	rule_rrr(t_ryusupov **r_stack_a,
				t_ryusupov **r_stack_b);
/*-----------------------Helper functions-----------------------*/
int			correct_input(char **str);
void		free_content(void *node);
size_t		count_words(char **words);
void		print_error_and_exit(const char *message, int exit_code);
#endif
