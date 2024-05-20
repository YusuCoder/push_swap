/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:55:46 by ryusupov          #+#    #+#             */
/*   Updated: 2024/05/20 15:11:51 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

int	check_against_normalized(char *normalized_i, char **str, int i)
{
	char	*normalized_a;
	int		a;

	a = 1;
	while (str[a])
	{
		if (a != i)
		{
			normalized_a = normalize_number(str[a]);
			if (!normalized_a)
			{
				return (-1);
			}
			if (ft_strcmp(normalized_i, normalized_a) == 0)
			{
				free(normalized_a);
				return (1);
			}
			free(normalized_a);
		}
		a++;
	}
	return (0);
}

static int	dublicate_check(char **str)
{
	char	*normalized_i;
	int		i;
	int		result;

	i = 1;
	while (str[i])
	{
		normalized_i = normalize_number(str[i]);
		if (!normalized_i)
			return (-1);
		result = check_against_normalized(normalized_i, str, i);
		free(normalized_i);
		if (result != 0)
			return (result);
		i++;
	}
	return (0);
}

static int	str_is_num(const char *str)
{
	int	i;
	int	has_digits;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0' && ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	has_digits = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		has_digits = 1;
		i++;
	}
	return (has_digits);
}

int	correct_input(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (!str_is_num(str[i]))
		{
			return (0);
		}
		i++;
	}
	if (dublicate_check(str))
	{
		return (0);
	}
	return (1);
}

// int	main(void)
// {
// 	char *inputs[] = {"", "123", "456", "789", NULL};

// 	if (correct_input(inputs))
// 	{
// 		printf("Input is correct!\n");
// 	}
// 	else
// 	{
// 		printf("Input is incorrect!\n");
// 	}
// 	return (0);
// }
