/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 20:21:01 by nsterk        #+#    #+#                 */
/*   Updated: 2021/10/20 14:20:42 by naomisterk    ########   odam.nl         */
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

int	where_is_min(t_stack *stack)
{
	t_stack	*tmp;
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

int	is_sorted(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next != NULL)
	{
		if (temp->num >= temp->next->num)
			return (0);
		temp = temp->next;
	}
	return (1);
}
