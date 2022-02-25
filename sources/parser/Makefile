NAME			=	parser

OBJDIR			:=	objdir
OBJS			=	$(patsubst %,$(OBJDIR)/%,$(SRC:.c=.o))

VPATH			=	sources
SRC				=	main.c parser.c

LIBFT			=	../../libft

$(OBJDIR)/%.o:  %.c
				cc -I../../includes -c $< -o $@

lib:
				make -sC $(LIBFT) all

all:			lib $(OBJS)
				cc $(OBJS) -L$(LIBFT) -lft -o parser
$(OBJS):		| $(OBJDIR)

$(OBJDIR):
				mkdir $(OBJDIR)

clean:
		rm */*.o
		rm -rf objdir
		rm parser
