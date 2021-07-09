/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/09 10:42:51 by nsterk        #+#    #+#                 */
/*   Updated: 2021/07/09 10:51:22 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	do_swap(t_stack **stack)
{
	int	temp;

	if (!(*stack) || !(*stack)->next)
		return ;
	temp = (*stack)->num;
	(*stack)->num = (*stack)->next->num;
	(*stack)->next->num = temp;
}

void	do_rotate(t_stack **stack)
{
	if (!stack || *stack == NULL)
		return ;
	push_back(stack, pop_front(stack));
}

void	do_reverse_rotate(t_stack **stack)
{
	if (!stack || *stack == NULL)
		return ;
	push_front(stack, pop_back(stack));
}
