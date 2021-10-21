/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: naomisterk <naomisterk@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 17:50:39 by naomisterk    #+#    #+#                 */
/*   Updated: 2021/10/21 16:06:37 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

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
	size_t	size;
	int		ops;
	int		per_chunk;
	int		chunks;
	int		unsorted;
}				t_stacks;


void	validate_input(int argc, char **argv, t_stacks *stacks);

void	sort_small(t_stacks *stacks);
void	sort_large(t_stacks *stacks);

/*
**	operations
*/

void	swap(t_stack *stack, char *cmd, int *ops);
void	push(t_stacks *stacks, char *cmd, int count);
void	reverse_rotate(t_stack **stack, char *cmd, int *ops, int count);
void	rotate(t_stack **stack, char *cmd, int *ops, int count);

/*
**	SORT_UTILS
*/

void	selection_sort(t_stacks *stacks, t_stack *copy);

int		find_closest_chunk(t_stack *stack, int chunk, int len);

void	initial_chunk_to_b(t_stacks *stacks, int chunk);
void	chunk_to_b(t_stacks *stacks);
void	chunk_to_a(t_stacks *stacks);
void	last_chunk_to_a(t_stacks *stacks);

int		find_closest(t_stack *a, int mid, int len);

void	set_as_sorted(t_stack *stack, int len);
int		is_sorted(t_stack *stack);
int		chunk_size(t_stack *stack, int chunk);
size_t	list_size(t_stack *stack);
int		unsorted_size(t_stack *stack);

int		get_mid(t_stack *stack, int chunk);
int		under_mid_left(t_stack *stack, int mid);
int		over_mid_left(t_stack *stack, int mid);

int		get_max(t_stack *stack, int chunk);
int		get_min(t_stack *stack, int chunk);

/*
**	STACK
*/

t_stack	*stack_new(int num);
void	stack_add_back(t_stack **stack, t_stack *new);
void	stack_add_front(t_stack **stack, t_stack *new);
t_stack	*stack_last(t_stack *stack);
void	free_stack(t_stack **stack);

t_stack	*pop_back(t_stack **stack);
t_stack	*pop_front(t_stack **stack);
void	push_back(t_stack **stack, t_stack *new);
void	push_front(t_stack **stack, t_stack *new);

void	index_stack(t_stack *stack);
t_stack	*get_node(t_stack **stack, int i);

/*
**	Utils
*/

void	exit_programme(int status, t_stacks *stacks);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);

#endif