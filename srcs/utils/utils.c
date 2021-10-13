/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 19:22:56 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/08 17:05:37 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <unistd.h>

void	init_stacks(t_stacks *stacks)
{
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->copy = NULL;
	stacks->size = 0;
	stacks->ops = 0;
	stacks->chunks = -1;
	stacks->unsorted = -1;
}

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

void	exit_error(void)
{
	write(2, "Error\n", 6);
	system("leaks push_swap");
	exit(0);
}

t_stack	*get_node(t_stack **stack, int i)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->i == i)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}
