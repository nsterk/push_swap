/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/01 12:48:47 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/06 13:20:06 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	index_stack(t_stack *stack)
{
	size_t	i;
	t_stack	*tmp;

	i = 0;
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
	int		i;
	t_stack	*tmp;

	if (!stack)
		return (0);
	tmp = stack;
	i = 0;
	max = stack->pos;
	while (tmp && tmp->chunk == stack->chunk)
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
	while (tmp && tmp->chunk == stack->chunk)
	{
		if (min > tmp->next->pos)
			min = tmp->next->pos;
		tmp = tmp->next;
	}
	return (min);
}
