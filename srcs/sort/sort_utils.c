/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 20:21:01 by nsterk        #+#    #+#                 */
/*   Updated: 2021/10/15 19:37:23 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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

int		how_many_chunks(size_t size)
{
	if (size < 50)
		return (3);
	if (size < 150)
		return (5);
	return (7);
}

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
