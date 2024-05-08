/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:34:29 by mac               #+#    #+#             */
/*   Updated: 2024/05/08 12:04:10 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ryusupov_h/ryusupov.h"

static void	content_position(t_ryusupov **stack)
{
	t_ryusupov	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->r_pos = i;
		tmp = tmp->next;
		i++;
	}
}

// static int get_target(t_ryusupov **r_stack, int b_idx,
//                       int t_i, int position)
// {
//     t_ryusupov *temp_a;
//     int found_target;

// 	found_target = 0;
//     temp_a = *r_stack;
//     while (temp_a)
//     {
//         if (!found_target && temp_a->i > b_idx && temp_a->i < t_i)
//         {
//             t_i = temp_a->i;
//             position = temp_a->r_pos;
//             found_target = 1;
//         }
//         else if (temp_a->i < t_i && temp_a->i > b_idx)
//         {
//             t_i = temp_a->i;
//             position = temp_a->r_pos;
//         }

// 		temp_a = temp_a->next;
//     }
//     return (position);
// }

static int	get_target(t_ryusupov **a, int b_idx,
								int target_idx, int target_pos)
{
	t_ryusupov	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->i > b_idx && tmp_a->i < target_idx)
		{
			target_idx = tmp_a->i;
			target_pos = tmp_a->r_pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->i < target_idx)
		{
			target_idx = tmp_a->i;
			target_pos = tmp_a->r_pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}


void	position(t_ryusupov **r_stack_a, t_ryusupov **r_stack_b)
{
	t_ryusupov	*temp_b;
	int		position;

	temp_b = *r_stack_b;
	content_position(r_stack_a);
	content_position(r_stack_b);
	position = 0;
	while (temp_b)
	{
		position = get_target(r_stack_a, temp_b->i, INT_MAX, position);
		temp_b->r_target_pos = position;
		temp_b = temp_b->next;
	}
}
