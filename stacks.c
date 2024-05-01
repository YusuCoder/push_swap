/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:44:33 by ryusupov          #+#    #+#             */
/*   Updated: 2024/05/01 12:18:27 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ryusupov_h/ryusupov.h"

t_ryusupov	*get_buttom_stack(t_ryusupov *r_stack)
{
	while (r_stack && r_stack->next != NULL)
	{
		r_stack = r_stack->next;
	}
	return (r_stack);
}

void	buttom_stack(t_ryusupov **r_stach_a, t_ryusupov *new)
{
	t_ryusupov	*tail;

	if (!new)
		exit(EXIT_FAILURE);
	if (!*r_stach_a)
	{
		*r_stach_a = new;
		return ;
	}
	tail = get_bottom_stack(*r_stach_a);
	tail->next = new;
}

t_ryusupov	*stack_new(int str)
{
	t_ryusupov	*new;

	new = malloc(sizeof(t_ryusupov));
	if (!new)
		return (NULL);
	new->r_content;
	new->i = 0;
	new->r_pos = -1;
	new->r_target_pos = -1;
	new->r_cost_a = -1;
	new->r_cost_a = -1;
	new->next = NULL;
	return (new);
}
