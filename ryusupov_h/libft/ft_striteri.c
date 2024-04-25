/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:46:23 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/25 19:30:40 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov.h"

/*
	ft_striteri iterates over each character in the string s1,
	applying the function f to each character along with its index.
	After processing all characters, it adds a null terminator to the end
	of the string.
*/

void	ft_striteri(char *s1, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	if (!s1 || !f)
	{
		return ;
	}
	while (s1[i])
	{
		f(i, s1 + i);
		i++;
	}
	s1[i] = '\0';
}
