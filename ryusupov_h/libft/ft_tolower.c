/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:20:58 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/25 19:31:55 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov.h"

int	ft_tolower(int i)
{
	if ((i >= 65) && (i <= 90))
	{
		return (i + 32);
	}
	return (i);
}
