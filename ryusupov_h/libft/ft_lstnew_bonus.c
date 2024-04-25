/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:42:02 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/25 19:29:30 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov.h"

/*
	ft_lstnew function dynamically allocates memory for a new node,
	initializes the node with the given content, and returns a pointer
	to the new node.
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*link;

	link = (t_list *)malloc(sizeof(t_list));
	if (!link)
	{
		return (0);
	}
	link->content = content;
	link->next = NULL;
	return (link);
}
