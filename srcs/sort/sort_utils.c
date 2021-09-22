/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/01 12:14:44 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/08/12 17:35:49 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	selection_sort(t_stack *copy)
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
	index_stack(stacks->copy);
	copy_index(stacks);
}

int	get_mid(t_stack *stack)
{
	t_stack	*tmp;
	int		total;
	int		sum;

	tmp = stack;
	total = 0;
	sum = 0;
	while (tmp)
	{
		sum += tmp->pos;
		total++;
		tmp = tmp->next;
	}
	return (sum / total);
}
