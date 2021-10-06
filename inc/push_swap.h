/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 17:50:39 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/06 21:19:47 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <libft.h>
# include <colours.h>

/*
**	includes to be removed at later stage: 
*/
# include <stdio.h>

typedef struct s_stack
{
	int				num;
	int				i;
	int				pos;
	int				chunk;
	int				sorted;
	struct s_stack	*next;
}				t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*copy;
	size_t	size;
	int		ops;
	int		chunks;
	int		unsorted;
}				t_stacks;

/*
**	Input validation
*/
void	validate_input(int argc, char **argv, t_stacks *stacks);
int		check_bounds(char *str, size_t len, t_stacks *stacks);
int		is_integer(char *str, size_t len);
void	check_duplicates(t_stack **head, int num);

/*
**	TESTING PURPOSES
*/

void	printf_list(t_stacks *stack, char *colour);

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

void	swap(t_stack *stack, char *cmd, int *ops);
void	push(t_stacks *stacks, char *cmd, int count);
void	reverse_rotate(t_stack *stack, char *cmd, int *ops, int count);
void	rotate(t_stack *stack, char *cmd, int *ops, int count);

t_stack	*pop_back(t_stack **stack);
t_stack	*pop_front(t_stack **stack);
void	push_back(t_stack **stack, t_stack *new);
void	push_front(t_stack **stack, t_stack *new);

/*
**	Sorting
*/

void	sort_three(t_stacks *stacks);
void	sort_to_five(t_stacks *stacks);
void	sort_to_seven(t_stacks *stacks);
void	sort_large(t_stacks *stacks);
void	push_a_to_b(t_stacks *stacks, int initial);
void	push_b_to_a(t_stacks *stacks);

void	initial_chunk_to_b(t_stacks *stacks);
void	chunk_to_b(t_stacks *stacks);
void	chunk_to_a(t_stacks *stacks, int to_push);

int		get_mid(t_stack *stack);
int		find_closest(t_stack *a, int mid, int len);
int		closest_from_head(t_stack *a, int mid);
int		closest_from_tail(t_stack *a, int mid);
void	set_as_sorted(t_stack *stack, int len);

/*
**	Utils
*/
void	init_stacks(t_stacks *stacks);
void	exit_error(void);
void	exit_programme(int status, t_stacks *stacks);
void	write_command(char *cmd, int *ops);
void	get_index(t_stacks *stacks);
int		get_max(t_stack *stack);
int		get_min(t_stack *stack);
void	index_stack(t_stack *stack);
t_stack	*get_node(t_stack **stack, int i);

/*
**	Utils: list descriptions
*/
void	print_list(t_stack **stack);
size_t	list_size(t_stack *stack);
int		is_sorted(t_stack *stack);
int		chunk_size(t_stack *stack);
int		len_unsorted(t_stack *stack);

#endif