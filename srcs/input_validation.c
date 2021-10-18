/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_validation.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 19:17:06 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/18 23:50:09 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	validate_input(int argc, char **argv, t_stacks *stacks)
{
	int		i;
	int		num;
	size_t	arg_len;

	// if (argc < 2)
	// 	exit_error();
	i = 1;
	while (i < argc)
	{
		arg_len = ft_strlen(argv[i]);
		if (not_integer(argv[i], arg_len))
			exit_programme(1, stacks);
		num = check_bounds(argv[i], arg_len, stacks);
		if (check_duplicates(stacks, num))
			exit_programme(1, stacks);
		stack_add_back(&stacks->a, stack_new(num));
		stack_add_back(&stacks->copy, stack_new(num));
		i++;
	}
	if (is_sorted(stacks->a))
		exit_programme(0, stacks);
	stacks->size = list_size(stacks->a);
	get_index(stacks);
}

int	check_bounds(char *str, size_t len, t_stacks *stacks)
{
	int		num;
	int		i;

	i = 0;
	num = ft_atoi(str);
	if (num == 0 && len > 1)
		exit_programme(1, stacks);
	return (num);
}

int	not_integer(char *str, size_t len)
{
	size_t	i;

	i = 0;
	if ((str[0] == '-' || str[0] == '+'))
		i++;
	while (i < len)
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_duplicates(t_stacks *stacks, int num)
{
	t_stack	*temp;

	if (!stacks || !stacks->a)
		return (0);
	temp = stacks->a;
	while (temp->next != NULL)
	{
		if (temp->num == num)
		{
			free_stack(&stacks->a);
			return (1);
		}
		temp = temp->next;
	}
	if (temp->num == num)
	{
		free_stack(&stacks->a);
		return (1);
	}
	return (0);
}
