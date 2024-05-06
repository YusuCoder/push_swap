/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:57:50 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/30 19:24:51 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ryusupov_h/ryusupov.h"

void	content_index(t_ryusupov *r_stack_a, int size)
{
	t_ryusupov	*max;
	t_ryusupov	*a;
	int			i;

	max = NULL;
	a = r_stack_a;
	i = INT_MIN;
	if (a == NULL || size < 1)
		exit(EXIT_FAILURE);
	while (--size > 0 && a != NULL)
	{
		while (a != NULL)
		{
			if (a->r_content > i && a->i == 0)
			{
				i = a->r_content;
				max = a;
			}
			a = a->next;
		}
		if (max != NULL)
			max->i = size;
		i = INT_MIN;
		a = r_stack_a;
	}
}
// int	main(void)
// {
// 	t_ryusupov	*node1;
// 	t_ryusupov	*node2;
// 	t_ryusupov	*node3;
// 	t_ryusupov	*node4;
// 	t_ryusupov	*node5;
// 	t_ryusupov	*node6;
// 	t_ryusupov	*current;

// 	node1 = malloc(sizeof(t_ryusupov));
// 	node2 = malloc(sizeof(t_ryusupov));
// 	node3 = malloc(sizeof(t_ryusupov));
// 	node4 = malloc(sizeof(t_ryusupov));
// 	node5 = malloc(sizeof(t_ryusupov));
// 	node6 = malloc(sizeof(t_ryusupov));
// 	node1->r_content = -2147483648;
// 	node1->i = 0;
// 	node1->next = node2;
// 	node2->r_content = 3;
// 	node2->i = 0;
// 	node2->next = node3;
// 	node3->r_content = 4;
// 	node3->i = 0;
// 	node3->next = node4;
// 	node4->r_content = 5;
// 	node4->i = 0;
// 	node4->next = node5;
// 	node5->r_content = 2147483647;
// 	node5->i = 0;
// 	node5->next = node6;
// 	node6->r_content = 1;
// 	node6->i = 0;
// 	node6->next = NULL;
// 	content_index(node1, 6);
// 	current = node1;
// 	while (current != NULL)
// 	{
// 		ft_printf("%d[%d], ", current->r_content, current->i);
// 		current = current->next;
// 	}
// 	free(node1);
// 	free(node2);
// 	free(node3);
// 	free(node4);
// 	free(node5);
// 	free(node6);
// 	return (0);
// }
