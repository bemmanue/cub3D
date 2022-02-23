
NAME		=	cub

SRC_DIR		=	sources/
SRCS		=	main.c		\
				calculate.c	\
				draw.c		\
				hook.c		\
				init.c

VPATH		=	$(SRC_DIR)
INCLUDES	=	includes

OBJ_DIR		:=	build_files
OBJS 		=	$(patsubst %,$(OBJ_DIR)/%,$(SRCS:.c=.o))
DEPS		=	$(OBJS:.o=.d)

LIBFT		=	libft/
LIBFTMAKE	=	make all -sC $(LIBFT)

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -MMD
FRAMEWORK	=	-framework OpenGL -framework AppKit

lib:
				$(LIBFTMAKE)

all:			cub lib

$(OBJ_DIR)/%.o:	%.c
				@$(CC) -I$(LIBFT) -I$(INCLUDES) $(CFLAGS) -c $< -o $@
				@printf "\033[0;33mObject %-40.100s [\033[0;32m✔\033[0;33m]\r" $@


cub:			clean
				$(CC) $(INCLUDES) -L$(LIBFT) -lft -Lmlx -I./mlx -lmlx $(FRAMEWORK) $(SRCS) -o $(NAME)
				@printf '\033[1;32m%-100.100s\n\033[0m' '$(NAME) compile success!'

clean:
				@$(MAKE)	clean -sC $(LIBFT)
				@rm -rf $(OBJS) $(DEPS)
				@printf '\033[1;35mDelete objects success!\n\033[0m'

fclean:			clean
				make fclean -sC $(LIBFT)
				rm -rf $(NAME)
				@printf '\033[1;35mDelete $(NAME) success!\n\033[0m'

re:				fclean all
.PHONY:			all lib clean fclean re
-include		$(DEPS)
