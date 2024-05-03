/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:01:11 by ryusupov          #+#    #+#             */
/*   Updated: 2024/05/03 18:38:23 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ryusupov_h/ryusupov.h"

/*The function swap_list swaps the content of current node with next node*/
/*The function rule_sa_sb is checks if the rule is sa(swap a) or sb(swap b) and makes swap
	between nodes*/
/*the rule_ss is (swap b and swap a at the same time)*/

void	swap_list(t_ryusupov *r_stack)
{
	int	temp;

	if (r_stack == NULL || r_stack->next == NULL)
	{
		ft_printf("Error!\n");
		return ;
	}
	temp = r_stack->r_content;
	r_stack->r_content = r_stack->next->r_content;
	r_stack->next->r_content = temp;
	temp = r_stack->i;
	r_stack->i = r_stack->next->i;
	r_stack->next->i = temp;
}

void	rule_sa_sb(t_ryusupov **r_stack, char rule)
{
	if (rule == 'a' || rule == 'b')
	{
		swap_list(*r_stack);
		printf("s%c\n", rule);
	}
}

void	rule_ss(t_ryusupov **r_stack, t_ryusupov **r_stack_b)
{
	swap_list(*r_stack);
	swap_list(*r_stack_b);
	printf("ss\n");
}

// int	main(void)
// {
// 	t_ryusupov	*stack_a;
// 	t_ryusupov	*stack_b;

// 	stack_a = malloc(sizeof(t_ryusupov));
// 	stack_a->r_content = 10;

// 	stack_a->next = malloc(sizeof(t_ryusupov));
// 	stack_a->next->r_content = 20;

// 	stack_a->next->next = NULL;
// 	stack_b = malloc(sizeof(t_ryusupov));
// 	stack_b->r_content = 30;

// 	stack_b->next = malloc(sizeof(t_ryusupov));
// 	stack_b->next->r_content = 40;
// 	stack_b->next->next = NULL;

// 	rule_ss(&stack_a, &stack_b);
// 	rule_sa_sb(&stack_a, 'a');
// 	rule_sa_sb(&stack_b, 'b');

// 	ft_printf("ss: %d and %d\n", stack_a->r_content, stack_b->r_content);
// 	ft_printf("sa: %d\n", stack_a->r_content);
// 	ft_printf("sb: %d\n", stack_b->r_content);
// 	// ft_printf("ss: %d -> %d\n", stack_a->r_content,
// 	// 		stack_a->next->r_content);
// 	// ft_printf("sa: %d -> %d\n", stack_a->r_content,
// 	// 		stack_a->next->r_content);
// 	// ft_printf("sb: %d -> %d\n", stack_b->r_content,
// 	// 		stack_b->next->r_content);
// 	free(stack_a->next);
// 	free(stack_a);
// 	free(stack_b->next);
// 	free(stack_b);
// 	return (0);
// }
