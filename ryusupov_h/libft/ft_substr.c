/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:25:11 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/25 19:31:51 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov.h"

/*
	ft_substr extracts a substring from the original string s1,
	starting from the specified index start and of the specified length len,
	and returns a newly allocated string containing the extracted substring.
*/

char	*ft_substr(char const *s1, unsigned int start, size_t len)
{
	size_t	s1_len;
	char	*s2;
	size_t	i;

	if (!s1)
		return (NULL);
	s1_len = ft_strlen(s1);
	if (start >= s1_len)
		return (ft_strdup(""));
	if (len > s1_len - start)
		len = s1_len - start;
	s2 = (char *)malloc((len + 1) * sizeof(char));
	if (!s2)
	{
		free(s2);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		s2[i] = s1[start + i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
