# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: naomisterk <naomisterk@student.codam.nl      +#+                      #
#                                                    +#+                       #
#    Created: 2021/06/22 14:26:50 by naomisterk    #+#    #+#                  #
#    Updated: 2021/07/01 17:41:21 by nsterk        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# add -Werror to flags & remove -g (ook bij libft)
NAME		=	push_swap
CC			=	gcc
CFLAGS		=	-Wall -Wextra -g

MAIN_PATH	=	./srcs/
STACK_PATH	=	./srcs/stack/

MAIN_C		=	gnl/get_next_line.c gnl/get_next_line_utils.c \
				main.c input_validation.c utils.c operations.c
STACK_C		=	stack_handling.c
STACK_SRCS	=	$(STACK_C:%=$(STACK_PATH)%)
MAIN_SRCS	=	$(MAIN_C:%=$(MAIN_PATH)%) 
SRCS		=	$(MAIN_SRCS) $(STACK_SRCS)
OBJS		=	$(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(SRCS)
	make bonus -C ../libft
	cp ../libft/libft.a .
	$(CC) $(SRCS) $(CFLAGS) -Iinc libft.a -o $(NAME)
	make clean

clean:
	make clean -C ../libft
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	rm libft.a

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus