#include <parser.h>

static void	check_action(t_param *info, char *str, int check, char flags)
{
	(void)info;
	(void)str;
	(void)check;
	(void)flags;
}

void	get_info(t_param *info, char *cub)
{
	char	*line;
	int		fd;
	int		check;
	char	flags;

	flags = 0;
	fd = open(cub, O_WRONLY);
	if (fd < 0)
		return ;
	line = NULL;
	while (get_next_line(fd, &line))
	{
		check = check_str(line);
		check_action(info, line, check, flags);
		free(line);
		line = NULL;
	}
	close(fd);
}
