NAME			=	parser

OBJDIR			:=	obj_dir
OBJS			=	$(patsubst %,$(OBJDIR)/%,$(SRC:.c=.o))

VPATH			=	source/parser
SRC				=	main.c parser.c parse_utils.c get_info.c\
					$(GNL)/get_next_line.c

LIBFT			=	../../libft

GNL				=	get_next_line

$(OBJDIR)/%.o:  %.c
				cc -I../../includes -I$(GNL) -c $< -o $@

lib:
				make -sC $(LIBFT) all

all:			lib $(OBJS)
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
