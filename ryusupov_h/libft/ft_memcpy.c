/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:26:02 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/25 19:29:47 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov.h"
/*
	ft_memcpy function copies n bytes from the source memory block to the
	destination memory block. It returns a pointer to the destination memory
	block.
*/
void	*ft_memcpy(void *to, const void *from, size_t n)
{
	size_t		i;
	char		*t;
	const char	*f;

	i = 0;
	t = (char *)to;
	f = (char *)from;
	while (i < n && (from || to))
	{
		t[i] = f[i];
		i++;
	}
	return (t);
}
