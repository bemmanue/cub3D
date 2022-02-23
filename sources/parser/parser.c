#include <parser.h>

_Noreturn void	err_msg(int flag)
{
	ft_putendl_fd("Error", 2);
	if (!flag)
		ft_putendl_fd("Missing or invalid .cub argument", 2);
	exit(0);
}

char	**parser(int argc, char **argv)
{
	char	**ret;

	if (argc != 2 || !ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])))
		err_msg(0);
	return (ret);
}