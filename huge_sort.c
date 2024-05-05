/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   huge_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:12:32 by ryusupov          #+#    #+#             */
/*   Updated: 2024/05/05 20:57:29 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ryusupov_h/ryusupov.h"

void	lets_push(t_ryusupov **r_stack_a, t_ryusupov **r_stack_b)
{
	int	size;
	int	push;
	int	i;

	size = list_sorted(*r_stack_a);
	push = 0;
	i = 0;
	while (i < size)
	{
		if ((size > 6 && push < size / 2) || (size - push > 3))
		{
			if ((*r_stack_a)->i <= size / 2)
			{
				rule_pb(r_stack_a, r_stack_b);
				push++;
			}
			else
				rule_ra_rb(r_stack_a, 'a');
		}
		else
			break ;
		i++;
	}
}

void	shift_stack(t_ryusupov **r_stack)
{
	int	size;
	int	min_position;
	int	target_position;
	int	direction;

	size = ft_lstsize(*r_stack);
	min_position = get_lowest_index(r_stack);
	if (min_position > size / 2)
	{
		target_position = size;
		direction = -1;
	}
	else
	{
		target_position = 0;
		direction = 1;
	}
	while (min_position != target_position)
	{
		if (direction == -1)
			rule_rra(r_stack);
		else
			rule_ra_rb(r_stack, 'a');
		min_position += direction;
	}
}

void	huge_sorting(t_ryusupov **r_stack_a, t_ryusupov **r_stack_b)
{
	lets_push(r_stack_a, r_stack_b);
	small_sorting(r_stack_a);
	while (*r_stack_b)
	{
		get_positions(r_stack_a, r_stack_b);
		get_costs(r_stack_a, r_stack_b);
		smallest_move(r_stack_a, r_stack_b);
	}
	if (!list_sorted(*r_stack_a))
		;
	shift_stack(r_stack_a);
}
