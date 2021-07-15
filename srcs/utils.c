/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 19:22:56 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/07/15 12:15:05 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <unistd.h>

void	init_stacks(t_stacks *stacks)
{
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->ops = 0;
}

void	exit_programme(int status, t_stacks *stacks)
{
	if (status)
		write(2, "Error\n", 6);
	if (stacks->a != NULL && (stacks->)a != NULL)
		free_stack(a);
	if (b != NULL && *b != NULL)
		free_stack(b);
	system("leaks push_swap");
	exit(1);
}

void	exit_error(void)
{
	write(2, "Error\n", 6);
	system("leaks push_swap");
	exit(1);
}
