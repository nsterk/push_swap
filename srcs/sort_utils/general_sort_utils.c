/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   general_sort_utils.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 20:21:01 by nsterk        #+#    #+#                 */
/*   Updated: 2021/10/21 15:02:02 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	set_as_sorted(t_stack *stack, int len)
{
	if (len == 2)
	{
		stack->next->sorted = 1;
		stack->next->chunk = -1;
	}
	if (len == 2 || len == 1)
	{
		stack->sorted = 1;
		stack->chunk = -1;
	}
}

int	is_sorted(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next != NULL)
	{
		if (temp->num >= temp->next->num)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	chunk_size(t_stack *stack, int chunk)
{
	int		size;
	t_stack	*tmp;

	size = 0;
	if (stack)
	{
		tmp = stack;
		while (tmp && tmp->chunk == stack->chunk)
		{
			if (tmp->chunk == chunk)
				size++;
			tmp = tmp->next;
		}
	}
	return (size);
}

size_t	list_size(t_stack *stack)
{
	size_t	size;
	t_stack	*tmp;

	size = 0;
	if (stack)
	{
		tmp = stack;
		while (tmp)
		{
			size++;
			tmp = tmp->next;
		}
	}
	return (size);
}

int	unsorted_size(t_stack *stack)
{
	int		size;
	t_stack	*tmp;

	size = 0;
	if (stack)
	{
		tmp = stack;
		while (tmp && tmp->sorted == 0)
		{
			size++;
			tmp = tmp->next;
		}
	}
	return (size);
}
