/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pivots.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/22 13:28:40 by nsterk        #+#    #+#                 */
/*   Updated: 2021/09/22 14:46:46 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	get_pivots(t_stacks *stacks)
{
	if (stacks->size > 5 && stacks->size < 22)
		make_pivots(stacks, 3);
	else if (stacks->size > 21 && stacks->size < 101)
		make_pivots(stacks, 7);
	else if (stacks->size > 100)
		make_pivots(stacks, 12);
}

int	make_pivots(t_stacks *stacks, int nr)
{
	int	nr_per_chunk;
	int	pivot;
}
