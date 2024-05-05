/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:18:07 by ryusupov          #+#    #+#             */
/*   Updated: 2024/05/05 13:37:35 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ryusupov_h/ryusupov.h"

int	max_index(t_ryusupov *r_stack)
{
	int	i;

	i = r_stack->i;
	while (r_stack)
	{
		if (r_stack->i > i)
			i = r_stack->i;
		r_stack = r_stack->next;
	}
	return (i);
}

void	small_sorting(t_ryusupov **r_stack)
{
	int	max;

	if (list_sorted(*r_stack))
		return ;
	max = max_index(*r_stack);
	if ((*r_stack)->i == max)
		rule_ra_rb(r_stack, 'a');
	else if ((*r_stack)->next->i == max)
		rule_rra_rrb(r_stack, 'a');
	if ((*r_stack)->i > (*r_stack)->next->i)
		rule_sa_sb(r_stack, 'a');
}

// t_ryusupov *createNode(int data) {
//     t_ryusupov *newNode = (t_ryusupov *)malloc(sizeof(t_ryusupov));
//     newNode->i = data;
//     newNode->next = NULL;
//     return newNode;
// }

// void push(t_ryusupov **r_stack, int data) {
//     t_ryusupov *newNode = createNode(data);
//     newNode->next = *r_stack;
//     *r_stack = newNode;
// }

// void freeList(t_ryusupov *r_stack) {
//     t_ryusupov *temp;
//     while (r_stack != NULL) {
//         temp = r_stack;
//         r_stack = r_stack->next;
//         free(temp);
//     }
// }

// int main() {
//     t_ryusupov *r_stack = NULL;

//     push(&r_stack, 5);
//     push(&r_stack, 2);
//     push(&r_stack, 7);
//     push(&r_stack, 1);
//     push(&r_stack, 9);

//     ft_printf("Original Stack:\n");
//     t_ryusupov *temp = r_stack;
//     while (temp != NULL) {
//         ft_printf("%d ", temp->i);
//         temp = temp->next;
//     }
//     ft_printf("\n");

//     small_sorting(&r_stack);

//     ft_printf("Sorted Stack:\n");
//     temp = r_stack;
//     while (temp != NULL) {
//         ft_printf("%d ", temp->i);
//         temp = temp->next;
//     }
//     ft_printf("\n");

//     freeList(r_stack);

//     return 0;
// }
