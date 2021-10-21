/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/30 17:09:21 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/21 16:05:24 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	swap_info(t_stack *stack, t_stack *new)
{
	stack->num = new->num;
	stack->i = new->i;
	stack->pos = new->pos;
	stack->chunk = new->chunk;
	stack->sorted = new->sorted;
}

void	swap(t_stack *stack, char *cmd, int *ops)
{
	t_stack	tmp;

	if (!stack || !stack->next)
		return ;
	tmp = *stack;
	swap_info(stack, stack->next);
	swap_info(stack->next, &tmp);
	write(1, cmd, ft_strlen(cmd));
	write(1, "\n", 1);
	ops++;
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
				write(1, cmd, ft_strlen(cmd));
				write(1, "\n", 1);
				stacks->ops++;
			}
		}
		else
		{
			if (stacks->b != NULL)
			{
				push_front(&stacks->a, pop_front(&stacks->b));
				write(1, cmd, ft_strlen(cmd));
				write(1, "\n", 1);
				stacks->ops++;
			}	
		}
		count--;
	}
}

void	rotate(t_stack **stack, char *cmd, int *ops, int count)
{
	if (!stack || !(*stack) || (*stack)->next == NULL)
		return ;
	while (count > 0)
	{
		push_back(stack, pop_front(stack));
		write(1, cmd, ft_strlen(cmd));
		write(1, "\n", 1);
		ops++;
		count--;
	}
}

void	reverse_rotate(t_stack **stack, char *cmd, int *ops, int count)
{
	if (!stack || !(*stack) || (*stack)->next == NULL)
		return ;
	while (count > 0)
	{
		push_front(stack, pop_back(stack));
		write(1, cmd, ft_strlen(cmd));
		write(1, "\n", 1);
		ops++;
		count--;
	}
}
