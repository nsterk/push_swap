/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_descriptive.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/13 17:42:02 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/07 20:07:45 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <colours.h>

void	print_list(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp != NULL)
	{
		if (temp->next != NULL)
			printf("num: %i, ", (temp)->num);
		else
			printf("num: %i", (temp)->num);
		temp = (temp)->next;
	}
}

void	printf_list(t_stacks *stacks, char *colour)
{
	printf("%s\n", colour);
	printf("%-27s%-25s\n"RST, "Stack A", "Stack B");
	print_list(&stacks->a);
	printf("          ");
	print_list(&stacks->b);
	printf("\n");
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

size_t	list_size(t_stack *stack)
{
	size_t	size;
	t_stack	*tmp;

	size = 0;
	if (stack)
	{
		size = 1;
		tmp = stack;
		while (tmp->next != NULL)
		{
			size++;
			tmp = tmp->next;
		}
	}
	return (size);
}

int	chunk_size(t_stack *stack)
{
	int		size;
	t_stack	*tmp;

	size = 0;
	if (stack)
	{
		tmp = stack;
		while (tmp && tmp->chunk == stack->chunk)
		{
			size++;
			tmp = tmp->next;
		}
	}
	return (size);
}

int	len_unsorted(t_stack *stack)
{
	int		size;
	t_stack	*tmp;

	size = 0;
	if (stack)
	{
		size = 1;
		tmp = stack;
		while (tmp->sorted == 0 && tmp->next != NULL &&	\
			tmp->next->chunk == tmp->chunk)
		{
			size++;
			tmp = tmp->next;
		}
	}
	return (size);
}
