/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:37:19 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/26 14:06:18 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov.h"

size_t	ft_strlen(const char *s)
{
	int	i;
	int	counter;

	if (!s)
	{
		return (0);
	}
	i = 0;
	counter = 0;
	while (s[i])
	{
		i++;
		counter++;
	}
	return (counter);
}

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }
