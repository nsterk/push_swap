/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/01 12:48:47 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/16 19:11:04 by naomisterk    ########   odam.nl         */
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

int	get_max(t_stack *stack, int chunk)
{
	int		max;
	t_stack	*tmp;

	if (!stack)
		return (0);
	tmp = stack;
	max = stack->pos;
	while (tmp)
	{
		if (tmp->chunk == chunk && max < tmp->pos)
			max = tmp->pos;
		tmp = tmp->next;
	}
	return (max);
}

int	get_min(t_stack *stack, int chunk)
{
	int		min;
	t_stack	*tmp;

	if (!stack)
		return (0);
	tmp = stack;
	min = stack->pos;
	while (tmp)
	{
		if (tmp->chunk == chunk && min > tmp->pos)
			min = tmp->pos;
		tmp = tmp->next;
	}
	return (min);
}
