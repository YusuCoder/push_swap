/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:44:33 by ryusupov          #+#    #+#             */
/*   Updated: 2024/05/09 16:56:24 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ryusupov_h/ryusupov.h"

/*Function buttom_stack adds new node to the buttom of the list*/

/*Function stack_new creates a stack elements with the provided value,
// 	and returns the newly created stack element*/
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

t_ryusupov	*stack_new(int str)
{
	t_ryusupov	*new;

	new = malloc(sizeof(t_ryusupov));
	if (!new)
		return (NULL);
	new->r_content = str;
	new->i = 0;
	new->r_pos = -1;
	new->r_target_pos = -1;
	new->r_cost_a = -1;
	new->r_cost_b = -1;
	new->next = NULL;
	return (new);
}

// // int main() {
// // 	int str = 10;
// // 	t_ryusupov *new_node = stack_new(str);
// // 	if (!new_node) {
// // 		printf("Error: Memory allocation failed!\n");
// // 		return (1);
// // 	}
// // 	printf("New Node Values:\n");
// // 	printf("r_content: %d\n", new_node->r_content);
// // 	printf("i: %d\n", new_node->i);
// // 	printf("r_pos: %d\n", new_node->r_pos);
// // 	printf("r_target_pos: %d\n", new_node->r_target_pos);
// // 	printf("r_cost_a: %d\n", new_node->r_cost_a);
// // 	printf("next: %p\n", (void *)new_node->next);
// // 	free(new_node);
// // 	return (0);
// // }

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
