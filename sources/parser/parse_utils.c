#include <parser.h>

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

static int	parse_colors(char *str)
{
	int	index;
	int	counter;

	counter = 0;
	if ((!ft_strnstr(str, "F ", 2) || !ft_strnstr(str, "C ", 2)))
		return (COLORS_ERR);
	index = 2;
	while (str[index] == ' ' && str[index])
		index++;
	if (!str[index])
		return (COLORS_ERR);
	while (str[index] && counter < 3)
	{
		if (ft_atoi(&str[index]) > 255 || ft_atoi(&str[index]) < 0)
			return (COLORS_ERR);
		while (ft_isdigit(str[index]))
			index++;
		if (str[index] == ',')
			index++;
		counter++;
	}
	if (str[0] == 'C')
		return (CEILING);
	else
		return (FLOOR);
}

static int	parse_map(char *str)
{
	(void)str;
}

int	check_str(char *str)
{
	if (!str)
		return (10);
	if (ft_strchr("NEWS", str[0]))
		return (parse_news(str));
	if (ft_strchr("FC", str[0]))
		return (parse_colors(str));
	if (ft_strchr("01 ", str[0]))
		return (parse_map(str));
	return (EMPTY);
}
