/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/30 17:09:21 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/07/07 15:43:43 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	fork_swap(t_stack **stack_a, t_stack **stack_b, char *cmd)
{
	if (!ft_strcmp(cmd, "sa"))
		swap(stack_a);
	else if (!ft_strcmp(cmd, "sb"))
		swap(stack_b);
	else if (!ft_strcmp(cmd, "ss"))
	{
		swap(stack_a);
		swap(stack_b);
	}
}

void	swap(t_stack **stack)
{
	int	temp;

	if (!(*stack) || !(*stack)->next)
		return ;
	temp = (*stack)->num;
	(*stack)->num = (*stack)->next->num;
	(*stack)->next->num = temp;
}

/*
commands and corresponding function calls:
sa		swap(stack_a)
sb		swap(stack_b)
ss		swap(stack_a)
		swap(stack_b)
pa		push_front(&stack_a, pop_front(stack_b))
pa		push_front(&stack_b, pop_front(stack_a))
ra		push_back(stack_a, pop_head(stack_a));

*/
void	push(t_stack **stack_a, t_stack **stack_b, char *cmd)
{
	if (!stack_a || *stack_a == NULL || !stack_b || *stack_b == NULL)
		return ;
	if (!ft_strcmp(cmd, "pa"))
		push_front(stack_a, pop_front(stack_b));
	else if (!ft_strcmp(cmd, "pb"))
		push_front(stack_b, pop_front(stack_a));
}

void	rotate(t_stack **stack)
{
	if (!stack || *stack == NULL)
		return ;
	push_back(stack, pop_front(stack));
}

void	reverse_rotate(t_stack **stack)
{
	if (!stack || *stack == NULL)
		return ;
	push_front(stack, pop_back(stack));
}
