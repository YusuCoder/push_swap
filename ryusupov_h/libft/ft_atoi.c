/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 21:59:34 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/25 19:27:25 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov.h"

/*
	atoi() function converts the initial portion of the string pointed to
     by str to int representation.
*/

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	counter;

	i = 0;
	sign = 1;
	counter = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	while (*str == 43 || *str == 45)
	{
		if (*str == 45)
			sign *= -1;
		counter++;
		if (counter > 1)
			return (0);
		str++;
	}
	while (ft_isdigit(*str))
	{
		i *= 10;
		i += *str - 48;
		str++;
	}
	return (i * sign);
}
