/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:17:20 by dwillard          #+#    #+#             */
/*   Updated: 2022/03/10 13:17:46 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void	duplicate(t_data *info)
{
	char	**temp;

	temp = ft_arrdup(info->map, 10);
	if (!temp)
		err_msg(mem_error);
	free_arr(&info->map);
	info->map = temp;
}

static void	case_error(const char *path, unsigned int bit, int flag)
{
	if (!flag)
	{
		if (!path)
			err_msg(mem_error);
		if (bit)
			err_msg(dup_tex);
	}
	if (flag)
		err_msg(dup_col);
}

static unsigned int	coltex(char *path, unsigned int bit, int flag)
{
	if (!flag)
	{
		if (path && !bit)
			return (1);
		case_error(path, bit, flag);
	}
	else
	{
		if (!bit)
			return (1);
		case_error(NULL, 0, flag);
	}
	return (0);
}

static void	check_action(t_data *info, int check, t_flag *flags)
{
	if (check == north)
		flags->flag.n = coltex(info->north.path, flags->flag.n, 0);
	else if (check == south)
		flags->flag.s = coltex(info->south.path, flags->flag.s, 0);
	else if (check == east)
		flags->flag.e = coltex(info->west.path, flags->flag.e, 0);
	else if (check == west)
		flags->flag.w = coltex(info->east.path, flags->flag.w, 0);
	else if (check == floor_clr)
		flags->flag.f = coltex(NULL, flags->flag.f, 1);
	else if (check == ceiling)
		flags->flag.c = coltex(NULL, flags->flag.c, 1);
	else
		return ;
}

void	get_info(t_data *info, char *cub)
{
	int		fd;
	int		check;
	t_flag	flags;
	char	*line;

	flags.val = 0;
	fd = open(cub, O_RDONLY);
	if (fd < 0)
		err_msg(0);
	line = NULL;
	while (get_next_line(fd, &line))
	{
		check = check_str(line, info);
		if (check == map_error)
			map(info, fd, ft_strdup(line), &flags);
		else
			check_action(info, check, &flags);
		free(line);
		line = NULL;
	}
	check_action(info, check_str(line, info), &flags);
	free(line);
	line = NULL;
	close(fd);
}
