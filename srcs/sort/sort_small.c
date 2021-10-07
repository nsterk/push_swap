/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_small.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/22 15:48:08 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/07 19:49:42 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_three(t_stacks *stacks)
{
	if (is_sorted(stacks->a))
		return ;
	while (stacks->a->next->next->pos != get_max(stacks->a))
		rotate(&stacks->a, "ra", &stacks->ops, 1);
	if (stacks->a->pos > stacks->a->next->pos)
		swap(stacks->a, "sa", &stacks->ops);
}

// void	sort_to_five(t_stacks *stacks)
// {
// 	int	rots;
// 	int	mid;

// 	while (list_size(stacks->a) > 3)
// 		push(stacks, "pb", 1);
// 	sort_three(stacks);
// 	if (stacks->b->next && stacks->b->pos < stacks->b->next->pos)
// 		swap(stacks->b, "sb", &stacks->ops);
// 	while (stacks->b != NULL)
// 	{
// 		index_stack(stacks->a);
// 		mid = get_node(&stacks->a, (int)(list_size(stacks->b) / 2))->pos;
// 		rots = 0;
// 		if (stacks->b->pos > get_max(stacks->a))
// 		{
// 			push(stacks, "pa", 1);
// 			rotate(&stacks->a, "ra", &stacks->ops, 1);
// 		}
// 		else
// 		{
// 			while (stacks->a->pos < stacks->b->pos)
// 				reverse_rotate(&stacks->a, "rra", &stacks->ops, 1);
// 			push(stacks, "pa", 1);
// 			while (stacks->a->pos)
// 			rotate(&stacks->a, "ra", &stacks->ops, rots);
// 		}
// 	}
// }

// void	sort_to_seven(t_stacks *stacks)
// {
// 	while (list_size(stacks->a) > 5)
// 		push(stacks, "pb", 1);
// 	sort_to_five(stacks);
// }
