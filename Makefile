
NAME		=	cub

SRCS		=	sources/main.c
OBJS		=	$(SRCS:.c=.o)

all:			cub

cub:			clean
				gcc -Lmlx -lmlx -framework OpenGL -framework AppKit $(SRCS) -o $(NAME)

clean:
				rm -rf $(OBJS) $(NAME)
