/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:17:51 by dwillard          #+#    #+#             */
/*   Updated: 2022/03/10 13:17:52 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static int	check_line(char *line, t_flag *flags)
{
	int	len;
	int	counter;
	int	ret;

	counter = 0;
	ret = 0;
	len = (int)ft_strlen(line);
	while (counter < len)
	{
		if (!ft_strchr(" 01NEWS", line[counter]))
			err_msg(content_err);
		if (ft_strchr("NEWS", line[counter]))
		{
			if (flags->flag.pos)
				err_msg(content_err);
			else
			{
				flags->flag.pos = 1;
				ret = counter;
			}
		}
		counter++;
	}
	return (ret);
}

static int	gnl(t_data *info, char **line, int fd, int index)
{
	int	detec;

	info->map[index] = ft_strdup(*line);
	free(*line);
	*line = NULL;
	detec = get_next_line(fd, line);
	if (!detec)
		return (0);
	if ((index + 1) % 25 == 0)
		duplicate(info);
	return (detec);
}

static void	get_map(t_data *info, int fd, char *line, t_flag *flags)
{
	int	index;
	int	detec;
	int	get;

	index = 0;
	detec = 1;
	while (detec >= 0)
	{
		get = check_line(line, flags);
		if (!detec && !ft_strlen(line))
			break ;
		if (get)
		{
			info->x_pos = get + 0.5;
			info->y_pos = index + 0.5;
		}
		detec = gnl(info, &line, fd, index);
		index++;
	}
	free(line);
	line = NULL;
	if (detec < 0)
		err_msg(get_error);
}

static int	angel(char pos)
{
	if (pos == north)
		return (0);
	else if (pos == west)
		return (90);
	else if (pos == south)
		return (180);
	else if (pos == east)
		return (270);
	return (0);
}

void	map(t_data *info, int fd, char *line, t_flag *flags)
{
	if (flags->flag.map)
		err_msg(map_error);
	else
		flags->flag.map = 1;
	get_map(info, fd, line, flags);
	if (!flags->flag.pos)
		err_msg(pos_error);
	if (flags->flag.pos)
		info->angle = angel(info->map[(int)info->y_pos][(int)info->x_pos]);
	explore_map(info);
}
