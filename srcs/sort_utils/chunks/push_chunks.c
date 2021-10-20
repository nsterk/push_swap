/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_chunks.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/15 16:37:34 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/20 20:22:47 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	chunk_left(t_stack *stack, int chunk)
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

/*
**	The fi.
*/

void	initial_chunk_to_b(t_stacks *stacks, int chunk)
{
	int	closest;
	int	size;

	while (chunk_left(stacks->a, chunk))
	{
		size = stacks->unsorted;
		index_stack(stacks->a);
		closest = find_closest_chunk(stacks->a, chunk, size);
		if (closest <= (size / 2))
			rotate(&stacks->a, "ra", &stacks->ops, closest);
		else
			reverse_rotate(&stacks->a, "rra", &stacks->ops, size - closest);
		stacks->a->chunk = chunk;
		push(stacks, "pb", 1);
		stacks->unsorted = unsorted_size(stacks->a);
	}
}

void	chunk_to_b(t_stacks *stacks)
{
	int	rots;
	int	mid;

	mid = get_mid(stacks->a, stacks->a->chunk);
	rots = 0;
	stacks->chunks++;
	while (under_mid_left(stacks->a, mid))
	{
		while (stacks->a->pos > mid)
		{
			rotate(&stacks->a, "ra", &stacks->ops, 1);
			rots++;
		}
		stacks->a->chunk = stacks->chunks;
		push(stacks, "pb", 1);
	}
	reverse_rotate(&stacks->a, "rra", &stacks->ops, rots);
}

void	chunk_to_a(t_stacks *stacks)
{
	int	rots;
	int	mid;

	mid = get_mid(stacks->b, stacks->b->chunk);
	rots = 0;
	while (over_mid_left(stacks->b, mid))
	{
		while (stacks->b->pos <= mid)
		{
			rotate(&stacks->b, "rb", &stacks->ops, 1);
			rots++;
		}
		push(stacks, "pa", 1);
	}
	reverse_rotate(&stacks->b, "rrb", &stacks->ops, rots);
}

void	last_chunk_to_a(t_stacks *stacks)
{
	int	closest;
	int	mid;
	int	size;

	mid = get_mid(stacks->b, stacks->b->chunk);
	while (over_mid_left(stacks->b, mid))
	{
		size = chunk_size(stacks->b, stacks->b->chunk);
		index_stack(stacks->b);
		closest = find_closest(stacks->b, mid, size, 'b');
		if (closest <= (size / 2))
			rotate(&stacks->b, "rb", &stacks->ops, closest);
		else
			reverse_rotate(&stacks->b, "rrb", &stacks->ops, size - closest);
		push(stacks, "pa", 1);
	}
}
