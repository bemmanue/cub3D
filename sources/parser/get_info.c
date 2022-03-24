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

static unsigned int	check_coltex(char *path, unsigned int bit, int flag)
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
		flags->flag.n = check_coltex(info->n_tex, flags->flag.n, 0);
	else if (check == south)
		flags->flag.s = check_coltex(info->s_tex, flags->flag.s, 0);
	else if (check == east)
		flags->flag.e = check_coltex(info->e_tex, flags->flag.e, 0);
	else if (check == west)
		flags->flag.w = check_coltex(info->w_tex, flags->flag.w, 0);
	else if (check == floor)
		flags->flag.f = check_coltex(NULL, flags->flag.f, 1);
	else if (check == ceiling)
		flags->flag.c = check_coltex(NULL, flags->flag.c, 1);
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
		return ;
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
