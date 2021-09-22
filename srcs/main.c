/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 17:50:09 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/09/22 16:01:30 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	choose_sort(t_stacks *stacks)
{
	if (stacks->size == 2)
		swap(stacks, "sa");
	else if (stacks->size == 3)
		sort_three(stacks);
	else if (stacks->size <= 7)
		sort_to_five(stacks);
	else
		sort_large(stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	init_stacks(&stacks);
	validate_input(argc, argv, &stacks);
	choose_sort(&stacks);
	printf_list(&stacks, TURQ);
	printf("total nr of operations: %i\n", stacks.ops);
	exit_programme(0, &stacks);
	return (0);
}
