
NAME		=	cub

SRC_DIR		=	sources/

PARSER		=	parser/

GNL			=	get_next_line/

SRCS		=	$(SRC_DIR)main.c							\
				$(SRC_DIR)calculate.c						\
				$(SRC_DIR)draw.c							\
				$(SRC_DIR)hook.c							\
				$(SRC_DIR)init.c							\
				$(SRC_DIR)utils.c							\
				$(SRC_DIR)$(PARSER)parser.c					\
				$(SRC_DIR)$(PARSER)parse_utils.c			\
				$(SRC_DIR)$(PARSER)get_info.c				\
                $(SRC_DIR)$(PARSER)map.c					\
                $(SRC_DIR)$(PARSER)map_utils.c 				\
                $(SRC_DIR)$(PARSER)explore_map.c			\
                $(SRC_DIR)$(PARSER)new_nod.c				\
                $(SRC_DIR)$(PARSER)$(GNL)/get_next_line.c	\
                libft/ft_putstr_fd.c						\
                libft/ft_strdup.c							\
                libft/ft_memcpy.c							\
                libft/ft_strlen.c							\
                libft/ft_atoi.c								\
                libft/ft_isdigit.c							\
                libft/ft_putendl_fd.c						\
                libft/ft_strchr.c							\
                libft/ft_strjoin.c							\
                libft/ft_strncmp.c							\
                libft/ft_strnstr.c							\
                libft/ft_strrchr.c							\
                libft/ft_free_arr.c							\
                libft/ft_arrdup.c			                \
                libft/ft_calloc.c			                \
                libft/ft_bzero.c			                \
                libft/ft_strndup.c			                \
				sources/minimap.c
INCLUDES	=	./includes/

OBJ_DIR		:=	build_files
OBJS 		=	$(patsubst %,$(OBJ_DIR)/%,$(SRCS:.c=.o))
DEPS		=	$(OBJS:.o=.d)

LIBFT		=	libft/
LIBFTMAKE	=	make all -sC $(LIBFT)

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g -MMD
FRAMEWORK	=	-framework OpenGL -framework AppKit

all:			lib $(NAME)

lib:
				$(LIBFTMAKE)

$(OBJ_DIR)/%.o:	%.c
				@$(CC) -I$(LIBFT) -I$(INCLUDES) $(CFLAGS) -c $< -o $@
				@printf "\033[0;33mObject %-40.100s [\033[0;32m✔\033[0;33m]\r" $@

$(NAME):
				gcc -Lmlx -lmlx -framework OpenGL -framework AppKit $(SRCS) -I$(INCLUDES) -o $(NAME)

clean:
				rm -rf $(OBJS) $(NAME)
