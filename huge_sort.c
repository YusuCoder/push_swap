/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   huge_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:12:32 by ryusupov          #+#    #+#             */
/*   Updated: 2024/05/08 12:01:51 by mac              ###   ########.fr       */
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
				rule_ra(r_stack_a);
		}
		else
			break ;
		i++;
	}
}

// static void	lets_push(t_ryusupov **stack_a, t_ryusupov **stack_b)
// {
// 	int	stack_size;
// 	int	pushed;
// 	int	i;

// 	stack_size = ft_lstsize(*stack_a);
// 	pushed = 0;
// 	i = 0;
// 	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
// 	{
// 		if ((*stack_a)->i <= stack_size / 2)
// 		{
// 			rule_pb(stack_a, stack_b);
// 			pushed++;
// 		}
// 		else
// 			rule_ra(stack_a);
// 		i++;
// 	}
// 	while (stack_size - pushed > 3)
// 	{
// 		rule_pb(stack_a, stack_b);
// 		pushed++;
// 	}
// }

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
// static void	get_position(t_ryusupov **stack)
// {
// 	t_ryusupov	*tmp;
// 	int		i;

// 	tmp = *stack;
// 	i = 0;
// 	while (tmp)
// 	{
// 		tmp->r_pos = i;
// 		tmp = tmp->next;
// 		i++;
// 	}
// }

// int	get_lowest_index(t_ryusupov **stack)
// {
// 	t_ryusupov	*tmp;
// 	int		lowest_index;
// 	int		lowest_pos;

// 	tmp = *stack;
// 	lowest_index = INT_MAX;
// 	get_position(stack);
// 	lowest_pos = tmp->r_pos;
// 	while (tmp)
// 	{
// 		if (tmp->i < lowest_index)
// 		{
// 			lowest_index = tmp->i;
// 			lowest_pos = tmp->r_pos;
// 		}
// 		tmp = tmp->next;
// 	}
// 	return (lowest_pos);
// }

static void	shifting(t_ryusupov **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = ft_lstsize(*stack_a);
	lowest_pos = get_lowest_index(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
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

// void	shifting(t_ryusupov **r_stack)
// {
// 	int	size;
// 	int	min_position;
// 	int	target_position;
// 	int	direction;

// 	size = ft_lstsize(*r_stack);
// 	min_position = get_lowest_index(r_stack);
// 	if (min_position > size / 2)
// 	{
// 		target_position = size;
// 		direction = -1;
// 	}
// 	else
// 	{
// 		target_position = 0;
// 		direction = 1;
// 	}
// 	while (min_position != target_position)
// 	{
// 		if (direction == -1)
// 			rule_rra(r_stack);
// 		else
// 			rule_ra(r_stack);
// 		min_position += direction;
// 	}
// }

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
