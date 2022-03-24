#include <parser.h>
#include <string.h>

void	check(t_map *start)
{
	int	kek = 0;

	while (start->up)
		start = start->up;
	while (start)
	{
		int	i = 0;
		printf("number\t%d\n", kek);
		printf("string %s\n", start->str);
		while (i < start->count)
		{
			char *str = strndup(&start->str[start->interval[i][0]],
				modi(start->interval[i][1]) - start->interval[i][0]);
			printf("beg index %d\n", start->interval[i][0]);
			printf("end index %d\n", start->interval[i][1]);
			printf("str chip '%s'\n", str);
			free(str);
			i++;
		}
		printf("count\t%d\n", start->count);
		printf("len\t%d\n", start->len);
		printf("__________\n\n\n");
		start = start->down;
		kek++;
	}
}

char **real_array(t_map *start)
{
	int		len;
	int		counter;
	int		index;
	char	**ret;

	counter = 0;
	index = 0;
	len = start->len;
	while (start->up)
	{
		start = start->up;
		counter++;
		if (len < start->len)
			len = start->len;
	}
	ret = ft_calloc(counter + 1, sizeof (char *));
	if (!ret)
		err_msg(mem_error);
	while (index < counter)
	{
		ret[index] = ft_strndup(start->str, len);
		index++;
		start = start->down;
	}
	return (ret);
}

void	check_chips(t_map *line)
{
	int		left;
	int		right;
	int		flag;
	int		index;
	char	*str;

	index = 0;
	while (index < line->count)
	{
		flag = 0;
		if (line->interval[index][1] < 0)
			flag = 1;
		str = line->str;
		right = modi(line->interval[index][1]);
		left = line->interval[index][0];
		while (left < right)
		{
			if (str[left] == '0' && flag)
				err_msg(content_err);
			left++;
		}
		index++;
	}
}

int	modi(int i)
{
	if (i < 0)
		i *= -1;
	return (i);
}

