/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:51:35 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/25 19:32:42 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov.h"

int	ft_decimal(size_t i, int res)
{
	int	recursive_result;

	if (i > 9)
	{
		recursive_result = ft_decimal(i / 10, res);
		if (recursive_result == -1)
			return (-1);
		res = recursive_result;
	}
	if (ft_putchar(i % 10 + '0') == -1)
		return (-1);
	res++;
	return (res);
}
