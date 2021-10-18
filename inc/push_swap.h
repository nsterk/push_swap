/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 17:50:39 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/19 01:41:34 by naomisterk    ########   odam.nl         */
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
	int		per_chunk;
	int		chunks;
	int		unsorted;
}				t_stacks;

/*
**	Input validation
*/
void	validate_input(int argc, char **argv, t_stacks *stacks);

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
void	swap_info(t_stack *stack, t_stack *new);
void	push(t_stacks *stacks, char *cmd, int count);
void	reverse_rotate(t_stack **stack, char *cmd, int *ops, int count);
void	rotate(t_stack **stack, char *cmd, int *ops, int count);

t_stack	*pop_back(t_stack **stack);
t_stack	*pop_front(t_stack **stack);
void	push_back(t_stack **stack, t_stack *new);
void	push_front(t_stack **stack, t_stack *new);

/*
**	Sorting
*/

void	selection_sort(t_stack *copy);
void	sort_three(t_stacks *stacks);
void	sort_small(t_stacks *stacks);
void	sort_large(t_stacks *stacks);
void	push_a_to_b(t_stacks *stacks);
void	push_b_to_a(t_stacks *stacks);

void	initial_chunk_to_b(t_stacks *stacks, int chunk);
void	chunk_to_b(t_stacks *stacks);
void	chunk_to_a(t_stacks *stacks);
void	last_chunk_to_a(t_stacks *stacks);

int		get_mid(t_stack *stack, int chunk);
int		under_mid_left(t_stack *stack, int mid);
int		over_mid_left(t_stack *stack, int mid);

int		chunk_left(t_stack *stack, int chunk);

int		find_closest_chunk(t_stack *stack, int chunk, int len); //used
int		find_closest(t_stack *a, int mid, int len, char c); //used
int		closest_from_head(t_stack *stack, int mid, char c); //used
int		closest_from_tail(t_stack *stack, int mid, int len, char c); //used
void	set_as_sorted(t_stack *stack, int len); //used
void	assign_chunks(t_stacks *stacks, int amount);
int		where_is_min(t_stack *stack);
//void	lowest_to_b(t_stacks *stacks);

/*
**	Utils
*/
void	init_stacks(t_stacks *stacks);
void	exit_error(void);
void	exit_programme(int status, t_stacks *stacks); //used
void	write_command(char *cmd, int *ops); //used
void	get_index(t_stacks *stacks); //used
int		get_max(t_stack *stack, int chunk); //used
int		get_min(t_stack *stack, int chunk); //used
void	index_stack(t_stack *stack); //being used
t_stack	*get_node(t_stack **stack, int i); //checked, is being used

/*
**	Utils: list descriptions
*/
void	print_list(t_stack **stack);
size_t	list_size(t_stack *stack);
int		is_sorted(t_stack *stack);
int		chunk_size(t_stack *stack, int chunk); //checked, is being used
int		len_unsorted(t_stack *stack); //checked, is being used

#endif