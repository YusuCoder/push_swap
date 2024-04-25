/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:07:34 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/25 19:31:47 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov.h"

/*
	ft_strtrim trims leading and trailing characters from the string s1 that
	match any characters in the set set and returns a newly allocated string
	containing the trimmed content. It ensures that the returned string is
	properly null-terminated.

	here in the code i'm trimming the given string using two while loops
	1-i'm strting triiming from the beginning of the loop untill it finds
	matching character.
	2-loop will starting iterating from the endi untill it finds the matchng
	character.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	end;
	char	*trimm_str;

	i = 0;
	end = ft_strlen(s1);
	if (!s1 || !set)
	{
		return (NULL);
	}
	while (s1[i] && ft_strchr(set, s1[i]))
	{
		i++;
	}
	while (end > i && ft_strchr(set, s1[end - 1]))
	{
		end--;
	}
	trimm_str = (char *)malloc(end - i + 1);
	if (!trimm_str)
		return (NULL);
	ft_strlcpy(trimm_str, s1 + i, end - i + 1);
	return (trimm_str);
}
