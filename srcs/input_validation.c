/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_validation.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 19:17:06 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/21 19:30:11 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static void	check_if_integer(char *str, size_t len, t_stacks *stacks)
{
	size_t	i;

	i = 0;
	if ((str[0] == '-' || str[0] == '+'))
		i++;
	while (i < len)
	{
		if (!ft_isdigit(str[i]))
			exit_programme(1, stacks);
		i++;
	}
}

static int	check_bounds(char *str, size_t len, t_stacks *stacks)
{
	int		num;
	int		i;

	i = 0;
	num = ft_atoi(str);
	if (num == 0 && len > 1)
	{
		free_stack(&stacks->a);
		exit_programme(1, stacks);
	}
	return (num);
}

static void	check_duplicates(t_stacks *stacks, int num)
{
	t_stack	*tmp;

	if (!stacks || !stacks->a)
		return ;
	tmp = stacks->a;
	while (tmp)
	{
		if (tmp->num == num)
		{
			free_stack(&stacks->a);
			exit_programme(1, stacks);
		}
		tmp = tmp->next;
	}
}

void	validate_input(int argc, char **argv, t_stacks *stacks)
{
	int		i;
	int		num;
	size_t	arg_len;

	i = 1;
	while (i < argc)
	{
		arg_len = ft_strlen(argv[i]);
		check_if_integer(argv[i], arg_len, stacks);
		num = check_bounds(argv[i], arg_len, stacks);
		check_duplicates(stacks, num);
		if (!stack_add_back(&stacks->a, stack_new(num)))
			exit_programme(1, stacks);
		i++;
	}
	if (is_sorted(stacks->a))
		exit_programme(0, stacks);
	stacks->size = list_size(stacks->a);
}
