/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:25:54 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/25 19:29:38 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov.h"

/*
	ft_memchr function searches for the first occurrence of a byte with
	the specified value within a given memory block. It returns a pointer to the
	located byte if found, or NULL if the byte is not found within the specified
	number of bytes.
*/
void	*ft_memchr(const void *p, int i, size_t n)
{
	size_t				a;
	const unsigned char	*s;
	unsigned char		z;

	a = 0;
	s = p;
	z = (unsigned char)i;
	while (a < n)
	{
		if (s[a] == z)
		{
			return ((void *)(s + a));
		}
		a++;
	}
	return (NULL);
}
