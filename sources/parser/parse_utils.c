/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:17:54 by dwillard          #+#    #+#             */
/*   Updated: 2022/03/10 13:17:55 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static int	get_color(char *str, int index)
{
	int	counter;
	int	color;

	counter = 0;
	color = 0;
	while (counter < 3 && str[index])
	{
		color = color << 8;
		color += cub_atoi(&str[index]);
		while (str[index] == ' ' || ft_isdigit(str[index]))
			index++;
		if (str[index] == ',' && counter < 2)
			index++;
		counter++;
	}
	if (counter != 3 || str[index])
		err_msg(colors_err);
	return (color);
}

static int	parse_news(char *str, t_data *info)
{
	int	index;
	int	fd;

	if ((!ft_strnstr(str, "NO ", 3) && !ft_strnstr(str, "EA ", 3))
		&& !ft_strnstr(str, "WE ", 3) && !ft_strnstr(str, "SO ", 3))
		err_msg(news_error);
	index = 3;
	while (str[index] == ' ' && str[index])
		index++;
	if (str[index])
		fd = open(&str[index], O_WRONLY);
	else
		err_msg(news_error);
	if (fd < 0 || ft_strncmp(".xpm", ft_strrchr(&str[index], '.'), 4))
		err_msg(news_op_error);
	close(fd);
	if (str[0] == north)
		info->north.path = ft_strdup(&str[index]);
	else if (str[0] == east)
		info->west.path = ft_strdup(&str[index]);
	else if (str[0] == south)
		info->south.path = ft_strdup(&str[index]);
	else if (str[0] == west)
		info->east.path = ft_strdup(&str[index]);
	return ((int)str[0]);
}

static int	parse_colors(char *str, t_data *info)
{
	int	index;
	int	color;

	if ((!ft_strnstr(str, "F ", 2) && !ft_strnstr(str, "C ", 2)))
		err_msg(colors_err);
	index = 2;
	while (str[index] == ' ' && str[index])
		index++;
	if (!str[index])
		err_msg(colors_err);
	color = get_color(str, index);
	if (str[0] == 'C' && info->ceiling == 0x10000000)
	{
		info->ceiling = color;
		return (ceiling);
	}
	else if (str[0] == 'F' && info->floor == 0x10000000)
	{
		info->floor = color;
		return (floor_clr);
	}
	else
		err_msg(colors_err);
}

int	check_str(char *str, t_data *info)
{
	if (!str)
		err_msg(mem_error);
	if (ft_strlen(str) == 0)
		return (empty);
	else if (ft_strchr("NEWS", str[0]))
		return (parse_news(str, info));
	else if (ft_strchr("FC", str[0]))
		return (parse_colors(str, info));
	else if (ft_strchr("01 ", str[0]))
		return (map_error);
	return (empty);
}

int	modi(int i)
{
	if (i < 0)
		i *= -1;
	return (i);
}
