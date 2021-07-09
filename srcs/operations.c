/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/30 17:09:21 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/07/09 10:51:38 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap(t_stack **stack_a, t_stack **stack_b, char *cmd)
{
	if (!ft_strcmp(cmd, "sa"))
		do_swap(stack_a);
	else if (!ft_strcmp(cmd, "sb"))
		do_swap(stack_b);
	else if (!ft_strcmp(cmd, "ss"))
	{
		do_swap(stack_a);
		do_swap(stack_b);
	}
}

void	push(t_stack **stack_a, t_stack **stack_b, char *cmd)
{
	if (!stack_a || *stack_a == NULL || !stack_b || *stack_b == NULL)
		return ;
	if (!ft_strcmp(cmd, "pa"))
		push_front(stack_a, pop_front(stack_b));
	else if (!ft_strcmp(cmd, "pb"))
		push_front(stack_b, pop_front(stack_a));
}

void	rotate(t_stack **stack_a, t_stack **stack_b, char *cmd)
{
	if (!ft_strcmp(cmd, "ra"))
		do_rotate(stack_a);
	else if (!ft_strcmp(cmd, "rb"))
		do_rotate(stack_b);
	else if (!ft_strcmp(cmd, "rr"))
	{
		do_rotate(stack_a);
		do_rotate(stack_b);
	}
}

void	reverse_rotate(t_stack **stack_a, t_stack **stack_b, char *cmd)
{
	if (!ft_strcmp(cmd, "rra"))
		do_reverse_rotate(stack_a);
	else if (!ft_strcmp(cmd, "rrb"))
		do_reverse_rotate(stack_b);
	else if (!ft_strcmp(cmd, "rrr"))
	{
		do_reverse_rotate(stack_a);
		do_reverse_rotate(stack_b);
	}
}
