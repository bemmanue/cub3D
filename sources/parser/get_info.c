#include <parser.h>

static void	check_action(t_param *info, char *str, int check)
{
	(void)info;
	(void)str;
	(void)check;
}

void	get_info(t_param *info, char *cub)
{
	char	*line;
	int		fd;
	int		check;

	fd = open(cub, O_WRONLY);
	if (fd < 0)
		return ;
	line = NULL;
	while (get_next_line(fd, &line))
	{
		check = check_str(line, info);
		if (check == MAP)
		{
			free(line);
			line = NULL;
			map();
		}
		else
		{
			check_action(info, line, check);
			free(line);
			line = NULL;
		}
	}
	close(fd);
}
