/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_pop.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/05 11:21:53 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/07/06 14:08:42 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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
