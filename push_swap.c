/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:43:39 by ryusupov          #+#    #+#             */
/*   Updated: 2024/05/08 11:33:25 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ryusupov_h/ryusupov.h"

// t_ryusupov	*stack_contents(int argc, char **argv)
// {
// 	t_ryusupov		*stack_a;
// 	long int	nb;
// 	int			i;

// 	stack_a = NULL;
// 	nb = 0;
// 	i = 1;
// 	while (i < argc)
// 	{
// 		nb = ft_atoi(argv[i]);
// 		if (nb > INT_MAX || nb < INT_MIN)
// 			exit (1);
// 		if (i == 1)
// 			stack_a = stack_new((int)nb);
// 		else
// 			buttom_stack(&stack_a, stack_new((int)nb));
// 		i++;
// 	}
// 	return (stack_a);
// }

static void	*stack_contents(int argc, char **argv)
{
	t_ryusupov	*r_stack_a;
	long int	num;
	int			i;

	r_stack_a = NULL;
	num = 0;
	i = 1;
	while (argc > i)
	{
		num = ft_atoi(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			free(r_stack_a);
			exit(EXIT_FAILURE);
		}
		if (i == 1)
			r_stack_a = stack_new((int)num);
		else
		{
			buttom_stack(&r_stack_a, stack_new((int)num));
			// ft_printf("hello");
		}
		i++;
	}
	return (r_stack_a);
}

static void	push_swap(t_ryusupov **r_stack_a, t_ryusupov **r_stack_b,
		int stack_size)
{
	if (stack_size == 2 && !list_sorted(*r_stack_a))
		rule_sa(r_stack_a);
	else if (stack_size == 3)
		small_sorting(r_stack_a);
	else if (stack_size > 3 && !list_sorted(*r_stack_a))
		huge_sorting(r_stack_a, r_stack_b);
}

int	main(int argc, char **argv)
{
	t_ryusupov	*r_stack_a;
	t_ryusupov	*r_stack_b;
	int			r_size;

	if (argc < 2)
	{
		ft_printf("Nothing to sort!\n");
		exit(EXIT_SUCCESS);
	}
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (!correct_input(argv))
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	r_stack_b = NULL;
	r_stack_a = stack_contents(argc, argv);
	r_size = ft_lstsize(r_stack_a);
	content_index(r_stack_a, r_size + 1);
	push_swap(&r_stack_a, &r_stack_b, r_size);
	free(r_stack_a);
	free(r_stack_b);
	return (0);
}
