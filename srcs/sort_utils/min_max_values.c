/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   min_max_values.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/20 19:20:36 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/21 15:57:09 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	get_max(t_stack *stack, int chunk)
{
	int		max;
	t_stack	*tmp;

	if (!stack)
		return (0);
	tmp = stack;
	max = stack->pos;
	while (tmp)
	{
		if (tmp->chunk == chunk && max < tmp->pos)
			max = tmp->pos;
		tmp = tmp->next;
	}
	return (max);
}

int	get_min(t_stack *stack, int chunk)
{
	int		min;
	t_stack	*tmp;

	if (!stack)
		return (0);
	tmp = stack;
	min = stack->pos;
	while (tmp)
	{
		if (tmp->chunk == chunk && min > tmp->pos)
			min = tmp->pos;
		tmp = tmp->next;
	}
	return (min);
}
