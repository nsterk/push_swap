/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 17:50:09 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/07/09 13:45:22 by nsterk        ########   odam.nl         */
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
	stack_b = stack_new(22);
	stack_add_front(&stack_b, stack_new(-1));
	/* SWAP OPERATIONS */
	swap_operations(&stack_a, &stack_b);
	/* PUSH OPERATIONS	*/
	printf(U_WHITE"\n%-35s\n"RST, "Push operations");
	printf("Stacks %sbefore%s and %safter%s \"pb\":\n", VIOLET, RST, TURQ, RST);
	printf_list(&stack_a, &stack_b, VIOLET);
	push(&stack_a, &stack_b, "pb");
	printf_list(&stack_a, &stack_b, TURQ);
	/* ROTATION */
	printf(U_WHITE"\n%-35s\n"RST, "Rotation operations");
	printf("Stacks %sbefore%s and %safter%s \"ra\":\n", VIOLET, RST, TURQ, RST);
	printf_list(&stack_a, &stack_b, VIOLET);
	do_rotate(&stack_a);
	printf_list(&stack_a, &stack_b, TURQ);
	/* REVERSE ROTATING */
	printf(U_WHITE"\n%-35s\n"RST, "Reverse rotation operations");
	printf("Stacks %sbefore%s and %safter%s \"rra\":\n", VIOLET, RST, TURQ, RST);
	printf_list(&stack_a, &stack_b, VIOLET);
	do_reverse_rotate(&stack_a);
	printf_list(&stack_a, &stack_b, TURQ);
	printf(U_WHITE"\n%-35s\n"RST, "Reverse rotation operations");
	printf("Stacks %sbefore%s and %safter%s \"rrb\":\n", VIOLET, RST, TURQ, RST);
	printf_list(&stack_a, &stack_b, VIOLET);
	reverse_rotate(&stack_a, &stack_b, "rrb");
	printf_list(&stack_a, &stack_b, TURQ);
	return (1);
}
