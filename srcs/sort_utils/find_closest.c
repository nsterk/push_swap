/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_closest.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/15 16:35:57 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/21 15:07:02 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	closest_from_head(t_stack *stack, int mid)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->pos > mid)
			return (tmp->i);
		tmp = tmp->next;
	}
	return (-1);
}

static int	closest_from_tail(t_stack *stack, int mid, int len)
{
	t_stack	*tmp;

	if (!stack)
		return (-1);
	tmp = stack;
	while (len >= 0)
	{
		tmp = get_node(&stack, len);
		if (tmp->pos > mid)
			return (tmp->i);
		len--;
	}
	return (-1);
}

int	find_closest(t_stack *a, int mid, int len)
{
	int	index1;
	int	index2;
	int	steps_from_tail;

	index1 = closest_from_head(a, mid);
	index2 = closest_from_tail(a, mid, len - 1);
	if (index1 == -1 || index2 == -1)
		return (-1);
	steps_from_tail = len - index2;
	if (index1 <= steps_from_tail)
		return (index1);
	return (index2);
}
