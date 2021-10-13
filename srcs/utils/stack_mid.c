/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_mid.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 18:24:07 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/08 18:35:15 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	get_mid(t_stack *stack)
{
	int		min;
	int		max;

	if (!stack)
		return (0);
	min = get_min(stack);
	max = get_max(stack);
	return ((max + min) / 2);
}

int	under_mid_left(t_stack *stack, int mid)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp && tmp->chunk == stack->chunk)
	{
		if (tmp->pos < mid)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	over_mid_left(t_stack *stack, int mid)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp && tmp->chunk == stack->chunk)
	{
		if (tmp->pos > mid)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
