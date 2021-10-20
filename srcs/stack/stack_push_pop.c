/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_push_pop.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/05 11:21:53 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/20 15:20:16 by naomisterk    ########   odam.nl         */
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

t_stack	*pop_back(t_stack **stack)
{
	t_stack	*new_tail;
	t_stack	*old_tail;

	new_tail = *stack;
	old_tail = stack_last(*stack);
	while (new_tail->next->next != NULL)
		new_tail = new_tail->next;
	new_tail->next = NULL;
	return (old_tail);
}

t_stack	*pop_front(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	*stack = (*stack)->next;
	return (temp);
}
