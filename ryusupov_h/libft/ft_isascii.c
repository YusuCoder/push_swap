/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:34:20 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/25 19:28:24 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov.h"

/*	ISASCII function tests for an ASCII character*/

int	ft_isascii(int i)
{
	if (i == 0)
		return (1);
	if (i > 0 && i <= 127)
	{
		return (i);
	}
	return (0);
}
