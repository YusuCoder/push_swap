/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:28:18 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/25 19:30:51 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov.h"

/*
	ft_strlcat appends the string from to the end of the string to,
	ensuring that the resulting string is properly null-terminated
	and fits within the provided buffer size dstsize. It returns the total
	length of the resulting string (excluding the null terminator)
*/

size_t	ft_strlcat(char *to, const char *from, size_t dstsize)
{
	size_t	a;
	size_t	dlen;

	if (dstsize <= ft_strlen(to))
	{
		return (dstsize + ft_strlen(from));
	}
	a = ft_strlen(to);
	dlen = 0;
	while (from[dlen] != '\0' && a + 1 < dstsize)
	{
		to[a] = from[dlen];
		a++;
		dlen++;
	}
	to[a] = '\0';
	return (ft_strlen(to) + ft_strlen(&from[dlen]));
}
