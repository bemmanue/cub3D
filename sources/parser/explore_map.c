#include <parser.h>

static int	help_scan(int ptr, int flag, t_map *ref)
{
	int	index;
	int	left;
	int	right;
	int	flag_down;

	index = 0;
	flag_down = 0;
	while (index < ref->count)
	{
		left = ref->interval[index][0];
		if (ref->interval[index][1] < 0)
			flag_down = 1;
		right = modi(ref->interval[index][1]);
		if (ptr >= left && ptr < right)
		{
			if (flag != flag_down)
				err_msg(content_err);
			ptr = right;
			continue ;
		}
		index++;
	}
	return (ptr);
}

static void	scan(int ptr, int stop, int flag, t_map *ref)
{
	int	temp;

	if (ptr == stop)
		return ;
	if ((!ref->up || !ref->down) && !flag)
		err_msg(content_err);
	while (ptr < stop)
	{
		temp = help_scan(ptr, flag, ref->down);
		if (temp != ptr)
		{
			ptr = temp;
			continue ;
		}
		ptr++;
	}
}

static void	checker(t_map *line)
{
	int	index;
	int	stop;
	int	flag;

	index = 0;
	while (index < line->count)
	{
		flag = 0;
		if (line->interval[index][1] < 0)
			flag = 1;
		stop = modi(line->interval[index][1]);
		if ((line->down && stop > line->down->len)
			|| (line->up && stop > line->up->len))
			err_msg(content_err);
		if (stop)
			scan(line->interval[index][0], stop, flag, line);
		index++;
	}
}

static char	**go_through(int size, char **src, int x, int y)
{
	t_map	*start;
	t_map	*temp;
	char	**ret;

	if (!x || x == (int)ft_strlen(src[y]) || !y || y == size)
		err_msg(pos_error);
	start = new_nod(NULL, NULL, src[y]);
	init_nods(size, start, y, src);
//	check(start);
	while (start->up)
		start = start->up;
	temp = start;
	while (start)
	{
		check_chips(start);
		checker(start);
		start = start->down;
	}
	ret = real_array(temp);
	destroy_map(temp);
	return (ret);
}

void	explore_map(t_data *info)
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
	info->map = go_through(size, temp, (int)info->x_pos, (int)info->y_pos);
	free_arr(&temp);
	get_params(info);
}
