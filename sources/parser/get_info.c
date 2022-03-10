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
			err_msg(MEM_ERROR);
		if (bit)
			err_msg(DUP_TEX);
	}
	if (flag)
		err_msg(DUP_COL);
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

static void	check_action(t_param *info, int check, t_flag *flags)
{
	if (check == NORTH)
		flags->flag.n = check_coltex(info->n_tex, flags->flag.n, 0);
	else if (check == SOUTH)
		flags->flag.s = check_coltex(info->s_tex, flags->flag.s, 0);
	else if (check == EAST)
		flags->flag.e = check_coltex(info->e_tex, flags->flag.e, 0);
	else if (check == WEST)
		flags->flag.w = check_coltex(info->w_tex, flags->flag.w, 0);
	else if (check == FLOOR)
		flags->flag.f = check_coltex(NULL, flags->flag.f, 1);
	else if (check == CEILING)
		flags->flag.c = check_coltex(NULL, flags->flag.c, 1);
	else
		return ;
}

void	get_info(t_param *info, char *cub)
{
	int		fd;
	int		check;
	t_flag	flags;
	char	*line;

	flags.val = 0;
	printf("%s\n", cub);
	fd = open(cub, O_RDONLY);
	if (fd < 0)
		return ;
	line = NULL;
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
		check = check_str(line, info);
		printf("%d\n", check);
		if (check == MAP)
			/*flags.map = map()*/;
		else
			check_action(info, check, &flags);
		free(line);
		line = NULL;
	}
	close(fd);
}
