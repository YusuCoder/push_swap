/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:03:31 by ryusupov          #+#    #+#             */
/*   Updated: 2024/05/11 20:00:04 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

t_ryusupov	*get_stack_b_last_and_last(t_ryusupov *r_stack,
										t_ryusupov **last_node)
{
	t_ryusupov	*before_last;

	before_last = NULL;
	*last_node = NULL;
	while (r_stack && r_stack->next != NULL)
	{
		before_last = r_stack;
		r_stack = r_stack->next;
	}
	*last_node = r_stack;
	return (before_last);
}

void	reverse_rotate(t_ryusupov **r_stack)
{
	t_ryusupov	*temp;
	t_ryusupov	*before_last;
	t_ryusupov	*last_node;

	before_last = get_stack_b_last_and_last(*r_stack, &last_node);
	temp = *r_stack;
	*r_stack = last_node;
	(*r_stack)->next = temp;
	before_last->next = NULL;
}

void	rule_rra(t_ryusupov **r_stack)
{
	reverse_rotate(r_stack);
	ft_printf("rra\n");
}

void	rule_rrb(t_ryusupov **r_stack)
{
	reverse_rotate(r_stack);
	ft_printf("rrb\n");
}

void	rule_rrr(t_ryusupov **r_stack_a, t_ryusupov **r_stack_b)
{
	reverse_rotate(r_stack_a);
	reverse_rotate(r_stack_b);
	ft_printf("rrr\n");
}
// void	print_stack(t_ryusupov *stack)
// {
// 	while (stack != NULL)
// 	{
// 		ft_printf("%d ", stack->r_content);
// 		stack = stack->next;
// 	}
// 	ft_printf("\n");
// }

// int	main(void)
// {
// 	t_ryusupov	*stack;
// 	t_ryusupov	*temp;

// 	// Create a sample stack
// 	stack = malloc(sizeof(t_ryusupov));
// 	stack->r_content = 1;
// 	stack->next = malloc(sizeof(t_ryusupov));
// 	stack->next->r_content = 2;
// 	stack->next->next = malloc(sizeof(t_ryusupov));
// 	stack->next->next->r_content = 3;
// 	stack->next->next->next = NULL;
// 	ft_printf("Current stack: ");
// 	print_stack(stack);
// 	reverse_rotate(&stack);
// 	ft_printf("After rotation: ");
// 	print_stack(stack);
// 	// Free memory
// 	while (stack != NULL)
// 	{
// 		temp = stack;
// 		stack = stack->next;
// 		free(temp);
// 	}
// 	return (0);
// }
