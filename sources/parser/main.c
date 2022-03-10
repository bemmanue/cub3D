
#include <parser.h>

int	main(int argc, char **argv)
{
	t_param	*check;

	check = parser(argc, argv);
	printf("NO:%s\nSO:%s\nEA:%s\nWE:%s\n", check->n_tex,
		   check->s_tex, check->e_tex, check->w_tex);
	printf("C:%d\nF:%D\n", check->ceiln, check->floor);
	return (0);
}