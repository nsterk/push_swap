/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 20:21:01 by nsterk        #+#    #+#                 */
/*   Updated: 2021/10/17 18:40:16 by naomisterk    ########   odam.nl         */
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

void	lowest_to_b(t_stacks *stacks)
{
	index_stack(stacks->a);
	if (where_is_min(stacks->a) <= ((int)list_size(stacks->a) / 2))
	{
		while (stacks->a->pos != get_min(stacks->a, stacks->a->chunk))
			rotate(&stacks->a, "ra", &stacks->ops, 1);
	}
	else
	{
		while (stacks->a->pos != get_min(stacks->a, stacks->a->chunk))
			reverse_rotate(&stacks->a, "rra", &stacks->ops, 1);
	}
	push(stacks, "pb", 1);
}

int		where_is_min(t_stack *stack)
{
	t_stack *tmp;
	int		min;
	int		i;

	if (!stack)
		return (-1);
	min = stack->pos;
	i = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->pos < min)
		{
			min = tmp->pos;
			i = tmp->i;
		}
		tmp = tmp->next;
	}
	return (i);
}