/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:01:16 by ryusupov          #+#    #+#             */
/*   Updated: 2024/05/21 18:35:42 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ryusupov_h/ryusupov.h"

int	main(int argc, char **argv)
{
	t_ryusupov	*r_stack_a;
	t_ryusupov	*r_stack_b;
	int			r_size;

	r_stack_a = NULL;
	r_stack_b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		print_error_and_exit("Error!", EXIT_FAILURE);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = count_words(argv);
	}
	if (!correct_input(argv))
	{
		print_error_and_exit("Error!", EXIT_FAILURE);
	}
	r_stack_a = stack_contents(argc, argv);
	r_size = ft_lstsize(r_stack_a);
	content_index(r_stack_a, r_size + 1);
	push_swap(&r_stack_a, &r_stack_b, r_size);
	ft_lstclear(&r_stack_a, &free_content);
	ft_lstclear(&r_stack_b, &free_content);
	return (0);
}
