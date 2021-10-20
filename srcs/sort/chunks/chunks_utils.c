/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   chunk_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/20 15:32:01 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/20 15:33:21 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	assign_chunks(t_stacks *stacks, int amount)
{
	t_stack	*tmp;
	int		pivot;

	if (!stacks || !(stacks->a))
		return ;
	tmp = stacks->a;
	stacks->per_chunk = (int)stacks->size / amount;
	pivot = stacks->per_chunk;
	while (amount)
	{
		stacks->chunks++;
		while (tmp)
		{
			if ((amount == 1 && tmp->chunk == -1) || \
				(tmp->chunk == -1 && tmp->pos <= pivot))
				tmp->chunk = stacks->chunks;
			tmp = tmp->next;
		}
		tmp = stacks->a;
		pivot += (stacks->per_chunk + 1);
		amount--;
	}	
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

int	chunk_left(t_stack *stack, int chunk)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->chunk == chunk)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
