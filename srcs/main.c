/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 17:50:09 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/07/15 15:27:57 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <colours.h>

void	printf_list(t_stacks *stack, char *colour)
{
	printf("%s\n", colour);
	printf("%-27s%-25s\n"RST, "Stack A", "Stack B");
	print_list(&stack->a);
	printf("          ");
	print_list(&stack->b);
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	init_stacks(&stacks);
	validate_input(argc, argv, &stacks.a);
	stack_b = stack_new(22);
	stack_add_front(&stack_b, stack_new(-1));
	return (1);
}
