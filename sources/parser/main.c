#include <parser.h>

int	main(int argc, char **argv)
{
	t_param	*check;

	check = parser(argc, argv);
	printf("NO:%s\nSO:%s\nEA:%s\nWE:%s\n", check->n_tex,
		check->s_tex, check->e_tex, check->w_tex);
	printf("C:%d\nF:%d\n", check->ceiln, check->floor);
	printf("x:\t%f\ny:\t%f\nangle:\t%f\n", check->x_pos, check->y_pos,
		check->angle);
	printf("height:\t%d\nwidth:\t%d\n", check->height, check->width);
	int	index = 0;
	while (check->inmap[index])
		printf("%s\n", check->inmap[index++]);
	return (0);
}
