/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:26:07 by ryusupov          #+#    #+#             */
/*   Updated: 2024/05/11 20:02:19 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

int	num_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

static int	calculate_move_cost(int cost_a, int cost_b)
{
	return (num_abs(cost_a) + num_abs(cost_b));
}

static void	find_cheapest_move(t_ryusupov *stack_b, int *cheapest_a,
		int *cheapest_b)
{
	t_ryusupov	*temp;
	int			cheapest_move;
	int			total_cost;

	temp = stack_b;
	cheapest_move = INT_MAX;
	while (temp != NULL)
	{
		total_cost = calculate_move_cost(temp->r_cost_a, temp->r_cost_b);
		if (total_cost < cheapest_move)
		{
			cheapest_move = total_cost;
			*cheapest_a = temp->r_cost_a;
			*cheapest_b = temp->r_cost_b;
		}
		temp = temp->next;
	}
}

void	make_cheapest_move(t_ryusupov **r_stack_a, t_ryusupov **r_stack_b)
{
	int	cheapest_a;
	int	cheapest_b;

	find_cheapest_move(*r_stack_b, &cheapest_a, &cheapest_b);
	move(r_stack_a, r_stack_b, cheapest_a, cheapest_b);
}

void	costs(t_ryusupov **r_stack_a, t_ryusupov **r_stack_b)
{
	t_ryusupov	*stack_a;
	t_ryusupov	*stack_b;
	int			size_a;
	int			size_b;

	stack_a = *r_stack_a;
	stack_b = *r_stack_b;
	size_a = ft_lstsize(stack_a);
	size_b = ft_lstsize(stack_b);
	while (stack_b)
	{
		stack_b->r_cost_b = stack_b->r_pos;
		if (stack_b->r_pos > size_b / 2)
			stack_b->r_cost_b = (size_b - stack_b->r_pos) * -1;
		stack_b->r_cost_a = stack_b->r_target_pos;
		if (stack_b->r_target_pos > size_a / 2)
			stack_b->r_cost_a = (size_a - stack_b->r_target_pos) * -1;
		stack_b = stack_b->next;
	}
}