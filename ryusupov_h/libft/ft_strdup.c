/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:03:11 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/25 19:30:35 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov.h"

/*
	ft_strdup function is used to duplicate a string. It allocates memory for
	the duplicate string, copies the contents of the original string into the
	newly allocated memory, and returns a pointer to the duplicate string
*/

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = (char *)malloc(ft_strlen(s1) + 1);
	if (!(s2))
	{
		return (NULL);
	}
	ft_memcpy(s2, s1, ft_strlen(s1) + 1);
	return (s2);
	free(s2);
}
