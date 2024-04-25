/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:51:07 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/25 19:31:22 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov.h"

/*
	ft_strnstr searches for the first occurrence of the substring needle within
	the string hydr, limited to a maximum of n characters. It returns a pointer
	to the start of the matched substring within hydr, or NULL if the substring
	is not found.
*/

char	*ft_strnstr(const char *hydr, const char *needle, size_t n)
{
	size_t	strle;
	size_t	i;
	size_t	a;

	i = 0;
	strle = ft_strlen(needle);
	if (hydr == needle || strle == 0)
		return ((char *)hydr);
	while (hydr[i] != '\0' && i < n)
	{
		a = 0;
		while (hydr[i + a] != '\0' && needle[a] != '\0'
			&& (i + a) < n && hydr[i + a] == needle[a])
		{
			a++;
			if (a == strle)
				return ((char *)(hydr + i));
		}
		i++;
	}
	return (0);
}
