/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 20:21:01 by nsterk        #+#    #+#                 */
/*   Updated: 2021/10/06 21:24:03 by nsterk        ########   odam.nl         */
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
	return ((max - min) / 2);
}

void	set_as_sorted(t_stack *stack, int len)
{
	if (len == 2)
	{
		stack->next->sorted = 1;
		stack->next->chunk = -1;
	}
	if (len == 2 || len == 1)
	{
		stack->sorted = 1;
		stack->chunk = -1;
	}
}

int	find_closest(t_stack *a, int mid, int len)
{
	int	index1;
	int	index2;
	int	steps_from_tail;

	index1 = closest_from_head(a, mid);
	index2 = closest_from_tail(a, mid);
	if (index1 == -1 || index2 == -1)
		return (-1);
	steps_from_tail = len - index2;
	if (index1 <= steps_from_tail)
		return (index1);
	return (index2);
}

int	closest_from_head(t_stack *a, int mid)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->pos <= mid)
			return (tmp->i);
		tmp = tmp->next;
	}
	return (-1);
}

int	closest_from_tail(t_stack *a, int mid)
{
	t_stack	*tmp;
	int		node;

	if (!a)
		return (-1);
	tmp = a;
	node = (int)list_size(a);
	while (node >= 0)
	{
		tmp = get_node(&a, node);
		if (tmp->pos <= mid)
			return (tmp->i);
		node--;
	}
	return (-1);
}
