/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 09:24:51 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/25 19:30:46 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov.h"

/*
	ft_strjoin concatenates two strings s1 and s2 into a new string s3 and returns
	a pointer to it. It allocates memory dynamically for the concatenated string
	and ensures proper null termination.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		a;

	i = 0;
	a = 0;
	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[a] != '\0')
	{
		s3[i + a] = s2[a];
		a++;
	}
	s3[i + a] = '\0';
	return (s3);
}
