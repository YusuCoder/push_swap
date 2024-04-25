/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:37:35 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/25 19:30:20 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (ptr == NULL)
	{
		return (malloc(size));
	}
	if (!size)
	{
		return (ptr);
	}
	new_ptr = malloc(size);
	ft_memcpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}


// int main()
// {
//     int *ptr;
//     ptr = NULL;

//     ptr = realloc(ptr, 20);
//     if(ptr != NULL)
//            printf("Memory allocated successfully for original realloc\n");
// 	ptr = ft_realloc(ptr, 20);
// 	if(ptr != NULL)
//            printf("Memory allocated successfully for ft_realloc\n");

//     return 0;
// }
