/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   selection_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/01 12:14:44 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/21 19:43:03 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	copy_stack(t_stack *a, t_stack **copy)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		if (!stack_add_back(copy, stack_new(tmp->num)))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void	do_selection_sort(t_stack *copy)
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

static void	copy_index(t_stack *a, t_stack *copy)
{
	t_stack	*tmp_a;
	t_stack	*tmp_c;

	tmp_a = a;
	while (tmp_a)
	{
		tmp_c = copy;
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

int	selection_sort(t_stack *a)
{
	t_stack	*copy;

	copy = NULL;
	if (!copy_stack(a, &copy))
		return (0);
	do_selection_sort(copy);
	index_stack(copy);
	copy_index(a, copy);
	free_stack(&copy);
	return (1);
}
