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
//
//void	check_borders(char *str)
//{
//	int	index;
//	int	count;
//
//	count = (int)ft_strlen(str);
//	index = 0;
//	while (str[index] != '1' && index < count)
//	{
//		if (str[index] != ' ')
//			err_msg(content_err);
//		index++;
//	}
//	index = count - 1;
//	while (str[index] != '1' && index > 0)
//	{
//		if (str[index] != ' ')
//			err_msg(content_err);
//		index--;
//	}
//}

int	modi(int i)
{
	if (i < 0)
		i *= -1;
	return (i);
}

