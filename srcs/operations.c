/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/30 17:09:21 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/07/01 17:40:05 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	swap(t_stack **stack)
{
	int	temp;

	if (!(*stack) || !(*stack)->next)
		return (0);
	temp = (*stack)->num;
	(*stack)->num = (*stack)->next->num;
	(*stack)->next->num = temp;
	return (1);
}

t_stack	**push(t_stack **from, t_stack **to)
{
	t_stack	**temp;

	*temp = (*from)->next;
	stack_add_front(to, stack_new((*from)->num));
	free(from);
	return (temp);
}
