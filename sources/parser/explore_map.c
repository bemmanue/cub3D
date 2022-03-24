#include <parser.h>

static void	checker(t_map *line)
{
	int	index;
	int	flag;
	int	ptr;

	index = 0;
	while (index < line->count)
	{
		flag = 0;
		if (line->interval[index][1] < 0)
			flag = 1;
		if (modi(line->interval[index][1]) > line->down->len)
			err_msg(content_err);
		ptr = line->interval[index][0];
	}
}

static char	**go_through(int size, char **src, int x, int y)
{
	t_map	*start;

	if (!x || x == ft_strlen(src[y]) || !y || y == size)
		err_msg(pos_error);
	start = new_nod(NULL, NULL, src[y]);
	init_nods(size, start, y, src);
	check(start);
	while (start->up)
		start = start->up;
	while (start->down)
	{
		check_chips(start);
//		checker(start);
		start = start->down;
	}
	return (NULL);
}

void	explore_map(t_param *info)
{
	char	**temp;
	int		size;

	temp = info->map;
	size = 0;
	while (temp[size])
	{
		if (!ft_strlen(temp[size]))
			err_msg(map_error);
		size++;
	}
	info->inmap = go_through(size, temp, (int)info->x_pos, (int)info->y_pos);
}
