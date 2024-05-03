/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:44:33 by ryusupov          #+#    #+#             */
/*   Updated: 2024/05/03 11:46:36 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ryusupov_h/ryusupov.h"

/*Function buttom_stack adds new node to the buttom of the list*/

void	buttom_stack(t_ryusupov **r_stack_a, t_ryusupov *new)
{
	t_ryusupov	*current;

	if (!new)
		exit(EXIT_FAILURE);
	if (!*r_stack_a)
	{
		*r_stack_a = new;
		return ;
	}
	current = *r_stack_a;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new;
}

// int	main(void)
// {
// 	t_ryusupov	*node1;
// 	t_ryusupov	*node2;
// 	t_ryusupov	*node3;
// 	t_ryusupov	*stack;
// 	t_ryusupov	*current;

// 	node1 = (t_ryusupov *)malloc(sizeof(t_ryusupov));
// 	node2 = (t_ryusupov *)malloc(sizeof(t_ryusupov));
// 	node3 = (t_ryusupov *)malloc(sizeof(t_ryusupov));
// 	node1->r_content = 1;
// 	node1->next = NULL;
// 	node2->r_content = 2;
// 	node2->next = NULL;
// 	node3->r_content = 3;
// 	node3->next = NULL;
// 	stack = NULL;
// 	buttom_stack(&stack, node1);
// 	buttom_stack(&stack, node2);
// 	buttom_stack(&stack, node3);
// 	printf("Stack contents:\n");
// 	current = stack;
// 	while (current != NULL)
// 	{
// 		printf("%d\n", current->r_content);
// 		current = current->next;
// 	}
// 	free(node1);
// 	free(node2);
// 	free(node3);
// 	return (0);
// }
