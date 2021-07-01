/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_extra.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/29 04:01:35 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/06/29 04:48:02 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	stack_add_int(t_stack *stack, int num)
{
	t_stack	*new;

	new = stack_new(num);
	if (!stack)
		return ;
	free(stack);
}
