/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 20:07:40 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/21 20:51:47 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"
#include "../inc/push_swap.h"
#include "../inc/checker.h"
#include <fcntl.h>
#include <stdio.h>

static void	init_structs(t_stacks *stacks, t_operations *ops)
{
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->size = 0;
	stacks->ops = 0;
	stacks->chunks = -1;
	stacks->unsorted = -1;
	ops->cmd = NULL;
	ops->next = NULL;

}

static void	exit_error(t_stacks *stacks, t_operations *ops)
{
	t_operations *next;
	if (stacks)
	{
		if (stacks->a)
			free_stack(&stacks->a);
		if (stacks->b)
			free_stack(&stacks->b);
	}
	while (ops)
	{
		next = ops->next;
		free(ops);
		ops = next;
	}
	write(2, "Error\n", 6);
	exit(0);
}

static t_operations	*new_operation(const char * line)
{
	t_operations *new;

	new = malloc(sizeof(t_operations));
	if (!new)
		return (NULL);
	new->cmd = ft_strndup(line, ft_strlen(line));
	if (!new->cmd)
		return (NULL);
	new->next = NULL;
	return (new);
}

static int	add_operation(t_operations **ops, t_operations *new)
{
	t_operations	*current;
	if (!ops || !new)
		return (0);
	if (*ops == NULL)
		*ops = new;
	else
	{
		current = *ops;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int				ret;
	t_stacks		stacks;
	t_operations	ops;
	t_operations	*ptr_ops;
	char			*line;

	init_structs(&stacks, &ops);
	ptr_ops = &ops;
	validate_input(argc, argv, &stacks);
	ret = 1;
	while (ret)
	{
		ret = get_next_line(0, &line);
		if (ret == -1)
			exit_error(&stacks, &ops);
		if (!add_operation(&ptr_ops, new_operation(line)))
			exit_error(&stacks, &ops);
		free(line);
	}
	while (ptr_ops)
	{
		printf("%s\n", ptr_ops->cmd);
		ptr = ptr_ops->next;
	}
}
