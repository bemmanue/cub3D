#include <parser.h>

static int	get_color(char *str, int index)
{
	int counter;
	int color;

	counter = 0;
	color = 0;
	while (counter < 3)
	{
		color = color << 2;
		if (ft_atoi(&str[index]) > 255 || ft_atoi(&str[index]) < 0)
			return (COLORS_ERR);
		color += ft_atoi(&str[index]);
		while (str[index] == ' ')
			index++;
		while (ft_isdigit(str[index]))
			index++;
		while (str[index] == ' ')
			index++;
		if (str[index] == ',')
			index++;
		counter++;
	}
	return (color);
}

static int	parse_news(char *str)
{
	int	index;
	int	fd;

	if ((!ft_strnstr(str, "NO ", 3) || !ft_strnstr(str, "EA ", 3))
		|| !ft_strnstr(str, "WE ", 3) ||!ft_strnstr(str, "SO ", 3))
		return (NEWS_ERROR);
	index = 3;
	while (str[index] == ' ' && str[index])
		index++;
	if (str[index])
		fd = open(&str[index], O_WRONLY);
	else
		return (NEWS_ERROR);
	if (fd < 0)
		return (NEWS_OP_ER);
	close(fd);
	if (str[0] == 'N')
		return (NORTH);
	else if (str[0] == 'E')
		return (EAST);
	else if (str[0] == 'S')
		return (SOUTH);
	else if (str[0] == 'W')
		return (WEST);
	return (0);
}

static int	parse_colors(char *str, t_param *info)
{
	int	index;
	int	counter;
	int	color;

	counter = 0;
	if ((!ft_strnstr(str, "F ", 2) || !ft_strnstr(str, "C ", 2)))
		return (COLORS_ERR);
	index = 2;
	while (str[index] == ' ' && str[index])
		index++;
	if (!str[index])
		return (COLORS_ERR);
	color = get_color(str, index);

	if (str[0] == 'C' && info->ceiling_color == 0x10000000)
		info->
	else if ((str[0] == 'F' && info->floor_color == 0x10000000)
		return (FLOOR);
	return (0);
}

int	check_str(char *str, t_param *info)
{
	if (!str)
		err_msg(MEM_ERROR);
	if (ft_strchr("NEWS", str[0]))
		return (parse_news(str));
	if (ft_strchr("FC", str[0]))
		return (parse_colors(str, info));
	if (ft_strchr("01 ", str[0]))
		return (MAP);
	return (EMPTY);
}
