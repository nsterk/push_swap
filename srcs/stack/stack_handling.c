/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_handling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/29 03:49:25 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/03 19:49:40 by naomisterk    ########   odam.nl         */
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
	new->chunk = -1;
	return (new);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*current;

	if (!stack)
		return ;
	if (*stack == NULL)
		*stack = new;
	else
	{
		current = stack_last(*stack);
		current->next = new;
	}
}

void	stack_add_front(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;
	new->next = *stack;
	*stack = new;
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
