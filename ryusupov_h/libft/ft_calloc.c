/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:16:37 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/25 19:27:48 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov.h"

/*
		Calloc is used for dynamic memory allocation.
		Calloc allocates blocks of memory and sets it to zero type.
		Allocating Memory for Multiple Elements: calloc is specifically used
		when you want to allocate memory for multiple elements of a certain type.
		For example, you might want to create an array of integers, but you don't
		know how many integers you'll need until runtime.
		Calloc has two arguments one is for number of elements you want to
		allocate for and the second one is for the size of each element in bytes.
*/

void	*ft_calloc(size_t count, size_t size)
{
	size_t	all_size;
	void	*dest;

	all_size = count * size;
	dest = malloc(all_size);
	if (dest == 0)
	{
		return (NULL);
	}
	ft_memset(dest, 0, all_size);
	return (dest);
}
