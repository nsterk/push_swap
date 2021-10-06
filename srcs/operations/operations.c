/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/30 17:09:21 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/06 19:13:00 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap(t_stacks *stack, char *cmd, int *ops)
{
	t_stack	*tmp;

	if (!stack || *stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = stack;
	stack->num = stack->next->num;
	stack->i = stack->next->i;
	stack->pos = stack->next->pos;
	stack->chunk = stack->next->chunk;
	stack->next->num = tmp->num;
	stack->next->i = tmp->i;
	stack->next->pos = tmp->pos;
	stack->next->chunk = stack->chunk;
	write_command(cmd, ops);
}

void	push(t_stacks *stacks, char *cmd, int count)
{
	while (count > 0)
	{
		if (cmd[1] == 'b')
		{
			if (stacks->a != NULL)
			{
				push_front(&stacks->b, pop_front(&stacks->a));
				write_command("pb", &stacks->ops);
			}
		}
		else
		{
			if (stacks->b != NULL)
			{
				push_front(&stacks->a, pop_front(&stacks->b));
				write_command("pa", &stacks->ops);
			}	
		}
		count--;
	}
}

void	rotate(t_stack *stack, char *cmd, int *ops, int count)
{
	if (!stack || stack->next == NULL)
		return ;
	while (count > 0)
	{
		push_back(stack, pop_front(stack));
		write_command(cmd, ops);
		count--;
	}
}

void	reverse_rotate(t_stacks *stack, char *cmd, int *ops, int count)
{
	if (!stack || stack->next == NULL)
		return ;
	while (count > 0)
	{
		push_front(stack, pop_back(stack));
		write_command(cmd, ops);
		count--;
	}
}
