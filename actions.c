/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:29:38 by ryusupov          #+#    #+#             */
/*   Updated: 2024/05/08 22:24:22 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ryusupov_h/ryusupov.h"

void	rotate_or_reverse(t_ryusupov **r_stack_a,
		t_ryusupov **r_stack_b, int *a_cost, int *b_cost)
{
	while ((*a_cost != 0 || *b_cost != 0) && (*a_cost < 0 || *b_cost < 0)
		&& (*a_cost > 0 || *b_cost > 0))
	{
		if (*a_cost < 0 && *b_cost < 0)
		{
			(*a_cost)++;
			(*b_cost)++;
			rule_rrr(r_stack_a, r_stack_b);
		}
		else if (*a_cost > 0 && *b_cost > 0)
		{
			(*a_cost)--;
			(*b_cost)--;
			rule_rr(r_stack_a, r_stack_b);
		}
	}
}

void	rotate(t_ryusupov **r_stack, int *a_cost, void (*rule_r)(t_ryusupov **),
		void (*rule_rr)(t_ryusupov **))
{
	while (*a_cost)
	{
		if (*a_cost > 0)
		{
			rule_r(r_stack);
			(*a_cost)--;
		}
		else if (*a_cost < 0)
		{
			rule_rr(r_stack);
			(*a_cost)++;
		}
	}
}

void	move(t_ryusupov **r_stack_a, t_ryusupov **r_stack_b, int cost_a,
		int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
	{
		rotate_or_reverse(r_stack_a, r_stack_b, &cost_a, &cost_b);
	}
	else if (cost_a > 0 && cost_b > 0)
	{
		rotate_or_reverse(r_stack_a, r_stack_b, &cost_a, &cost_b);
	}
	rotate(r_stack_a, &cost_a, rule_ra, rule_rra);
	rotate(r_stack_b, &cost_b, rule_rb, rule_rrb);
	rule_pa(r_stack_a, r_stack_b);
}
