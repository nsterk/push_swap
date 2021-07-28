/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/09 13:43:07 by nsterk        #+#    #+#                 */
/*   Updated: 2021/07/21 17:19:59 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <colours.h>

void	swap_operations(t_stacks *stacks)
{
	printf(U_WHITE"\n%-35s\n"RST, "Swap operations");
	printf("Stacks %sbefore%s and %safter%s \"sa\":\n", VIOLET, RST, TURQ, RST);
	printf_list(stacks, VIOLET);
	swap(stacks, "sa");
	printf_list(stacks, TURQ);
}

void	push_operations(t_stacks *stacks)
{
	printf(U_WHITE"\n%-35s\n"RST, "Push operations");
	printf("Stacks %sbefore%s and %safter%s \"pb\":\n", VIOLET, RST, TURQ, RST);
	printf_list(stacks, VIOLET);
	push(stacks, "pb");
	printf_list(stacks, TURQ);
}

void	rotation_operations(t_stacks *stacks)
{
	printf(U_WHITE"\n%-35s\n"RST, "Rotation operations");
	printf("Stacks %sbefore%s and %safter%s \"ra\":\n", VIOLET, RST, TURQ, RST);
	printf_list(stacks, VIOLET);
	do_rotate(&stacks->a);
	write_command("ra", &stacks->ops);
	printf_list(stacks, TURQ);
}

void	rev_rotation_operations(t_stacks *stacks)
{
	printf(U_WHITE"\n%-35s\n"RST, "Reverse rotation operations");
	printf("Stacks %sbefore%s and %safter%s \"rra\":\n", VIOLET, RST, TURQ, RST);
	printf_list(stacks, VIOLET);
	do_reverse_rotate(&stacks->a);
	write_command("rra", &stacks->ops);
	printf_list(stacks, TURQ);
	printf(U_WHITE"\n%-35s\n"RST, "Reverse rotation operations");
	printf("Stacks %sbefore%s and %safter%s \"rrb\":\n", VIOLET, RST, TURQ, RST);
	printf_list(stacks, VIOLET);
	reverse_rotate(stacks, "rrb");
	printf_list(stacks, TURQ);
}
