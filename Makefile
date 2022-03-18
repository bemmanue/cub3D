
NAME		=	cub

SRCS		=	sources/main.c			\
				sources/calculate.c		\
				sources/draw.c			\
				sources/parser_data.c	\
				sources/hook.c			\
				sources/init.c			\
				libft/ft_putstr_fd.c	\
				libft/ft_strdup.c		\
				libft/ft_memcpy.c		\
				libft/ft_strlen.c		\
				sources/utils.c			\
				sources/minimap.c

OBJS		=	$(SRCS:.c=.o)

all:			cub

cub:			clean
				gcc -Lmlx -lmlx -framework OpenGL -framework AppKit $(SRCS) -o $(NAME)

clean:
				rm -rf $(OBJS) $(NAME)
