/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:12:38 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/25 19:30:24 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov.h"

/*
	ft_split function splits a string into words based on a delimiter character
	and returns an array of strings representing those words. It handles memory
	allocation and freeing appropriately to ensure no memory leaks occur.
*/

static int	colculated_words(const char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static void	free_array(char **array, size_t i)
{
	if (!array)
		return ;
	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static char	**extracting(const char *s1, char **result, char c, size_t words)
{
	size_t	i;
	size_t	a;
	size_t	counter;

	i = 0;
	a = 0;
	while (i < words)
	{
		counter = 0;
		while (s1[a] && s1[a] == c)
			a++;
		while (s1[a] && s1[a] != c && ++counter)
			a++;
		result[i] = ft_substr(s1, a - counter, counter);
		if (!result[i])
		{
			free_array(result, i);
			return (NULL);
		}
		i++;
	}
	return (result);
}

char	**ft_split(char const *s1, char c)
{
	char	**result;
	size_t	words;

	if (!s1)
	{
		return (NULL);
	}
	words = colculated_words(s1, c);
	result = (char **)ft_calloc((sizeof(char *)), words + 1);
	if (!result)
	{
		return (NULL);
	}
	return (extracting(s1, result, c, words));
}
