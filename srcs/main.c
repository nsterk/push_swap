/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 17:50:09 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/06/29 16:30:20 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	t_stack		*stack_a;
	t_stack		*next;

	stack_a = validate_input(argc, argv);
	while (stack_a)
	{
		next = stack_a->next;
		printf("%i\n", stack_a->num);
		free(stack_a);
		stack_a = next;
	}
	return (1);
}
