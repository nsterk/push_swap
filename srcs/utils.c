/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 19:22:56 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/20 20:21:58 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <unistd.h>

void	exit_programme(int status, t_stacks *stacks)
{
	if (status)
		write(2, "Error\n", 6);
	if (stacks->a != NULL)
		free_stack(&stacks->a);
	if (stacks->b != NULL)
		free_stack(&stacks->b);
	//system("leaks push_swap");
	exit(0);
}

