/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:26:51 by ryusupov          #+#    #+#             */
/*   Updated: 2024/05/11 20:02:42 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

static void	pushing(t_ryusupov **src, t_ryusupov **dest)
{
	t_ryusupov	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

void	rule_pa(t_ryusupov **r_stack_a, t_ryusupov **r_stack_b)
{
	pushing(r_stack_b, r_stack_a);
	ft_printf("pa\n");
}

void	rule_pb(t_ryusupov **r_stack_a, t_ryusupov **r_stack_b)
{
	pushing(r_stack_a, r_stack_b);
	ft_printf("pb\n");
}
