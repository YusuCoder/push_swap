/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:13:14 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/25 19:30:56 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov.h"

/*
	ft_strlcpy copies the source string from to the destination string source,
	ensuring proper null-termination of the destination string and limiting
	the copy operation to dstsize - 1 characters. It returns the length of
	the source string.
*/

size_t	ft_strlcpy(char *to, const char *from, size_t dstsize)
{
	size_t	s;

	s = 0;
	while (from[s] != '\0')
	{
		s++;
	}
	while (dstsize--)
	{
		if (dstsize == 0 || *from == '\0')
		{
			*to = '\0';
			break ;
		}
		*to = *from;
		to++;
		from++;
	}
	return (s);
}
