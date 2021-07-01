/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 19:22:56 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/06/29 16:34:41 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <unistd.h>

void	init_stacks(t_stacks *stacks)
{
	stacks->a = NULL;
	stacks->b = NULL;
}

void	exit_programme(int status, t_stack **a, t_stack **b)
{
	if (status)
		write(2, "Error\n", 6);
	if (*a != NULL)
		free_stack(a);
	if (*b != NULL)
		free_stack(a);
	system("leaks push_swap");
	exit(1);
}

void	exit_error(void)
{
	write(2, "Error\n", 6);
	system("leaks push_swap");
	exit(1);
}
