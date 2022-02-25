
#include <parser.h>

int	main(int argc, char **argv)
{
	t_param	*check;

	check = parser(argc, argv);
	printf("NO:%s\nSO:%s\nEA:%s\nWE:%s\n", check->north_texture,
		   check->south_texture, check->east_texture, check->west_texture);
	return (0);
}