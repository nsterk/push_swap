# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: naomisterk <naomisterk@student.codam.nl      +#+                      #
#                                                    +#+                       #
#    Created: 2021/06/22 14:26:50 by naomisterk    #+#    #+#                  #
#    Updated: 2021/07/14 17:36:55 by naomisterk    ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# add -Werror to flags & remove -g (ook bij libft)
NAME		=	push_swap
CC			=	gcc
FLAGS		=	-Wall -Wextra -fsanitize=address -g
MAIN_PATH	=	./srcs/
STACK_PATH	=	./srcs/stack/
TEST_PATH	=	./srcs/test/

MAIN_C		=	gnl/get_next_line.c gnl/get_next_line_utils.c \
				main.c input_validation.c utils.c operations.c \
				stack_pop.c stack_push.c operations_utils.c \
				list_descriptive.c sort.c
STACK_C		=	stack_handling.c
TEST_C		=	operations.c
STACK_SRCS	=	$(STACK_C:%=$(STACK_PATH)%)
MAIN_SRCS	=	$(MAIN_C:%=$(MAIN_PATH)%) 
TEST_SRCS	=	$(TEST_C:%=$(TEST_PATH)%)
SRCS		=	$(MAIN_SRCS) $(STACK_SRCS) $(TEST_SRCS)
OBJS		=	$(SRCS:%.c=%.o)

# ifdef DEBUG
# FLAGS	= -g
# else
# FLAGS	= $(W_FLAGS)
# endif

# ifdef F_SANITIZE
# FLAGS += -fsanitize=address
# endif

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