/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_validation.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 19:17:06 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/07/15 16:00:35 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	validate_input(int argc, char **argv, t_stacks *stacks)
{
	int		i;
	int		num;
	size_t	arg_len;

	if (argc < 2)
		exit_error();
	i = 1;
	while (i < argc)
	{
		arg_len = ft_strlen(argv[i]);
		is_integer(argv[i], arg_len);
		num = check_bounds(argv[i], arg_len, stacks);
		check_duplicates(&stacks->a, num);
		stack_add_back(&stacks->a, stack_new(num));
		i++;
	}
	if (is_sorted(stacks->a))
		exit_programme(0, stacks);
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

int	is_integer(char *str, size_t len)
{
	size_t	i;

	i = 0;
	if ((str[0] == '-' || str[0] == '+'))
		i++;
	while (i < len)
	{
		if (!ft_isdigit(str[i]))
			exit_error();
		i++;
	}
	return (1);
}

void	check_duplicates(t_stack **head, int num)
{
	t_stack	*temp;

	if (*head == NULL)
		return ;
	temp = *head;
	while (temp->next != NULL)
	{
		if (temp->num == num)
		{
			free_stack(head);
			exit_error();
		}
		temp = temp->next;
	}
	if (temp->num == num)
	{
		free_stack(head);
		exit_error();
	}
}
