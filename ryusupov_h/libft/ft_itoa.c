/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:54:50 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/25 19:28:43 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov.h"

/*
	itoa stands for "integer to ASCII." It's a function that converts an integer
	value to a null-terminated string representation of that integer
*/

static int	num_digits(int n)
{
	int	counter;

	if (n == 0)
		return (1);
	counter = 0;
	while (n != 0)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	long	new_n;
	int		size;
	char	*result;
	int		i;

	new_n = n;
	i = 0;
	if (n < 0)
	{
		i = 1;
		new_n = (long)n * (-1);
	}
	size = num_digits(new_n) + i;
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	result[size] = '\0';
	if (i == 1)
		result[0] = '-';
	while (i != size)
	{
		result[size-- - 1] = (new_n % 10) + '0';
		new_n = new_n / 10;
	}
	return (result);
}
