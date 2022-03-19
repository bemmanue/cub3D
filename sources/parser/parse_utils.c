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
		if (ft_atoi(&str[index]) > 255 || ft_atoi(&str[index]) < 0)
			return (colors_err);
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
	if (counter < 3 || str[index])
		err_msg(colors_err);
	return (color);
}

static int	parse_news(char *str, t_param *info)
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
	if (fd < 0)
		err_msg(news_op_error);
	close(fd);
	if (str[0] == north)
		info->n_tex = ft_strdup(&str[index]);
	else if (str[0] == east)
		info->e_tex = ft_strdup(&str[index]);
	else if (str[0] == south)
		info->s_tex = ft_strdup(&str[index]);
	else if (str[0] == west)
		info->w_tex = ft_strdup(&str[index]);
	return ((int)str[0]);
}

static int	parse_colors(char *str, t_param *info)
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
	if (str[0] == 'C' && info->ceiln == 0x10000000)
	{
		info->ceiln = color;
		return (ceiling);
	}
	else if (str[0] == 'F' && info->floor == 0x10000000)
	{
		info->floor = color;
		return (floor);
	}
	else
		err_msg(colors_err);
}

//static void	check_more(char *str)
//{
//
//}

int	check_str(char *str, t_param *info)
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
//	else
//		check_more(str);
	return (empty);
}
