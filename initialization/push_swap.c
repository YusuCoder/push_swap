/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:43:39 by ryusupov          #+#    #+#             */
/*   Updated: 2024/05/17 20:40:55 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

void	*stack_contents(int argc, char **argv)
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
		}
		i++;
	}
	return (r_stack_a);
}

void	push_swap(t_ryusupov **r_stack_a, t_ryusupov **r_stack_b,
		int stack_size)
{
	if (stack_size == 2 && !list_sorted(*r_stack_a))
		rule_sa_sb(r_stack_a, 'a');
	else if (stack_size == 3)
		small_sorting(r_stack_a);
	else if (stack_size > 3 && !list_sorted(*r_stack_a))
		huge_sorting(r_stack_a, r_stack_b);
}
