/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:42:46 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/25 19:29:42 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov.h"

/*
	ft_memcmp function compares the content of two memory blocks byte by byte.
	If the bytes are not equal, it returns the difference between them.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*a1;
	const unsigned char	*a2;

	i = 0;
	a1 = (const unsigned char *)s1;
	a2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (a1[i] != a2[i])
		{
			return (a1[i] - a2[i]);
		}
		i++;
	}
	return (0);
}
