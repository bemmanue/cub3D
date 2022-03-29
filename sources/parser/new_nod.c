/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_nod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:47:19 by dwillard          #+#    #+#             */
/*   Updated: 2022/03/29 12:47:25 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void	init_nods(int size, t_map *start, int y, char **src)
{
	t_map	*move;
	int		index;

	move = start;
	index = y;
	while (index > 0)
	{
		move->up = new_nod(NULL, move, src[--index]);
		move = move->up;
	}
	move = start;
	index = y + 1;
	while (index < size)
	{
		move->down = new_nod(move, NULL, src[index++]);
		move = move->down;
	}
}

static int	count(char *str, int *index)
{
	int	ind;
	int	counter;

	counter = 1;
	while (str[*index] != '1' && str[*index])
	{
		if (str[*index] != ' ')
			err_msg(content_err);
		(*index)++;
	}
	ind = *index;
	while (str[ind])
	{
		while (str[ind] == '1')
			ind++;
		if (str[ind])
			counter++;
		while (str[ind] != '1' && str[ind])
		{
			if (!ft_strchr("0 NEWS", str[ind]))
				err_msg(content_err);
			ind++;
		}
	}
	return (counter);
}

static void	cycle(t_map *map, int index, int start, char *str)
{
	static int	counter = 0;
	int			index1;

	index1 = 0;
	map->interval[counter] = malloc(sizeof (int) * 2);
	if (!map->interval[counter])
		err_msg(mem_error);
	while (index > 0 && start + index1 < index)
	{
		if (str[start + index1] == ' ' || !str[index])
			index *= -1;
		index1++;
	}
	map->interval[counter][0] = start;
	map->interval[counter][1] = index;
	counter++;
	if (counter >= map->count)
		counter = 0;
}

static void	x_dim(char *str, t_map *map)
{
	int	index;
	int	start;

	index = 0;
	start = 0;
	map->count = count(str, &index);
	map->interval = ft_calloc((map->count + 1), sizeof (int *));
	if (!map->interval)
		err_msg(mem_error);
	while (str[index])
	{
		cycle(map, index, start, str);
		while (str[index] == '1')
			index++;
		start = index;
		while (str[index] != '1' && str[index])
			index++;
	}
	if (index - start > 0)
		cycle(map, index, start, str);
}

t_map	*new_nod(t_map *up, t_map *down, char *str)
{
	t_map	*ret;

	if (!str)
		return (NULL);
	ret = malloc(sizeof (*ret));
	if (!ret)
		err_msg(mem_error);
	ret->str = ft_strdup(str);
	if (!ret->str)
		err_msg(mem_error);
	ret->count = 0;
	ret->len = ft_strlen(str);
	ret->up = up;
	ret->down = down;
	x_dim(str, ret);
	return (ret);
}
