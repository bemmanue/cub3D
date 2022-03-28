NAME			=	parser

FLAGS			=	-Wall -Wextra -Werror -g

OBJDIR			:=	obj_dir
OBJS			=	$(patsubst %,$(OBJDIR)/%,$(SRC:.c=.o))

VPATH			=	source/parser
SRC				=	main.c parser.c parse_utils.c get_info.c	\
 					map.c map_utils.c explore_map.c	new_nod.c	\
					$(GNL)/get_next_line.c

LIBFT			=	../../libft

GNL				=	get_next_line

$(OBJDIR)/%.o:  %.c
				cc $(FLAGS) -I../../includes -I$(GNL) -c $< -o $@

all:			lib $(NAME)

lib:
				make -sC $(LIBFT) all

$(NAME):		$(OBJS)
				cc $(OBJS) -L$(LIBFT) -lft -o parser

$(OBJS):		| $(OBJDIR)

$(OBJDIR):
				mkdir $(OBJDIR)
				mkdir $(OBJDIR)/$(GNL)

clean:
		make -sC $(LIBFT) fclean
		rm -rf */*.o
		rm -rf $(OBJDIR)
		rm -rf parser

.PHONY:	all lib clean