/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:14:28 by dwillard          #+#    #+#             */
/*   Updated: 2022/03/29 16:14:30 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void	replace(char **arr)
{
	int		index;
	int		jndex;

	index = 0;
	while (arr[index])
	{
		jndex = 0;
		while (arr[index][jndex])
		{
			if (arr[index][jndex] == ' ')
				arr[index][jndex] = '1';
			jndex++;
		}
		index++;
	}
}

_Noreturn void	err_msg(int flag)
{
	ft_putendl_fd("Error", 2);
	if (!flag)
		ft_putendl_fd("Missing or corrupted .cub file argument", 2);
	else if (flag == mem_error)
		ft_putendl_fd("Memory allocation error", 2);
	else if (flag == colors_err)
		ft_putendl_fd("Missing or invalid color format", 2);
	else if (flag == news_error)
		ft_putendl_fd("Missing or invalid texture path format", 2);
	else if (flag == news_op_error)
		ft_putendl_fd("Missing or corrupted texture file", 2);
	else if (flag == dup_tex)
		ft_putendl_fd("Duplicate texture path", 2);
	else if (flag == dup_col)
		ft_putendl_fd("Duplicate color definition", 2);
	else if (flag == map_error)
		ft_putendl_fd("Found new statement when expected end-of-file", 2);
	else if (flag == get_error)
		ft_putendl_fd("System call error while reading from file", 2);
	else if (flag == content_err)
		ft_putendl_fd("Unexpected symbols while reading map", 2);
	else if (flag == pos_error)
		ft_putendl_fd("Missing or invalid starting position", 2);
	exit(0);
}

void	duplicate(t_data *info)
{
	char	**temp;

	temp = ft_arrdup(info->map, 10);
	if (!temp)
		err_msg(mem_error);
	free_arr(&info->map);
	info->map = temp;
}

int	cub_atoi(const char *str)
{
	int	min;
	int	nbr;
	int	len;

	len = 0;
	min = 0;
	nbr = 0;
	while (*str == ' ')
		str++;
	if (*str == '-' && *str++)
		min = 1;
	while (str[len] >= '0' && str[len] <= '9')
	{
		nbr *= 10;
		nbr += str[len++] - 48;
	}
	if (len > 3 || nbr > 255 || min || !len)
		err_msg(colors_err);
	while (str[len] == ' ')
		len++;
	if (str[len] && str[len] != ',')
		err_msg(colors_err);
	return (nbr);
}
