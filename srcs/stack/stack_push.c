/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_push.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/02 17:40:26 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/07 17:26:04 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push_back(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (!stack || !new)
		return ;
	temp = NULL;
	new->next = NULL;
	if (*stack == NULL)
		*stack = new;
	else
		temp = stack_last(*stack);
	temp->next = new;
}

void	push_front(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;
	new->next = *stack;
	*stack = new;
}
