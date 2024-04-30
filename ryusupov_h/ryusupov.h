/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ryusupov.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:21:53 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/30 18:59:47 by ryusupov         ###   ########.fr       */
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
/*-----------------FT_PRINTF---------------------*/
# include "./printf/ft_printf.h"
/*-----------------GET_NEXT_LINE------------------*/
// # include "get_next_line/get_next_line.h"
# include "get_next_line/get_next_line_bonus.h"
/*---------------LBFT FUNCTIONS------------------*/
# include "libftt/libft.h"

/*--------struct for the push_swap list---------*/
typedef struct s_ryusupov
{
	int					r_content;
	int					i;
	int					r_pos;
	int					r_target_pos;
	int					r_cost_a;
	int					r_cost_b;
	struct s_ryusupov	*next;
}						t_ryusupov;

int						correct_input(char **str);
void					content_index(t_ryusupov *r_stack_a, int size);

#endif
