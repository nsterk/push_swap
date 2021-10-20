/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   chunks_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/20 15:32:01 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/20 20:18:28 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	chunk_size(t_stack *stack, int chunk)
{
	int		size;
	t_stack	*tmp;

	size = 0;
	if (stack)
	{
		tmp = stack;
		while (tmp && tmp->chunk == stack->chunk)
		{
			if (tmp->chunk == chunk)
				size++;
			tmp = tmp->next;
		}
	}
	return (size);
}

