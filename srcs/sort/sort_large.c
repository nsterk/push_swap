/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_large.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/14 17:40:48 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/20 13:44:23 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <math.h>

void	sort_large(t_stacks *stacks)
{
	int	chunk;

	stacks->chunks = log2(stacks->size);
	stacks->unsorted = (int)stacks->size;
	assign_chunks(stacks, stacks->chunks);
	chunk = 0;
	while (stacks->a)
	{
		initial_chunk_to_b(stacks, chunk);
		chunk++;
	}
	while (stacks->b)
	{
		push_b_to_a(stacks);
		push_a_to_b(stacks);
	}
	return ;
}

void	push_a_to_b(t_stacks *stacks)
{
	while (stacks->unsorted > 2)
	{
		chunk_to_b(stacks);
		stacks->unsorted = unsorted_size(stacks->a);
	}
	if (stacks->unsorted == 2)
	{
		if (stacks->a->pos > stacks->a->next->pos)
			swap(stacks->a, "sa", &stacks->ops);
	}
	set_as_sorted(stacks->a, stacks->unsorted);
	stacks->unsorted = 0;
}

void	push_b_to_a(t_stacks *stacks)
{
	int	chunk_len;

	chunk_len = chunk_size(stacks->b, stacks->b->chunk);
	if (chunk_len > 2)
	{
		index_stack(stacks->b);
		if (stacks->b->chunk == 0)
			last_chunk_to_a(stacks);
		else
			chunk_to_a(stacks);
		chunk_len = chunk_size(stacks->b, stacks->b->chunk);
	}
	else
	{
		set_as_sorted(stacks->b, chunk_len);
		if (chunk_len == 2 && stacks->b->pos < stacks->b->next->pos)
			swap(stacks->b, "sb", &stacks->ops);
		push(stacks, "pa", chunk_len);
		stacks->chunks--;
	}
	stacks->unsorted = unsorted_size(stacks->a);
}
