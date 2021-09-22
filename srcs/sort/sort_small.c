/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_small.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/22 15:48:08 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/09/22 15:53:18 by naomisterk    ########   odam.nl         */
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
		index_stack(stacks->a);
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

void	sort_to_seven(t_stacks *stacks)
{
	while (list_size(stacks->a) > 5)
		push(stacks, "pb");
	sort_to_five(stacks);
}
