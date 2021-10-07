/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/09 10:42:51 by nsterk        #+#    #+#                 */
/*   Updated: 2021/10/07 18:30:38 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap_info(t_stack *stack, t_stack *new)
{
	stack->num = new->num;
	stack->i = new->i;
	stack->pos = new->pos;
	stack->chunk = new->chunk;
	stack->sorted = new->sorted;
}

void	write_command(char *cmd, int *ops)
{
	write(1, cmd, ft_strlen(cmd));
	write(1, "\n", 1);
	(*ops)++;
}
