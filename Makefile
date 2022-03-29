
NAME		=	cub

SRC_DIR		=	sources/

PARSER		=	parser/

GNL			=	get_next_line

SRCS		=	main.c										\
				calculate.c									\
				draw.c										\
				hook.c										\
				init.c										\
				utils.c										\
				$(PARSER)parser.c							\
				$(PARSER)parse_utils.c						\
				$(PARSER)get_info.c							\
				$(PARSER)map.c								\
				$(PARSER)map_utils.c 						\
				$(PARSER)explore_map.c						\
				$(PARSER)new_nod.c							\
				$(PARSER)$(GNL)/get_next_line.c				\
				minimap.c

INCLUDES	=	./includes/

VPATH		=	$(SRC_DIR)

OBJ_DIR		:=	build_files
OBJS 		=	$(patsubst %,$(OBJ_DIR)/%,$(SRCS:.c=.o))
DEPS		=	$(OBJS:.o=.d)

LIBFT		=	libft/
LIBFTMAKE	=	@make all -sC $(LIBFT)

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g -MMD
FRAMEWORK	=	-framework OpenGL -framework AppKit

all:			lib $(NAME)

$(OBJ_DIR)/%.o:	%.c
				@$(CC) -I$(LIBFT) -I$(INCLUDES) $(CFLAGS) -c $< -o $@
				@printf "\033[0;33mObject %-40.100s [\033[0;32m✔\033[0;33m]\r" $@

$(NAME):		$(OBJS)
				@gcc -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJS) \
-L$(LIBFT) -lft -I$(INCLUDES) -o $(NAME)

$(OBJS):		| $(OBJ_DIR)

$(OBJ_DIR):
				@mkdir $(OBJ_DIR)
				@mkdir $(OBJ_DIR)/parser
				@mkdir $(OBJ_DIR)/parser/$(GNL)

lib:
				$(LIBFTMAKE)


clean:
				@$(MAKE) -sC $(LIBFT) clean
				@rm -rf $(OBJ_DIR)

fclean:			clean
				@rm $(NAME)

re:				fclean all

.PHONY:			all lib clean fclean re
-include	$(DEPS)
