/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_small.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/22 15:48:08 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/06 19:11:49 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_three(t_stacks *stacks)
{
	if (is_sorted(stacks->a))
		return ;
	if (stacks->a->next->num > stacks->a->num)
	{
		reverse_rotate(stack->a, "rra", &stacks->ops, 1);
		if (stacks->a->num > stacks->a->next->num)
			swap(stacks->a, "sa", &stacks->ops);
		return ;
	}
	if (stacks->a->num < stacks->a->next->next->num)
	{
		swap(stacks->a, "sa", &stacks->ops);
		return ;
	}
	rotate(stacks->a, "ra", &stacks->ops, 1);
	if (stacks->a->num > stacks->a->next->num)
		swap(stacks->a, "sa", &stacks->ops);
}

void	sort_to_five(t_stacks *stacks)
{
	int	rots;

	while (list_size(stacks->a) > 3)
		push(stacks, "pb", 1);
	sort_three(stacks);
	while (stacks->b != NULL)
	{
		rots = 0;
		index_stack(stacks->a);
		stacks->mid_a = (get_node(&stacks->a, list_size(stacks->a) / 2))->num;
		if (stacks->b->num < stacks->mid_a)
		{
			while (stacks->b->num > stacks->a->num)
			{
				rotate(stacks->a, "ra", &stacks->ops, 1);
				rots++;
			}
			push(stacks, "pa", 1);
			reverse_rotate(stacks->a, "rra", &stacks->ops, rots);
		}
		else
		{
			while (stacks->b->num < stacks->a->num)
			{
				reverse_rotate(stacks->a, "rra", &stacks->ops, 1);
				rots++;
			}
			push(stacks, "pa", 1);
			rotate(stacks->a, "ra", &stacks->ops, rots);
		}
	}
}

void	sort_to_seven(t_stacks *stacks)
{
	while (list_size(stacks->a) > 5)
		push(stacks, "pb");
	sort_to_five(stacks);
}
