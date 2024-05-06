/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:34:29 by mac               #+#    #+#             */
/*   Updated: 2024/05/06 21:29:23 by mac              ###   ########.fr       */
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
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

static int get_target(t_ryusupov **r_stack, int b_idx,
                      int t_index, int position)
{
    t_ryusupov *temp_a;
    int found_target;

	found_target = 0;
    temp_a = *a;
    while (tmp_a)
    {
        if (!found_target && temp_a->i > b_idx && temp_a->i < t_index)
        {
            t_index = temp_a->i;
            position = temp_a->pos;
            found_target = 1;
        }
        else if (temp_a->i < t_index && temp_a->i > b_idx)
        {
            t_index = temp_a->i;
            position = temp_a->pos;
        }
        tmp_a = temp_a->next;
    }
    return (position);
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
		temp_b->position = position;
		temp_b = temp_b->next;
	}
}
