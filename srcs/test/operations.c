/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/09 13:43:07 by nsterk        #+#    #+#                 */
/*   Updated: 2021/07/09 13:44:25 by nsterk        ########   odam.nl         */
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
