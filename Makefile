
NAME		=	cub

SRCS		=	sources/main.c		\
				sources/calculate.c	\
				sources/draw.c		\
				sources/hook.c		\
				sources/init.c

OBJS		=	$(SRCS:.c=.o)

all:			cub

cub:			clean
				gcc -Lmlx -lmlx -framework OpenGL -framework AppKit $(SRCS) -o $(NAME)

clean:
				rm -rf $(OBJS) $(NAME)
