/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 17:50:09 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/07/08 17:16:53 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <colours.h>

static void	printf_list(t_stack **stack_a, t_stack **stack_b, char *colour)
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
	printf(U_WHITE"\n%-35s\n"RST, "Swap operations");
	printf("Stacks %sbefore%s and %safter%s \"sa\":\n",VIOLET, RST, TURQ, RST);
	printf_list(&stack_a, &stack_b, VIOLET);
	fork_swap(&stack_a, &stack_b, "sa");
	printf_list(&stack_a, &stack_b, TURQ);
	/* PUSH OPERATIONS	*/
	printf(U_WHITE"\n%-35s\n"RST, "Push operations");
	printf("Stacks %sbefore%s and %safter%s \"pa\":\n",VIOLET, RST, TURQ, RST);
	printf_list(&stack_a, &stack_b, VIOLET);
	push(&stack_a, &stack_b, "pa");
	printf_list(&stack_a, &stack_b, TURQ);
	/* ROTATION */
	printf(U_WHITE"\n%-35s\n"RST, "Rotation operations");
	printf("Stacks %sbefore%s and %safter%s \"ra\":\n",VIOLET, RST, TURQ, RST);
	printf_list(&stack_a, &stack_b, VIOLET);
	rotate(&stack_a);
	printf_list(&stack_a, &stack_b, TURQ);
	/* REVERSE ROTATING */
	printf(U_WHITE"\n%-35s\n"RST, "Reverse rotation operations");
	reverse_rotate(&stack_a);
	printf("\nStack A after reverse rotating\n");
	print_list(&stack_a);
	return (1);
}

/*
	printf("\033[1;35mPOPPING OPERATIONS\033[0m\n");
	head = pop_front(&stack_a);
	printf("Stack A after popping head\n");
	print_list(&stack_a);
	printf("Head:\n");
	printf("%i\n", head->num);
	head = pop_back(&stack_a);
	printf("Stack A after popping tail\n");
	print_list(&stack_a);
	printf("tail:\n");
	printf("%i\n", head->num);
*/