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

static int	init_check(int argc, char **argv)
{
	char	*temp;
	int		fd;

	if (argc != 2)
		err_msg(0);
	temp = ft_strrchr(argv[1], '.');
	if (!temp || ft_strncmp(temp, ".cub", 5))
		err_msg(0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		err_msg(0);
	return (fd);
}

t_data	*parser(int argc, char **argv)
{
	t_data	*ret;
	int		fd;

	fd = init_check(argc, argv);
	ret = init_ret();
	get_info(ret, fd);
	ret->x_ratio = (double)SCREEN_WIDTH / ret->map_width;
	ret->y_ratio = (double)SCREEN_HEIGHT / ret->map_height;
	return (ret);
}
