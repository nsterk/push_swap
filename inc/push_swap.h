/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 17:50:39 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/07/15 12:10:49 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <libft.h>
# include <colours.h>

/*
**	includes to be removed at later stage: 
*/
# include <stdio.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}				t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
	int		size;
	int		ops;
}				t_stacks;

/*
**	Input validation
*/
t_stack	*validate_input(int argc, char **argv);
int		check_bounds(char *str, size_t len, t_stack **stack);
int		is_integer(char *str, size_t len);
void	check_duplicates(t_stack **head, int num);

/*
**	TESTING PURPOSES
*/
void	swap_operations(t_stack **stack_a, t_stack **stack_b);
void	push_operations(t_stack **stack_a, t_stack **stack_b);
void	rotation_operations(t_stack **stack_a, t_stack **stack_b);
void	rev_rotation_operations(t_stack **stack_a, t_stack **stack_b);
void	printf_list(t_stack **stack_a, t_stack **stack_b, char *colour);

/*
** Stack handling
*/

t_stack	*stack_new(int num);
void	stack_add_back(t_stack **stack, t_stack *new);
void	stack_add_front(t_stack **stack, t_stack *new);
t_stack	*stack_last(t_stack *stack);
void	free_stack(t_stack **stack);

/*
**	Operations
*/

void	do_swap(t_stack **stack, int *operations);
void	swap(t_stack **stack_a, t_stack **stack_b, char *cmd);
void	push(t_stack **stack_a, t_stack **stack_b, char *cmd);
void	reverse_rotate(t_stack **stack_a, t_stack **stack_b, char *cmd);
void	rotate(t_stack **stack_a, t_stack **stack_b, char *cmd);
void	do_rotate(t_stack **stack);
void	do_reverse_rotate(t_stack **stack);
t_stack	*pop_back(t_stack **stack);
t_stack	*pop_front(t_stack **stack);
void	push_back(t_stack **stack, t_stack *new);
void	push_front(t_stack **stack, t_stack *new);

/*
**	Sorting
*/

void	sort_three(t_stack **stack);

/*
**	Utils
*/

void	exit_error(void);
void	exit_programme(int status, t_stacks *stacks);

/*
**	Utils: list descriptions
*/
void	print_list(t_stack **stack);
int		list_size(t_stack *stack);
int		is_sorted(t_stack *stack);

#endif