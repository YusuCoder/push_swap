/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:29:28 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/25 19:30:28 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov.h"

/*earches for the first occurrence of the character*/

char	*ft_strchr(const char *p, int i)
{
	unsigned char	c;

	c = i;
	while (*p != '\0' && c != *p)
	{
		p++;
	}
	if (c == *p)
	{
		return ((char *)p);
	}
	return (0);
}
