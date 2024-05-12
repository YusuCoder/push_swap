/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:03:17 by ryusupov          #+#    #+#             */
/*   Updated: 2024/05/12 14:48:52 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

void	free_content(void *node)
{
	t_ryusupov	*temp;

	temp = (t_ryusupov *)node;
	free(temp);
}

size_t	count_words(char **words)
{
	size_t	count;

	count = 0;
	while (*words)
	{
		if (**words)
			count++;
		words++;
	}
	return (count);
}

void	print_error_and_exit(const char *message, int exit_code)
{
	ft_printf("%s\n", message);
	exit(exit_code);
}
