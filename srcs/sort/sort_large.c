/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_large.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/14 17:40:48 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/14 12:16:21 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_large(t_stacks *stacks)
{
	stacks->unsorted = (int)stacks->size;
	push_a_to_b(stacks, 1);
	while (stacks->b)
	{
		push_b_to_a(stacks);
		push_a_to_b(stacks, 0);
	}
	return ;
}

void	push_a_to_b(t_stacks *stacks, int initial)
{
	while (stacks->unsorted > 2)
	{
		stacks->chunks++;
		if (initial)
			initial_chunk_to_b(stacks);
		else
			chunk_to_b(stacks);
		stacks->unsorted = len_unsorted(stacks->a);
	}
	if (stacks->unsorted == 2)
	{
		if (stacks->a->pos > stacks->a->next->pos)
			swap(stacks->a, "sa", &stacks->ops);
	}
	set_as_sorted(stacks->a, stacks->unsorted);
	stacks->unsorted = 0;
}

void	initial_chunk_to_b(t_stacks *stacks)
{
	int	closest;
	int	to_push;
	int	mid;
	int	size;

	to_push = (stacks->unsorted + 1) / 2;
	mid = get_mid(stacks->a);
	while (under_mid_left(stacks->a, mid))
	{
		size = chunk_size(stacks->a);
		index_stack(stacks->a, 0);
		closest = find_closest(stacks->a, mid, size);
		if (closest <= (size / 2))
			rotate(&stacks->a, "ra", &stacks->ops, closest);
		else
			reverse_rotate(&stacks->a, "rra", &stacks->ops, size - closest);
		stacks->a->chunk = stacks->chunks;
		push(stacks, "pb", 1);
	}
}

void	chunk_to_b(t_stacks *stacks)
{
	int	rots;
	int	to_push;
	int	mid;

	to_push = (chunk_size(stacks->a) + 1) / 2;
	mid = get_mid(stacks->a);
	rots = 0;
	while (under_mid_left(stacks->a, mid))
	{
		while (stacks->a->pos > mid)
		{
			rotate(&stacks->a, "ra", &stacks->ops, 1);
			rots++;
		}
		stacks->a->chunk = stacks->chunks;
		push(stacks, "pb", 1);
		to_push--;
	}
	reverse_rotate(&stacks->a, "rra", &stacks->ops, rots);
}

void	push_b_to_a(t_stacks *stacks)
{
	int	chunk_len;

	chunk_len = chunk_size(stacks->b);
	if (chunk_len > 2)
	{
		index_stack(stacks->b, 0);
		chunk_to_a(stacks, chunk_len / 2);
		chunk_len = chunk_size(stacks->b);
	}
	else
	{
		set_as_sorted(stacks->b, chunk_len);
		if (chunk_len == 2 && stacks->b->pos < stacks->b->next->pos)
			swap(stacks->b, "sb", &stacks->ops);
		push(stacks, "pa", chunk_len);
		stacks->chunks--;
	}
	stacks->unsorted = len_unsorted(stacks->a);
}

void	chunk_to_a(t_stacks *stacks, int to_push)
{
	int	rots;
	int	mid;

	mid = get_mid(stacks->b);
	rots = 0;
	while (over_mid_left(stacks->b, mid))
	{
		while (stacks->b->pos <= mid && over_mid_left(stacks->b, mid))
		{
			rotate(&stacks->b, "rb", &stacks->ops, 1);
			rots++;
		}
		push(stacks, "pa", 1);
		to_push--;
	}
	reverse_rotate(&stacks->b, "rrb", &stacks->ops, rots);
}

/*
void	a_to_b(t_stacks *stacks)
{
	int		pushed;
	int		mid;
	size_t	i;

	while (stacks->len_a > 2)
	{
		index_stack(stacks->a);
		mid = (int)stacks->len_a / 2;
		stacks->mid_a = get_mid(stacks->a);
		// stacks->mid_a = (get_node(&stacks->a, mid))->pos;
		pushed = 0;
		while (pushed < mid)
		{
			if ((stack_last(stacks->a)->pos < stacks->mid_a))
				reverse_rotate(stacks, "rra");
			else if (stacks->a->pos > stacks->mid_a)
			{
				i = 0;
				while (stacks->a->pos > stacks->mid_a && i < stacks->len_a)
				{
					rotate(stacks, "ra");
					i++;
				}
			}
			push(stacks, "pb");
			pushed++;
		}
		stacks->len_a = list_size(stacks->a);
	}
	if (stacks->a->next != NULL && stacks->a->pos >= stacks->a->next->pos)
		swap(stacks, "sa");
}

void	b_to_a(t_stacks *stacks)
{
	int		pushed;
	int		mid;
	int		max;
	size_t	i;

	stacks->len_b = list_size(stacks->b);
	// print_list(&stacks->b);
	while (stacks->len_b > 1)
	{
		index_stack(stacks->b);
		max = get_max(stacks->b);
		mid = (int)stacks->len_b / 2;
		// stacks->mid_b = get_mid(stacks->b);
		// stacks->mid_b = (get_node(&stacks->b, mid))->pos;
		while (stacks->a->i != max )
		{
			if ((stack_last(stacks->b)->pos > stacks->mid_b))
				reverse_rotate(stacks, "rrb");
			else if (stacks->b->pos < stacks->mid_b)
			{
				i = 0;
				while (stacks->b->pos < stacks->mid_b && i < stacks->len_b)
				{
					rotate(stacks, "rb");
					i++;
				}
			}
			push(stacks, "pa");
			pushed++;
		}
		stacks->len_b = list_size(stacks->b);
	}
	push(stacks, "pa");
}

*/