/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:43:39 by ryusupov          #+#    #+#             */
/*   Updated: 2024/05/10 11:14:23 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ryusupov_h/ryusupov.h"

void	free_content(void *node)
{
	t_ryusupov	*temp;

	temp = (t_ryusupov *)node;
	// free(temp->r_content);
	free(temp);
}

static void	*stack_contents(int argc, char **argv)
{
	t_ryusupov	*r_stack_a;
	long int	num;
	int			i;

	r_stack_a = NULL;
	num = 0;
	i = 1;
	while (argc > i)
	{
		num = ft_atoi(argv[i]);
        printf("second test\n");
		if (num > INT_MAX || num < INT_MIN)
		{
			free(r_stack_a);
			exit(EXIT_FAILURE);
		}
		if (i == 1)	
			r_stack_a = stack_new((int)num);
		else
		{
            printf("first tes\n");
			buttom_stack(&r_stack_a, stack_new((int)num));
		}
		i++;
	}
	return (r_stack_a);
}

static void	push_swap(t_ryusupov **r_stack_a, t_ryusupov **r_stack_b,
		int stack_size)
{
	if (stack_size == 2 && !list_sorted(*r_stack_a))
		rule_sa_sb(r_stack_a, 'a');
	else if (stack_size == 3)
		small_sorting(r_stack_a);
	else if (stack_size > 3 && !list_sorted(*r_stack_a))
		huge_sorting(r_stack_a, r_stack_b);
}

// int ft_wordcount(const char *str, char delimiter) {
//     int count = 0;
//     int is_word = 0; // flag to indicate if currently in a word

//     while (*str) {
//         if (*str != delimiter) {
//             // If the current character is not the delimiter
//             // and we are not already in a word, increment the count
//             if (!is_word) {
//                 count++;
//                 is_word = 1; // Set flag to indicate that we are in a word
//             }
//         } else {
//             // If the current character is the delimiter
//             is_word = 0; // Set flag to indicate that we are not in a word
//         }
//         str++; // Move to the next character
//     }

//     return count;
// }

// int main(int argc, char **argv)
// {
//     t_ryusupov *r_stack_a;
//     t_ryusupov *r_stack_b;
//     int r_size;

//     r_stack_a = NULL;
//     r_stack_b = NULL;

//     if (argc < 2 || (argc == 2 && !argv[1][0]))
//     {
//         ft_printf("Nothing to sort!\n");
//         exit(EXIT_SUCCESS);
//     }
//     else if (argc == 2)
//     {
//         // If the argument is provided within double quotes
//      if (argv[1][0] == '"')
// {
//     // Remove the double quotes from the string
//     char *arg_without_quotes = strdup(argv[1] + 1); // Copy the string without the opening quote
//     arg_without_quotes[strlen(arg_without_quotes) - 1] = '\0'; // Remove the closing quote
//     argc = ft_wordcount(arg_without_quotes, ' '); // Recalculate argc
//     argv = ft_split(arg_without_quotes, ' '); // Split the string without quotes
//     free(arg_without_quotes); // Free the allocated memory
// }
//         else
//         {
//             // Otherwise, split the argument normally
//             argv = ft_split(argv[1], ' ');
//             argc = ft_wordcount(argv[1], ' ');
//         }
//     }

//     if (!correct_input(argv))
//     {
//         ft_printf("Error\n");
//         exit(EXIT_FAILURE);
//     }

//     r_stack_b = NULL;
//     r_stack_a = stack_contents(argc, argv);
//     r_size = ft_lstsize(r_stack_a);
//     content_index(r_stack_a, r_size + 1);
//     push_swap(&r_stack_a, &r_stack_b, r_size);
//     ft_lstclear(&r_stack_a, &free_content);
//     ft_lstclear(&r_stack_b, &free_content);
//     return 0;
// }

// int	main(int argc, char **argv)
// {
//     t_ryusupov  *r_stack_a;
//     t_ryusupov  *r_stack_b;
//     int         r_size;
//     int         new_argc = argc;
//     char        **new_argv = argv;

//     r_stack_a = NULL;
//     r_stack_b = NULL;
//     if (argc < 2 || (argc == 2 && !argv[1][0]))
//     {
//         ft_printf("Nothing to sort!\n");
//         exit(EXIT_SUCCESS);
//     }
//     else if (argc == 2)
//     {   
//         printf("Before split: %s\n", argv[1]);

//         new_argv = ft_split(argv[1], &new_argc);

//         // Print the value of argv[1] after split
//         printf("After split: %s\n", new_argv[0]); // Just for testing, you can iterate over new_argv if necessary
//     }
//     if (!correct_input(new_argv))
//     {
//         ft_printf("Error\n");
//         exit(EXIT_FAILURE);
//     }
//     r_stack_b = NULL;
//     r_stack_a = stack_contents(new_argc, new_argv);
//     r_size = ft_lstsize(r_stack_a);
//     content_index(r_stack_a, r_size + 1);
//     push_swap(&r_stack_a, &r_stack_b, r_size);
//     ft_lstclear(&r_stack_a, &free_content);
//     ft_lstclear(&r_stack_b, &free_content);

//     // Free memory allocated by ft_split
//     if (argc == 2) {
//         for (int i = 0; i < new_argc; i++) {
//             free(new_argv[i]);
//         }
//         free(new_argv);
//     }

//     return (0);
// }

int	main(int argc, char **argv)
{
	t_ryusupov	*r_stack_a;
	t_ryusupov	*r_stack_b;
    int         new_argc = argc;
    char        **new_argv = argv;
	int			r_size;

	r_stack_a = NULL;
	r_stack_b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
	{
		ft_printf("Nothing to sort!\n");
		exit(EXIT_SUCCESS);
	}
	else if (argc == 2)
{        printf("Before split: %s\n", argv[1]);

        new_argv = new_split(argv[1], &new_argc);

        // Print the value of argv[1] after split
        printf("After split: %s\n", argv[1]);}
	if (!correct_input(new_argv))
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	r_stack_b = NULL;
	r_stack_a = stack_contents(new_argc, new_argv);
	r_size = ft_lstsize(r_stack_a);
	content_index(r_stack_a, r_size + 1);
	push_swap(&r_stack_a, &r_stack_b, r_size);
	ft_lstclear(&r_stack_a, &free_content);
	ft_lstclear(&r_stack_b, &free_content);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	t_ryusupov	*r_stack_a;
// 	t_ryusupov	*r_stack_b;
// 	int			r_size;

// 	r_stack_a = NULL;
// 	r_stack_b = NULL;
// 	if (argc < 2 || (argc == 2 && !argv[1][0]))
// 	{
// 		ft_printf("Nothing to sort!\n");
// 		exit(EXIT_SUCCESS);
// 	}
// 	else if (argc == 2)
// 		argv = ft_split(argv[1], ' ');
// 	if (!correct_input(argv))
// 	{
// 		ft_printf("Error\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	r_stack_b = NULL;
// 	r_stack_a = stack_contents(argc, argv);
// 	r_size = ft_lstsize(r_stack_a);
// 	content_index(r_stack_a, r_size + 1);
// 	push_swap(&r_stack_a, &r_stack_b, r_size);
// 	ft_lstclear(&r_stack_a, &free_content);
// 	ft_lstclear(&r_stack_b, &free_content);
// 	return (0);
// }
