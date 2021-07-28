/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/14 17:40:48 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/07/28 03:25:35 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_three(t_stacks *stacks)
{
	if (is_sorted(stacks->a))
		return ;
	if (stacks->a->next->num > stacks->a->num)
	{
		reverse_rotate(stacks, "rra");
		if (stacks->a->num > stacks->a->next->num)
			swap(stacks, "sa");
		return ;
	}
	if (stacks->a->num < stacks->a->next->next->num)
	{
		swap(stacks, "sa");
		return ;
	}
	rotate(stacks, "ra");
	if (stacks->a->num > stacks->a->next->num)
		swap(stacks, "sa");
}

void	sort_to_five(t_stacks *stacks)
{
	size_t	rots;

	rots = 0;
	while (list_size(stacks->a) > 3)
		push(stacks, "pb");
	sort_three(stacks);
	while (stacks->b != NULL)
	{
		index_stack(&stacks->a);
		stacks->mid_a = (get_node(&stacks->a, list_size(stacks->a) / 2))->num;
		if (stacks->b->num < stacks->mid_a)
		{
			while (stacks->b->num > stacks->a->num)
			{
				rotate(stacks, "ra");
				rots++;
			}
			push(stacks, "pa");
			rots = rotate_count(stacks, rots, "rra");
		}
		else
		{
			while (stacks->b->num < stacks->a->num)
			{
				reverse_rotate(stacks, "rra");
				rots++;
			}
			push(stacks, "pa");
			rots = rotate_count(stacks, rots, "ra");
		}
	}
}

void	a_to_b(t_stacks *stacks)
{
	int		pushed;
	int		mid;
	size_t	i;

	while (stacks->len_a > 2)
	{
		index_stack(&stacks->a);
		mid = (int)stacks->len_a / 2 + 1;
		stacks->mid_a = (get_node(&stacks->a, mid))->num;
		// stacks->mid_a = stacks->len_a / 2;
		pushed = 0;
		while (pushed < mid)
		{
			if ((stack_last(stacks->a)->num < stacks->mid_a))
				reverse_rotate(stacks, "rra");
			else if (stacks->a->num > stacks->mid_a)
			{
				i = 0;
				while (stacks->a->num > stacks->mid_a && i < stacks->len_a)
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
}

void	sort_large(t_stacks *stacks)
{
	a_to_b(stacks);
}
