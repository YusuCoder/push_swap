/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_adaptation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:13:28 by ryusupov          #+#    #+#             */
/*   Updated: 2024/05/05 13:34:36 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "./ryusupov_h/ryusupov.h"

// t_list	*convert_to_list(t_ryusupov *r_stack)
// {
// 	t_list	*head;
// 	t_list	*temp;
// 	t_list	*new_node;

// 	head = NULL;
// 	temp = NULL;
// 	while (r_stack != NULL)
// 	{
// 		new_node = (t_list *)malloc(sizeof(t_list));
// 		if (new_node == NULL)
// 			exit(EXIT_FAILURE);
// 		new_node->content = r_stack->r_content;
// 		new_node->next = NULL;
// 		if (head == NULL)
// 		{
// 			head = new_node;
// 		}
// 		else
// 		{
// 			temp->next = new_node;
// 		}
// 		temp = new_node;
// 		r_stack = r_stack->next;
// 	}
// 	return (head);
// }

// int	list_sorted_adapter(t_ryusupov *r_stack)
// {
// 	t_list	*list_a;

// 	list_a = convert_to_list(r_stack);
// 	return (list_sorted(list_a));
// }
