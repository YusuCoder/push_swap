/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:43:19 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/25 19:29:03 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
	{
		return ;
	}
	del(lst->content);
	free(lst);
}
