/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 19:22:56 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/07/08 16:49:43 by naomisterk    ########   odam.nl         */
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
	if (a != NULL && *a != NULL)
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

int	is_sorted(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next != NULL)
	{
		if (temp->num >= temp->next->num)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	print_list(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp != NULL)
	{
		if (temp->next != NULL)
			printf("%i, ", (temp)->num);
		else
			printf("%i", (temp)->num);
		temp = (temp)->next;
	}
}
