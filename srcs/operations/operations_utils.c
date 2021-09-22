/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/09 10:42:51 by nsterk        #+#    #+#                 */
/*   Updated: 2021/08/18 15:09:59 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

size_t	do_swap(t_stack **stack)
{
	int	temp;

	if (!stack || *stack == NULL || (*stack)->next == NULL)
		return (0);
	temp = (*stack)->num;
	(*stack)->num = (*stack)->next->num;
	(*stack)->next->num = temp;
	return (1);
}

size_t	do_rotate(t_stack **stack)
{
	if (!stack || *stack == NULL || (*stack)->next == NULL)
		return (0);
	push_back(stack, pop_front(stack));
	return (1);
}

size_t	do_reverse_rotate(t_stack **stack)
{
	if (!stack || *stack == NULL || (*stack)->next == NULL)
		return (0);
	push_front(stack, pop_back(stack));
	return (1);
}

size_t	rotate_count(t_stacks *stacks, size_t count, char *cmd)
{
	size_t	len;

	len = ft_strlen(cmd);
	while (count)
	{
		if (len == 2)
			rotate(stacks, cmd);
		else
			reverse_rotate(stacks, cmd);
		count--;
	}
	return (0);
}

void	write_command(char *cmd, int *ops)
{
	write(1, cmd, ft_strlen(cmd));
	write(1, "\n", 1);
	(*ops)++;
}
