# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: naomisterk <naomisterk@student.codam.nl      +#+                      #
#                                                    +#+                       #
#    Created: 2021/06/22 14:26:50 by naomisterk    #+#    #+#                  #
#    Updated: 2021/10/21 18:00:08 by naomisterk    ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# add -Werror to flags & remove -g (ook bij libft)
NAME		=	push_swap
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
MAIN_PATH	=	./srcs/
STACK_PATH	=	./srcs/stack/
SORT_PATH	=	./srcs/sort_utils/

MAIN_C		=	main.c input_validation.c sort_small.c sort_large.c \
				operations.c utils.c
STACK_C		=	stack_handling.c stack_push_pop.c stack_utils.c
SORT_C		=	find_closest.c general_sort_utils.c mid_value.c \
				min_max_values.c selection_sort.c \
				chunks/push_chunks.c chunks/find_closest_chunk.c \

MAIN_SRCS	=	$(MAIN_C:%=$(MAIN_PATH)%)
STACK_SRCS	=	$(STACK_C:%=$(STACK_PATH)%)
SORT_SRCS	=	$(SORT_C:%=$(SORT_PATH)%)
SRCS		=	$(MAIN_SRCS) $(STACK_SRCS) $(SORT_SRCS) $(UTILS_SRCS) $(OPS_SRCS)
OBJS		=	$(SRCS:%.c=%.o)

ifdef DEBUG
FLAGS	+= -g
endif

ifdef F_SANITIZE
FLAGS += -fsanitize=address
endif

all: $(NAME)

$(NAME): $(SRCS)
# make bonus -C ./libft
# cp ./libft/libft.a .
# libft.a (this belonged to the cmd below, after _Iinc)
	$(CC) $(SRCS) $(FLAGS) -Iinc -o $(NAME)
	make clean
clean:
# @ make clean -C ./libft
	@ rm -rf $(OBJS)

fclean: clean
	@ rm -rf $(NAME)
#@ rm libft.a

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus