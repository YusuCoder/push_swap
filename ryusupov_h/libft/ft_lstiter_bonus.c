/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:47:18 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/25 19:29:10 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov.h"

/*	The ft_lstiter function iterates through each element
	of a linked list and applies a given function (f) to the content
	of each node. It allows for performing some action on each element
	of the list without directly accessing or modifying the list structure itself.
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
	{
		return ;
	}
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
