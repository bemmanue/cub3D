#include <parser.h>

static t_param	*init_ret(void)
{
	t_param	*ret;

	ret = malloc(sizeof (t_param));
	if (!ret)
		return (NULL);
	ret->map = ft_calloc(1000, sizeof (char *));
	if (!ret->map)
		return (NULL);
	ret->x_pos = 0;
	ret->y_pos = 0;
	ret->angle = 0;
	ret->width = 0;
	ret->height = 0;
	ret->ceiling_color = 0x10000000;
	ret->floor_color = 0x10000000;
	return (ret);
}

_Noreturn void	err_msg(int flag)
{
	ft_putendl_fd("Error", 2);
	if (!flag)
		ft_putendl_fd("Missing or invalid .cub file argument", 2);
	if (flag == MEM_ERROR)
		ft_putendl_fd("Memory allocation error", 2);
	if (flag == COLORS_ERR)
		ft_putendl_fd("Missing or invalid color format", 2);
	exit(0);
}

static void	init_check(int argc, char **argv)
{
	char	*temp;

	if (argc != 2)
		err_msg(0);
	temp = ft_strrchr(argv[1], '.');
	if (!temp || ft_strncmp(temp, ".cub", 5))
		err_msg(0);
}

t_param	*parser(int argc, char **argv)
{
	t_param	*ret;

	init_check(argc, argv);
	ret = init_ret();
	if (!ret || !ret->map)
		return (ret);
	get_info(ret, argv[1]);
	return (ret);
}
