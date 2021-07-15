/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/30 17:09:21 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/07/15 15:58:54 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap(t_stacks *stacks, char *cmd)
{
	if (!ft_strcmp(cmd, "sa"))
		do_swap(&stacks->a, &stacks->operations);
	else if (!ft_strcmp(cmd, "sb"))
		do_swap(&stacks->b, &stacks->operations);
	else if (!ft_strcmp(cmd, "ss"))
	{
		do_swap(&stacks->a, &stacks->operations);
		do_swap(&stacks->b, &stacks->operations);
	}
}

void	push(t_stacks *stacks, char *cmd)
{
	if (!ft_strcmp(cmd, "pa"))
	{
		if (stacks->b != NULL)
			push_front(&stacks->a, pop_front(&stacks->b));
	}
	else if (!ft_strcmp(cmd, "pb"))
	{
		if (stacks->a != NULL)
			push_front(&stacks->b, pop_front(&stacks->a));
	}
}

void	rotate(t_stacks *stacks, char *cmd)
{
	if (!ft_strcmp(cmd, "ra"))
		do_rotate(&stacks->a, &stacks->operations);
	else if (!ft_strcmp(cmd, "rb"))
		do_rotate(&stacks->b, &stacks->operations);
	else if (!ft_strcmp(cmd, "rr"))
	{
		do_rotate(&stacks->a, &stacks->operations);
		do_rotate(&stacks->b, &stacks->operations);
	}
}

void	reverse_rotate(t_stacks *stacks, char *cmd)
{
	if (!ft_strcmp(cmd, "rra"))
		do_reverse_rotate(&stacks->a, &stacks->operations);
	else if (!ft_strcmp(cmd, "rrb"))
		do_reverse_rotate(&stacks->b, &stacks->operations);
	else if (!ft_strcmp(cmd, "rrr"))
	{
		do_reverse_rotate(&stacks->a, &stacks->operations);
		do_reverse_rotate(&stacks->b, &stacks->operations);
	}
}
