
NAME		=	cub

SRCS		=	sources/parser/main.c		\
				sources/parser/map_utils.c	\
				sources/parser/parser.c		\
				sources/parser/parse_utils.c\
				sources/parser/get_info.c	\
				sources/parser/get_next_line/get_next_line.c\
				sources/parser/map.c		\
				sources/parser/explore_map.c\
				sources/parser/new_nod.c	\
				sources/main.c				\
				sources/calculate.c			\
				sources/draw.c				\
				sources/parser_data.c		\
				sources/hook.c				\
				sources/init.c				\
				libft/ft_putstr_fd.c		\
				libft/ft_strdup.c			\
				libft/ft_memcpy.c			\
				libft/ft_strlen.c			\
				libft/ft_atoi.c				\
				libft/ft_isdigit.c			\
				libft/ft_putendl_fd.c		\
				libft/ft_strchr.c			\
				libft/ft_strjoin.c			\
				libft/ft_strncmp.c			\
				libft/ft_strnstr.c			\
				libft/ft_strrchr.c			\
				libft/ft_free_arr.c			\
                libft/ft_arrdup.c			\
                libft/ft_calloc.c			\
                libft/ft_bzero.c			\
                libft/ft_strndup.c			\
				sources/utils.c				\
				sources/minimap.c
INCLUDES	=	./includes/

OBJ_DIR		:=	build_files
OBJS 		=	$(patsubst %,$(OBJ_DIR)/%,$(SRCS:.c=.o))
DEPS		=	$(OBJS:.o=.d)

LIBFT		=	libft/
LIBFTMAKE	=	make all -sC $(LIBFT)

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -MMD
FRAMEWORK	=	-framework OpenGL -framework AppKit

all:			$(NAME) lib

lib:
				$(LIBFTMAKE)

$(OBJ_DIR)/%.o:	%.c
				@$(CC) -I$(LIBFT) -I$(INCLUDES) $(CFLAGS) -c $< -o $@
				@printf "\033[0;33mObject %-40.100s [\033[0;32m✔\033[0;33m]\r" $@

$(NAME):
				gcc -Lmlx -lmlx -framework OpenGL -framework AppKit $(SRCS) -I$(INCLUDES) -o $(NAME)

clean:
				rm -rf $(OBJS) $(NAME)
