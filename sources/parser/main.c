#include <parser.h>

int	main(int argc, char **argv)
{
	t_data	*check;

	check = parser(argc, argv);
	printf("NO:%s\nSO:%s\nEA:%s\nWE:%s\n", check->north.path,
		check->south.path, check->east.path, check->west.path);
	printf("C:%d\nF:%d\n", check->ceiling, check->floor);
	printf("x:\t%f\ny:\t%f\nangle:\t%f\n", check->x_pos, check->y_pos,
		   check->angle);
	printf("height:\t%f\nwidth:\t%f\n", check->map_height, check->map_width);
	int	index = 0;
	while (check->map[index])
		printf("%s\n", check->map[index++]);
	return (0);
}
