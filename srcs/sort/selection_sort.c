/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   selection_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/01 12:14:44 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/08 17:16:32 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	selection_sort(t_stack *copy)
{
	t_stack	*tmp;
	t_stack	*next;
	t_stack	*min;
	int		val;

	tmp = copy;
	while (tmp)
	{
		min = tmp;
		next = tmp->next;
		while (next)
		{
			if (min->num > next->num)
				min = next;
			next = next->next;
		}
		val = tmp->num;
		tmp->num = min->num;
		min->num = val;
		tmp = tmp->next;
	}
}

static void	copy_index(t_stacks *stacks)
{
	t_stack	*tmp_a;
	t_stack	*tmp_c;

	tmp_a = stacks->a;
	while (tmp_a)
	{
		tmp_c = stacks->copy;
		while (tmp_c)
		{
			if (tmp_a->num == tmp_c->num)
			{
				tmp_a->pos = tmp_c->i;
				tmp_a = tmp_a->next;
				break ;
			}
			tmp_c = tmp_c->next;
		}
	}
}

void	get_index(t_stacks *stacks)
{
	selection_sort(stacks->copy);
	index_stack(stacks->copy, 0);
	copy_index(stacks);
}
