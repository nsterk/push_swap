/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_small.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/22 15:48:08 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/21 19:37:51 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	where_is_min(t_stack *stack)
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

static void	lowest_to_b(t_stacks *stacks)
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

static void	sort_three(t_stacks *stacks)
{
	if ((stacks->a->num < stacks->a->next->num \
		&& stacks->a->next->num < stacks->a->next->next->num))
		return ;
	while (stacks->a->next->next->pos != get_max(stacks->a, stacks->a->chunk))
		rotate(&stacks->a, "ra", &stacks->ops, 1);
	if (stacks->a->pos > stacks->a->next->pos)
		swap(stacks->a, "sa", &stacks->ops);
}

void	sort_small(t_stacks *stacks)
{
	if (stacks->size == 2)
		swap(stacks->a, "sa", &stacks->ops);
	else
	{
		while (list_size(stacks->a) > 3)
			lowest_to_b(stacks);
		sort_three(stacks);
		while (stacks->b)
			push(stacks, "pa", 1);
	}
}
