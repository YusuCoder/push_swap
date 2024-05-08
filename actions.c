/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:29:38 by ryusupov          #+#    #+#             */
/*   Updated: 2024/05/08 12:06:34 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ryusupov_h/ryusupov.h"

void	reverse_rotate_a_b(t_ryusupov **r_stack_a, t_ryusupov **r_stack_b,
		int *a_cost, int *b_cost)
{
	while (*a_cost < 0 && *b_cost < 0)
	{
		(*a_cost)++;
		(*b_cost)++;
		rule_rrr(r_stack_a, r_stack_b);
	}
}

void	rotate_a_b(t_ryusupov **r_stack_a, t_ryusupov **r_stack_b, int *a_cost,
		int *b_cost)
{
	while (*a_cost > 0 && *b_cost > 0)
	{
		(*a_cost)--;
		(*b_cost)--;
		rule_rr(r_stack_a, r_stack_b);
	}
}

// void	rotate_rev_a_b(t_ryusupov **r_stack_a, t_ryusupov **r_stack_b, int *a_cost,
// 		int *b_cost)
// {
// 	while (*a_cost != 0 && *b_cost != 0)
// 	{
// 		if (*a_cost > 0 && *b_cost > 0)
// 		{
// 			(*a_cost)--;
// 			(*b_cost)--;
// 		}
// 		else if (*a_cost < 0 && *b_cost < 0)
// 		{
// 			(*a_cost)++;
// 			(*b_cost)++;
// 		}
// 		rule_rr(r_stack_a, r_stack_b);
// 	}
// }

void	rotate_a(t_ryusupov **r_stack_a, int *a_cost)
{
	while (*a_cost)
	{
		if (*a_cost > 0)
		{
			rule_ra(r_stack_a);
			(*a_cost)--;
		}
		else if (*a_cost < 0)
		{
			rule_rra(r_stack_a);
			(*a_cost)++;
		}
	}
}

void	rotate_b(t_ryusupov **r_stack_b, int *a_cost)
{
	while (*a_cost)
	{
		if (*a_cost > 0)
		{
			rule_rb(r_stack_b);
			(*a_cost)--;
		}
		else if (*a_cost < 0)
		{
			rule_rrb(r_stack_b);
			(*a_cost)++;
		}
	}
}

void	move(t_ryusupov **r_stack_a, t_ryusupov **r_stack_b, int cost_a,
		int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
	{
		reverse_rotate_a_b(r_stack_a, r_stack_b, &cost_a, &cost_b);
	}
	else if (cost_a > 0 && cost_b > 0)
	{
		rotate_a_b(r_stack_a, r_stack_b, &cost_a, &cost_b);
	}
	rotate_a(r_stack_a, &cost_a);
	rotate_b(r_stack_b, &cost_b);
	rule_pa(r_stack_a, r_stack_b);
}
