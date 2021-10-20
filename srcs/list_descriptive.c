/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_descriptive.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/13 17:42:02 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/20 14:21:20 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

size_t	list_size(t_stack *stack)
{
	size_t	size;
	t_stack	*tmp;

	size = 0;
	if (stack)
	{
		tmp = stack;
		while (tmp)
		{
			size++;
			tmp = tmp->next;
		}
	}
	return (size);
}

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

int	unsorted_size(t_stack *stack)
{
	int		size;
	t_stack	*tmp;

	size = 0;
	if (stack)
	{
		tmp = stack;
		while (tmp && tmp->sorted == 0)
		{
			size++;
			tmp = tmp->next;
		}
	}
	return (size);
}
