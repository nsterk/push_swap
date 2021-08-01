# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: naomisterk <naomisterk@student.codam.nl      +#+                      #
#                                                    +#+                       #
#    Created: 2021/06/22 14:26:50 by naomisterk    #+#    #+#                  #
#    Updated: 2021/08/01 12:48:28 by naomisterk    ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# add -Werror to flags & remove -g (ook bij libft)
NAME		=	push_swap
CC			=	gcc
FLAGS		=	-Wall -Wextra -g -fsanitize=address
MAIN_PATH	=	./srcs/
STACK_PATH	=	./srcs/stack/
GNL_PATH	=	./srcs/gnl/
SORT_PATH	=	./srcs/sort/
UTILS_PATH	=	./srcs/utils/
OPS_PATH	=	./srcs/operations/

MAIN_C		=	main.c input_validation.c list_descriptive.c
STACK_C		=	stack_handling.c stack_pop.c stack_push.c \
				stack_utils.c
SORT_C		=	sort_utils.c sort.c
OPS_C		=	operations.c operations_utils.c
UTILS_C		=	utils.c
GNL_C		=	get_next_line.c get_next_line_utils.c

STACK_SRCS	=	$(STACK_C:%=$(STACK_PATH)%)
MAIN_SRCS	=	$(MAIN_C:%=$(MAIN_PATH)%)
SORT_SRCS	=	$(SORT_C:%=$(SORT_PATH)%)
UTILS_SRCS	=	$(UTILS_C:%=$(UTILS_PATH)%)
OPS_SRCS	=	$(OPS_C:%=$(OPS_PATH)%)
# GNL_SRCS	=	$(GNL_C:%=$(GNL_PATH)%)
SRCS		=	$(MAIN_SRCS) $(STACK_SRCS) $(SORT_SRCS) $(UTILS_SRCS) $(OPS_SRCS) # $(GNL_SRCS)
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