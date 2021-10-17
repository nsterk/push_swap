/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_small.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/22 15:48:08 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/17 18:43:15 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_three(t_stacks *stacks)
{
	if (is_sorted(stacks->a))
		return ;
	while (stacks->a->next->next->pos != get_max(stacks->a, stacks->a->chunk))
		rotate(&stacks->a, "ra", &stacks->ops, 1);
	if (stacks->a->pos > stacks->a->next->pos)
		swap(stacks->a, "sa", &stacks->ops);
}

void	sort_to_five(t_stacks *stacks)
{

	while (list_size(stacks->a) > 3)
		lowest_to_b(stacks);
	sort_three(stacks);
	while (stacks->b)
		push(stacks, "pa", 1);
}

// void	sort_to_seven(t_stacks *stacks)
// {
// 	while (list_size(stacks->a) > 5)
// 		push(stacks, "pb", 1);
// 	sort_to_five(stacks);
// }
