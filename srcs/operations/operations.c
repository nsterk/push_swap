/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/30 17:09:21 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/07/21 15:47:28 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap(t_stacks *stacks, char *cmd)
{
	size_t	i;

	i = 0;
	if (!ft_strcmp(cmd, "sa") || !ft_strcmp(cmd, "ss"))
		i |= do_swap(&stacks->a);
	if (!ft_strcmp(cmd, "sb") || !ft_strcmp(cmd, "ss"))
		i |= do_swap(&stacks->b);
	if (i)
		write_command(cmd, &stacks->ops);
}

void	push(t_stacks *stacks, char *cmd)
{
	if (!ft_strcmp(cmd, "pa"))
	{
		if (stacks->b != NULL)
		{
			push_front(&stacks->a, pop_front(&stacks->b));
			write_command(cmd, &stacks->ops);
		}
	}
	else if (!ft_strcmp(cmd, "pb"))
	{
		if (stacks->a != NULL)
		{
			push_front(&stacks->b, pop_front(&stacks->a));
			write_command(cmd, &stacks->ops);
		}
	}
}

void	rotate(t_stacks *stacks, char *cmd)
{
	size_t	i;

	i = 0;
	if (!ft_strcmp(cmd, "ra") || !ft_strcmp(cmd, "rr"))
		i |= do_rotate(&stacks->a);
	if (!ft_strcmp(cmd, "rb") || !ft_strcmp(cmd, "rr"))
		i |= do_rotate(&stacks->b);
	if (i)
		write_command(cmd, &stacks->ops);
}

void	reverse_rotate(t_stacks *stacks, char *cmd)
{
	int	i;

	i = 0;
	if (!ft_strcmp(cmd, "rra") || !ft_strcmp(cmd, "rrr"))
		i |= do_reverse_rotate(&stacks->a);
	if (!ft_strcmp(cmd, "rrb") || !ft_strcmp(cmd, "rrr"))
		i |= do_reverse_rotate(&stacks->b);
	if (i)
		write_command(cmd, &stacks->ops);
}
