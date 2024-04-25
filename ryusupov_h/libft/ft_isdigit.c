/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:52:56 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/25 19:28:31 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov.h"

/*	isdigit function tests if the given character is digit or not	*/

int	ft_isdigit(int i)
{
	if (i >= 48 && i <= 57)
	{
		return (i);
	}
	return (0);
}
