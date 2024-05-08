/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   huge_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:12:32 by ryusupov          #+#    #+#             */
/*   Updated: 2024/05/08 18:52:49 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ryusupov_h/ryusupov.h"

static void	lets_push(t_ryusupov **stack_a, t_ryusupov **stack_b)
{
	int	size;
	int	pushed;

	size = ft_lstsize(*stack_a);
	pushed = 0;
	while (size > 3 && pushed < size / 2)
	{
		if ((*stack_a)->i <= size / 2)
		{
			rule_pb(stack_a, stack_b);
			pushed++;
		}
		else
			rule_ra(stack_a);
	}
	while (pushed < size - 3)
	{
		rule_pb(stack_a, stack_b);
		pushed++;
	}
}

int	get_lowest_index(t_ryusupov **r_stack)
{
	t_ryusupov	*temp;
	int			lowest_index;
	int			lowest_pos;
	int			i;

	temp = *r_stack;
	lowest_index = INT_MAX;
	lowest_pos = -1;
	i = 0;
	while (temp)
	{
		temp->r_pos = i;
		if (temp->i < lowest_index)
		{
			lowest_index = temp->i;
			lowest_pos = i;
		}
		temp = temp->next;
		i++;
	}
	return (lowest_pos);
}

static void	shifting(t_ryusupov **stack_a)
{
	int	lowest_pos;
	int	size;

	size = ft_lstsize(*stack_a);
	lowest_pos = get_lowest_index(stack_a);
	if (lowest_pos > size / 2)
	{
		while (lowest_pos < size)
		{
			rule_rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			rule_ra(stack_a);
			lowest_pos--;
		}
	}
}

void	huge_sorting(t_ryusupov **r_stack_a, t_ryusupov **r_stack_b)
{
	lets_push(r_stack_a, r_stack_b);
	small_sorting(r_stack_a);
	while (*r_stack_b)
	{
		position(r_stack_a, r_stack_b);
		costs(r_stack_a, r_stack_b);
		make_cheapest_move(r_stack_a, r_stack_b);
	}
	if (!list_sorted(*r_stack_a))
		shifting(r_stack_a);
}
