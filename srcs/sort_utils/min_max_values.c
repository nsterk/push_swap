/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   min_max_value.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/20 19:20:36 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/20 19:21:04 by naomisterk    ########   odam.nl         */
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

int	where_is_min(t_stack *stack)
{
	t_stack	*tmp;
	int		min;
	int		i;

	if (!stack)
		return (-1);
	min = stack->pos;
	i = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->pos < min)
		{
			min = tmp->pos;
			i = tmp->i;
		}
		tmp = tmp->next;
	}
	return (i);
}
