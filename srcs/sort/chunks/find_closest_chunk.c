/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_closest_chunk.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/15 19:16:08 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/20 14:19:45 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	closest_chunk_from_head(t_stack *stack, int chunk)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->chunk == chunk)
			return (tmp->i);
		tmp = tmp->next;
	}
	return (-1);
}

static int	closest_chunk_from_tail(t_stack *stack, int chunk, int len)
{
	t_stack	*tmp;

	if (!stack)
		return (-1);
	tmp = stack;
	while (len >= 0)
	{
		tmp = get_node(&stack, len);
		if (tmp->chunk == chunk)
			return (tmp->i);
		len--;
	}
	return (-1);
}

int	find_closest_chunk(t_stack *stack, int chunk, int len)
{
	int	index1;
	int	index2;
	int	steps_from_tail;

	index1 = closest_chunk_from_head(stack, chunk);
	index2 = closest_chunk_from_tail(stack, chunk, len - 1);
	if (index1 == -1 || index2 == -1)
		return (-1);
	steps_from_tail = len - index2;
	if (index1 <= steps_from_tail)
		return (index1);
	return (index2);
}
