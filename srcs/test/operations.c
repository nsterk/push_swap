/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/09 13:43:07 by nsterk        #+#    #+#                 */
/*   Updated: 2021/07/13 18:05:28 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <colours.h>

void	swap_operations(t_stack **stack_a, t_stack **stack_b)
{
	printf(U_WHITE"\n%-35s\n"RST, "Swap operations");
	printf("Stacks %sbefore%s and %safter%s \"sa\":\n", VIOLET, RST, TURQ, RST);
	printf_list(stack_a, stack_b, VIOLET);
	swap(stack_a, stack_b, "sa");
	printf_list(stack_a, stack_b, TURQ);
}

void	push_operations(t_stack **stack_a, t_stack **stack_b)
{
	printf(U_WHITE"\n%-35s\n"RST, "Push operations");
	printf("Stacks %sbefore%s and %safter%s \"pb\":\n", VIOLET, RST, TURQ, RST);
	printf_list(stack_a, stack_b, VIOLET);
	push(stack_a, stack_b, "pb");
	printf_list(stack_a, stack_b, TURQ);
}

void	rotation_operations(t_stack **stack_a, t_stack **stack_b)
{
	printf(U_WHITE"\n%-35s\n"RST, "Rotation operations");
	printf("Stacks %sbefore%s and %safter%s \"ra\":\n", VIOLET, RST, TURQ, RST);
	printf_list(stack_a, stack_b, VIOLET);
	do_rotate(stack_a);
	printf_list(stack_a, stack_b, TURQ);
}

void	rev_rotation_operations(t_stack **stack_a, t_stack **stack_b)
{
	printf(U_WHITE"\n%-35s\n"RST, "Reverse rotation operations");
	printf("Stacks %sbefore%s and %safter%s \"rra\":\n", VIOLET, RST, TURQ, RST);
	printf_list(stack_a, stack_b, VIOLET);
	do_reverse_rotate(stack_a);
	printf_list(stack_a, stack_b, TURQ);
	printf(U_WHITE"\n%-35s\n"RST, "Reverse rotation operations");
	printf("Stacks %sbefore%s and %safter%s \"rrb\":\n", VIOLET, RST, TURQ, RST);
	printf_list(stack_a, stack_b, VIOLET);
	reverse_rotate(stack_a, stack_b, "rrb");
	printf_list(stack_a, stack_b, TURQ);
}