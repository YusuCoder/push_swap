/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:43:39 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/28 17:12:35 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ryusupov_h/ryusupov.h"

static void	push_swap(t_ryusupov **r_stack_a, t_ryusupov **r_stack_b,
		int stack_size)
{
	if (stack_size == 2 && !list_sorted(*r_stack_a))
		option_sa(r_stack_a);
	else if (stack_size == 3)
		small_sorting(r_stack_a);
	else if (stack_size > 3)
		huge_sorting(r_stack_a);
}

int	main(int argc, char **argv)
{
	t_ryusupov	*r_stack_a;
	t_ryusupov	*r_stack_b;
	int			r_size;

	if (argc < 2)
	{
		ft_printf("Nothing to sort!");
		return (0);
	}
	if (!correct_input(argv))
		exit_program(NULL, NULL);
	r_stack_b = NULL;
	r_stack_a = stack_contents(argc, argv);
	r_size = stack_size(r_stack_a);
	content_index(r_stack_a, r_size + 1);
	push_swap(&r_stack_a, &r_stack_b, r_size);
	return (0);
}
