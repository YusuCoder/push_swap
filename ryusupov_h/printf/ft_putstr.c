/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:19:17 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/26 14:03:38 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov.h"

int	ft_putstr(char *c)
{
	int	len;

	if (!c)
		c = "(null)";
	len = (int)write(1, c, ft_strlen(c));
	if (len < 0)
		return (-1);
	else
		return (len);
}
