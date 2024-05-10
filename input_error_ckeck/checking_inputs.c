/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:55:46 by ryusupov          #+#    #+#             */
/*   Updated: 2024/05/10 19:13:23 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

static int	dublicate_check(char **str)
{
	int	i;
	int	a;

	i = 1;
	while (str[i])
	{
		a = 1;
		while (str[a])
		{
			if (a != i && ft_strcmp(str[i], str[a]) == 0)
				return (1);
			a++;
		}
		i++;
	}
	return (0);
}

static int	str_is_zero(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i] == '0')
	{
		i++;
	}
	if (str[i] != '\0')
		return (0);
	return (1);
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
	int	zero;

	zero = 0;
	i = 1;
	while (str[i])
	{
		if (!str_is_num(str[i]))
		{
			return (0);
		}
		zero = zero + str_is_zero(str[i]);
		i++;
	}
	if (zero > 1)
		return (0);
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
