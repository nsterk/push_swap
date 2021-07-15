/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 17:50:09 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/07/13 18:06:21 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <colours.h>

void	printf_list(t_stack **stack_a, t_stack **stack_b, char *colour)
{
	printf("%s\n", colour);
	printf("%-27s%-25s\n"RST, "Stack A", "Stack B");
	print_list(stack_a);
	printf("          ");
	print_list(stack_b);
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = validate_input(argc, argv);
	printf("Size of stack a: %d\n", list_size(stack_a));
	stack_b = stack_new(22);
	stack_add_front(&stack_b, stack_new(-1));
	// swap_operations(&stack_a, &stack_b);
	// push_operations(&stack_a, &stack_b);
	// rotation_operations(&stack_a, &stack_b);
	// rev_rotation_operations(&stack_a, &stack_b);
	return (1);
}
