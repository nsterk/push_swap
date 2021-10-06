/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pivots.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/22 13:28:40 by nsterk        #+#    #+#                 */
/*   Updated: 2021/09/22 18:54:09 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	get_pivots(t_stacks *stacks)
{
	if (stacks->size > 7 && stacks->size < 22)
		return (make_pivots(stacks, 3));
	else if (stacks->size > 21 && stacks->size < 101)
		return (make_pivots(stacks, 7));
	else
		return (make_pivots(stacks, 12));
}

int	make_pivots(t_stacks *stacks, int nr)
{
	int	nr_per_chunk;
	int	pivot;
	int	i;

	nr_per_chunk = stacks->size / nr;
	pivot = nr_per_chunk;
	i = 0;
	stacks->pivots = ft_calloc(nr - 1, sizeof(int));
	if (!stacks->pivots)
		return (1);
	while (pivot < (int)(stacks->size))
	{
		stacks->pivots[i] = pivot;
		i++;
		pivot += nr_per_chunk;
	}
	return (0);
}
