/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:03:17 by ryusupov          #+#    #+#             */
/*   Updated: 2024/05/20 14:55:16 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

void	free_content(void *node)
{
	t_ryusupov	*temp;

	temp = (t_ryusupov *)node;
	free(temp);
}

char *normalize_number(const char *str)
{
    while (*str == '0' && *(str + 1) != '\0')
        str++;
    return ft_strdup(str);
}

size_t	count_words(char **words)
{
	size_t	count;

	count = 1;
	while (words[count])
		count++;
	return (count);
}

void	print_error_and_exit(const char *message, int exit_code)
{
	ft_printf("%s\n", message);
	exit(exit_code);
}
