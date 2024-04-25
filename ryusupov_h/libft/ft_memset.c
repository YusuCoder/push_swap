/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:45:19 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/25 19:29:55 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov.h"

/*		The memset function used to fill a block of memory byte by byte.
		function is particularly useful for initializing
	 	memory buffers, setting specific memory regions to a known value,
	 	or preparing memory areas before they are used for other operations.

NOTE! : This function, this implementation does not optimize the operation for
		large memory blocks, and it's a straightforward byte-by-byte assignment.

		Here in exmple i'm setting variable a to each block of memory byte by byte.
*/

void	*ft_memset(void *p, int i, size_t len)
{
	size_t	a;

	a = 0;
	while (a < len)
	{
		((unsigned char *)p)[a] = i;
		a++;
	}
	return (p);
}
