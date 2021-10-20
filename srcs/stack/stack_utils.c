/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/01 12:48:47 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/20 19:39:33 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack	*get_node(t_stack **stack, int i)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->i == i)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

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
