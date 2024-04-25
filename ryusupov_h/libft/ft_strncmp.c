/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:33:59 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/25 19:31:13 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov.h"

/*
	ft_strncmp compares the first n characters of two strings s1 and s2
	and returns an integer indicating their relative order.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*a1;
	unsigned char	*a2;

	i = 0;
	a1 = (unsigned char *)s1;
	a2 = (unsigned char *)s2;
	while ((a1[i] != '\0' || a2[i] != '\0') && (i < n))
	{
		if (a1[i] != a2[i])
		{
			return (a1[i] - a2[i]);
		}
		i++;
	}
	return (0);
}
