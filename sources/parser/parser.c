/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:17:57 by dwillard          #+#    #+#             */
/*   Updated: 2022/03/10 13:17:58 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static t_data	*init_ret(void)
{
	t_data	*ret;

	ret = malloc(sizeof (t_data));
	if (!ret)
		return (NULL);
	ret->map = ft_calloc(25, sizeof (char *));
	if (!ret->map)
		err_msg(mem_error);
	ret->x_pos = 0;
	ret->y_pos = 0;
	ret->angle = 0;
	ret->ceiling = 0x10000000;
	ret->floor = 0x10000000;
	return (ret);
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

static void	init_check(int argc, char **argv)
{
	char	*temp;

	if (argc != 2)
		err_msg(0);
	temp = ft_strrchr(argv[1], '.');
	if (!temp || ft_strncmp(temp, ".cub", 5))
		err_msg(0);
}

t_data	*parser(int argc, char **argv)
{
	t_data	*ret;

	init_check(argc, argv);
	ret = init_ret();
	get_info(ret, argv[1]);
	return (ret);
}
