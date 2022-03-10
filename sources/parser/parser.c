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

static t_param	*init_ret(void)
{
	t_param	*ret;

	ret = malloc(sizeof (t_param));
	if (!ret)
		return (NULL);
	ret->map = ft_calloc(100, sizeof (char *));
	if (!ret->map)
		return (NULL);
	ret->x_pos = 0;
	ret->y_pos = 0;
	ret->angle = 0;
	ret->ceiln = 0x10000000;
	ret->floor = 0x10000000;
	return (ret);
}

_Noreturn void	err_msg(int flag)
{
	ft_putendl_fd("Error", 2);
	if (!flag)
		ft_putendl_fd("Missing or corrupted .cub file argument", 2);
	if (flag == MEM_ERROR)
		ft_putendl_fd("Memory allocation error", 2);
	if (flag == COLORS_ERR)
		ft_putendl_fd("Missing or invalid color format", 2);
	if (flag == NEWS_ERROR)
		ft_putendl_fd("Missing or invalid texture path format", 2);
	if (flag == NEWS_OP_ER)
		ft_putendl_fd("Missing or corrupted texture file", 2);
	if (flag == DUP_TEX)
		ft_putendl_fd("Duplicate texture path", 2);
	if (flag == DUP_COL)
		ft_putendl_fd("Duplicate color definition", 2);
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

t_param	*parser(int argc, char **argv)
{
	t_param	*ret;

	init_check(argc, argv);
	ret = init_ret();
	if (!ret || !ret->map)
		return (ret);
	get_info(ret, argv[1]);
	return (ret);
}
