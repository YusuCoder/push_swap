/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:25:53 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/26 13:46:21 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov.h"

int	ft_print_adress(long *p)
{
	size_t	i;
	int		a;
	int		ishex_result;

	i = (size_t)p;
	if (ft_putstr("0x") == -1)
		return (-1);
	a = 2;
	ishex_result = ft_ishex(i, 0, 0);
	if (ishex_result == -1)
		return (-1);
	a += ishex_result;
	return (a);
}

int	main(void)
{
	long	value;
	int		result;

	value = 12345;
	result = ft_print_adress(&value);
	if (result == -1)
	{
		printf("Error printing address.\n");
	}
	else
	{
		printf("Printed %d characters.\n", result);
	}
	return (0);
}
