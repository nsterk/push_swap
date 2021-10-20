/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 17:50:09 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/20 21:07:58 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	init_stacks(t_stacks *stacks)
{
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->size = 0;
	stacks->ops = 0;
	stacks->chunks = -1;
	stacks->unsorted = -1;
}

static void	choose_sort(t_stacks *stacks)
{
	// get_index(stacks);
	if (stacks->size == 2)
		swap(stacks->a, "sa", &stacks->ops);
	else if (stacks->size == 3)
		sort_three(stacks);
	else if (stacks->size <= 9)
		sort_small(stacks);
	else
		sort_large(stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	init_stacks(&stacks);
	validate_input(argc, argv, &stacks);
	choose_sort(&stacks);
	exit_programme(0, &stacks);
	return (0);
}
