/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:23:29 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/25 19:31:06 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov.h"

/*
	ft_strmapi applies a transformation function f to each character
	of the input string s1, creating a new string s2 with the transformed
	characters. The transformation function f takes both the index of the
	character and the character itself as arguments. This function is useful
	for applying custom transformations to strings based on their positions.
*/

char	*ft_strmapi(char const *s1, char (*f)(unsigned int, char))
{
	char	*s2;
	size_t	i;

	i = 0;
	s2 = ft_strdup(s1);
	if (!s1 || !f || !s2)
	{
		return (NULL);
	}
	while (s2[i])
	{
		s2[i] = f(i, s2[i]);
		i++;
	}
	return (s2);
}
