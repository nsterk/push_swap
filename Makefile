# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: naomisterk <naomisterk@student.codam.nl      +#+                      #
#                                                    +#+                       #
#    Created: 2021/06/22 14:26:50 by naomisterk    #+#    #+#                  #
#    Updated: 2021/10/20 21:05:38 by naomisterk    ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# add -Werror to flags & remove -g (ook bij libft)
NAME		=	push_swap
CC			=	gcc
FLAGS		=	-Wall -Wextra -g
MAIN_PATH	=	./srcs/
STACK_PATH	=	./srcs/stack/
GNL_PATH	=	./srcs/gnl/
SORT_PATH	=	./srcs/sort_utils/

MAIN_C		=	main.c input_validation.c utils.c \
				sort_small.c sort_large.c \
				operations.c operations_utils.c
STACK_C		=	stack_handling.c stack_push_pop.c stack_utils.c
SORT_C		=	find_closest.c general_sort_utils.c mid_value.c \
				min_max_values.c selection_sort.c \
				chunks/push_chunks.c chunks/find_closest_chunk.c \
# GNL_C		=	get_next_line.c get_next_line_utils.c

MAIN_SRCS	=	$(MAIN_C:%=$(MAIN_PATH)%)
STACK_SRCS	=	$(STACK_C:%=$(STACK_PATH)%)
SORT_SRCS	=	$(SORT_C:%=$(SORT_PATH)%)
# GNL_SRCS	=	$(GNL_C:%=$(GNL_PATH)%)
SRCS		=	$(MAIN_SRCS) $(STACK_SRCS) $(SORT_SRCS) $(UTILS_SRCS) $(OPS_SRCS) # $(GNL_SRCS)
OBJS		=	$(SRCS:%.c=%.o)

# FLAGS		= $(W_FLAGS)

ifdef DEBUG
FLAGS	+= -g
endif

ifdef F_SANITIZE
FLAGS += -fsanitize=address
endif

all: $(NAME)

$(NAME): $(SRCS)
	make bonus -C ../libft
	cp ../libft/libft.a .
	$(CC) $(SRCS) $(FLAGS) -Iinc libft.a -o $(NAME)
	make clean

clean:
	@ make clean -C ../libft
	@ rm -rf $(OBJS)

fclean: clean
	@ rm -rf $(NAME)
	@ rm libft.a

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus