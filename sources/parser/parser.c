#include <parser.h>

static t_param	*init_ret(void)
{
	t_param	*ret;

	ret = malloc(sizeof (t_param));
	if (!ret)
		return (NULL);
	ret->north_texture = malloc(sizeof (char *));
	ret->south_texture = malloc(sizeof (char *));
	ret->west_texture = malloc(sizeof (char *));
	ret->east_texture = malloc(sizeof (char *));
	ret->map = malloc(sizeof (char *));
	return (ret);
}

_Noreturn void	err_msg(int flag)
{
	ft_putendl_fd("Error", 2);
	if (!flag)
		ft_putendl_fd("Missing or invalid .cub argument", 2);
	exit(0);
}

t_param	*parser(int argc, char **argv)
{
	t_param	*ret;

	if (argc != 2 || !ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])))
		err_msg(0);
	ret = init_ret();
	if (!ret)
		return (ret);
	return (ret);
}