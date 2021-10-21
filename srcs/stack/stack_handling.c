/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_handling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/29 03:49:25 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/21 19:56:54 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack	*stack_new(int num)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->num = num;
	new->i = 0;
	new->pos = 0;
	new->next = NULL;
	new->sorted = 0;
	new->chunk = -1;
	new->next = NULL;
	return (new);
}

int	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*current;

	if (!stack || !new)
		return (0);
	if (*stack == NULL)
		*stack = new;
	else
	{
		current = stack_last(*stack);
		current->next = new;
	}
	return (1);
}

t_stack	*stack_last(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
		return (NULL);
	current = stack;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

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

void	free_stack(t_stack **stack)
{
	t_stack	*next;

	while (*stack)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
}
