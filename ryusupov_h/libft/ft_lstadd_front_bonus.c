/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:21:13 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/25 19:28:54 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
	{
		return ;
	}
	new->next = *lst;
	*lst = new;
}
