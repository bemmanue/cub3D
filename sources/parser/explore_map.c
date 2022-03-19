#include <parser.h>

static char	**go_through(int size, char **src, int x, int y)
{
	if (!x || x == ft_strlen(src[y]) || !y || y == size)
		err_msg(pos_error);
}

void	explore_map(t_param *info)
{
	char	**temp;
	int		size;

	temp = info->map;
	size = 0;
	while (temp[size])
		size++;
	info->inmap = go_through(size, temp, (int)info->x_pos, (int)info->y_pos);
}
