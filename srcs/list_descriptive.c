/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_descriptive.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/13 17:42:02 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/07/13 18:01:58 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_list(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp != NULL)
	{
		if (temp->next != NULL)
			printf("%i, ", (temp)->num);
		else
			printf("%i", (temp)->num);
		temp = (temp)->next;
	}
}

int	is_sorted(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next != NULL)
	{
		if (temp->num >= temp->next->num)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	list_size(t_stack *stack)
{
	int		size;
	t_stack	*tmp;

	size = 1;
	if (stack)
	{
		tmp = stack;
		while (tmp->next != NULL)
		{
			size++;
			tmp = tmp->next;
		}
	}
	return (size);
}
