#include <parser.h>

int	main(int argc, char **argv)
{
	t_data	*check;

	check = parser(argc, argv);
	printf("NO:%s\nSO:%s\nEA:%s\nWE:%s\n", check->north.path,
		check->s_tex, check->e_tex, check->w_tex);
	printf("C:%d\nF:%d\n", check->ceiling, check->floor);
	printf("x:\t%f\ny:\t%f\nangle:\t%f\n", check->xpos, check->ypos,
		check->angle);
	printf("height:\t%d\nwidth:\t%d\n", check->height, check->width);
	int	index = 0;
	while (check->inmap[index])
		printf("%s\n", check->inmap[index++]);
	return (0);
}
