/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:35:25 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/25 19:29:51 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov.h"

/*
	ft_memmove function copies len bytes from the source memory block to the
	destination memory block.
	1 - It iterates from the beginning of the memory blocks (s) to the end (s + len)
	and copies each byte from s to d.
	If the destination memory block starts after the source memory block (d > s),
	it means that the memory areas overlap and the copying must be done backwards
	to avoid overwriting data that has not been copied yet. In this case:
*/

void	*ft_memmove(void *to, const void *from, size_t len)
{
	char	*d;
	char	*s;

	if (to == NULL && from == NULL)
	{
		return (NULL);
	}
	d = (char *)to;
	s = (char *)from;
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		d += len - 1;
		s += len - 1;
		while (len--)
			*d-- = *s--;
	}
	return (to);
}
