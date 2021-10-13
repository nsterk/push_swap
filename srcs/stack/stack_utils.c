/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/01 12:48:47 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/08 17:04:45 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	index_stack(t_stack *stack, int initial)
{
	size_t	i;
	t_stack	*tmp;

	i = initial;
	tmp = stack;
	while (tmp)
	{
		tmp->i = i;
		i++;
		tmp = tmp->next;
	}
}

int	get_max(t_stack *stack)
{
	int		max;
	t_stack	*tmp;

	if (!stack)
		return (0);
	tmp = stack;
	max = stack->pos;
	while (tmp->next && tmp->chunk == stack->chunk)
	{
		if (max < tmp->next->pos)
			max = tmp->next->pos;
		tmp = tmp->next;
	}
	return (max);
}

int	get_min(t_stack *stack)
{
	int		min;
	t_stack	*tmp;

	if (!stack)
		return (0);
	tmp = stack;
	min = stack->pos;
	while (tmp->next && tmp->chunk == stack->chunk)
	{
		if (min > tmp->next->pos)
			min = tmp->next->pos;
		tmp = tmp->next;
	}
	return (min);
}
