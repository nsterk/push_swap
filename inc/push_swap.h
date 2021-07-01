/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 17:50:39 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/07/01 18:02:47 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
// # include <get_next_line.h>
# include <libft.h>

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
}				t_stacks;

/*
**	Input validation
*/
t_stack	*validate_input(int argc, char **argv);
int		check_bounds(char *str, size_t len, t_stack **stack);
int		is_integer(char *str, size_t len);
void	check_duplicates(t_stack **head, int num);

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

int		swap(t_stack **stack);
void	push(t_stack **from, t_stack **to);
/*
**	Utils
*/

int		is_sorted(t_stack *stack);
void	exit_error(void);
void	exit_programme(int status, t_stack **a, t_stack **b);

#endif