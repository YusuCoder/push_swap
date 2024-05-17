/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:03:17 by ryusupov          #+#    #+#             */
/*   Updated: 2024/05/17 21:10:52 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

void	free_content(void *node)
{
	t_ryusupov	*temp;

	temp = (t_ryusupov *)node;
	free(temp);
}

void free_array(char **array)
{
    size_t i = 0;
    if (!array)
        return;
    while (array[i] != NULL)
    {
        free(array[i]);
        i++;
    }
    free(array);
}
int ft_lstsize_new(t_ryusupov *lst)
{
    int i;
    t_ryusupov *temp;

    i = 0;
    temp = lst;
    while (temp)
    {
        temp = temp->next;
        i++;
    }
    return (i);
}
// size_t	count_words(char **words)
// {
// 	size_t	count;

// 	count = 0;
// 	while (*words)
// 	{
// 		if (**words)
// 			count++;
// 		words++;
// 	}
// 	return (count);
// }

size_t count_words(char **words)
{
    size_t count = 1;
    while (words[count])
        count++;
    return count;
}

void	print_error_and_exit(const char *message, int exit_code)
{
	ft_printf("%s\n", message);
	exit(exit_code);
}
