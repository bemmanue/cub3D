#include <parser.h>
#include <string.h>

static void	check(t_map *start)
{
	int	kek = 0;

	while (start->up)
		start = start->up;
	while (start->down)
	{
		int	i = 0;
		printf("number\t%d\n", kek);
		printf("string %s\n", start->str);
		while (i < start->count)
		{
			char *str = strndup(&start->str[start->interval[i][0]],
			start->interval[i][1] - start->interval[i][0]);
			printf("beg index %d\n", start->interval[i][0]);
			printf("end index %d\n", start->interval[i][1]);
			printf("%s", str);
			free(str);
			i++;
		}
		printf("\n");
		printf("count\t%d\n", start->count);
		printf("begin\t%d\n", start->begin);
		printf("len\t%d\n", start->len);
		printf("__________\n\n\n");
		start = start->down;
		kek++;
	}
}

static char	**go_through(int size, char **src, int x, int y)
{
	t_map	*start;

	if (!x || x == ft_strlen(src[y]) || !y || y == size)
		err_msg(pos_error);
	start = new_nod(NULL, NULL, src[y], x);
	init_nods(size, start, y, src);
	check(start);
	return (NULL);
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
