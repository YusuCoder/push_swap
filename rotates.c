/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:35:18 by ryusupov          #+#    #+#             */
/*   Updated: 2024/05/04 15:02:42 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ryusupov_h/ryusupov.h"

/*This function checks if the stack is empty or has only one element
	(in which case,
			no rotation is needed). If the stack has more than one element,
	it rotates the stack by moving the first element to the end.*/

void	rotate_stack(t_ryusupov **r_stack)
{
	t_ryusupov	*temp;
	t_ryusupov	*last_node;

	if (*r_stack == NULL || (*r_stack)->next == NULL)
		return ;
	temp = *r_stack;
	*r_stack = (*r_stack)->next;
	last_node = *r_stack;
	while (last_node->next != NULL)
		last_node = last_node->next;
	temp->next = NULL;
	last_node->next = temp;
}

void	rule_ra_rb(t_ryusupov **r_stack, char rule)
{
	if (rule == 'a' || rule == 'b')
	{
		rotate_stack(r_stack);
		ft_printf("r%c\n", rule);
	}
}

void	rule_rr(t_ryusupov **r_stack_a, t_ryusupov **r_stack_b)
{
	rotate_stack(r_stack_a);
	rotate_stack(r_stack_b);
	ft_printf("rr\n");
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

// 	rotate_stack(&stack);
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
