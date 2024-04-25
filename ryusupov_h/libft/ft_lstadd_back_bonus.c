/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:35:36 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/25 19:28:49 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*new_n;

	if (!lst || !new)
	{
		return ;
	}
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	new_n = *lst;
	while (new_n->next != NULL)
	{
		new_n = new_n->next;
	}
	new_n->next = new;
}
