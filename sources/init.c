/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:25:27 by bemmanue          #+#    #+#             */
/*   Updated: 2022/03/29 13:25:28 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_texture(t_data *data, t_texture *texture)
{
	texture->image = malloc(sizeof(t_image));
	if (!texture->image)
		exit_error("Memory error\n");
	texture->image->img = mlx_xpm_file_to_image
		(data->mlx, texture->path, &texture->width, &texture->height);
	if (!texture->image->img)
		exit_error("Memory error\n");
	texture->image->addr = mlx_get_data_addr(texture->image->img,
			&texture->image->bpp,
			&texture->image->len, &texture->image->end);
}

void	init_minimap(t_data *data)
{
	t_minimap	*minimap;

	minimap = &data->minimap;
	if (data->map_width >= data->map_height)
	{
		minimap->x_len = (double)SCREEN_WIDTH / 7.0;
		minimap->y_len = minimap->x_len * (data->map_height / data->map_width);
	}
	else
	{
		minimap->y_len = (double)SCREEN_HEIGHT / 7.0;
		minimap->x_len = minimap->y_len * (data->map_width / data->map_height);
	}
	minimap->x_ratio = minimap->x_len / data->map_width;
	minimap->y_ratio = minimap->y_len / data->map_height;
	minimap->x_shift = 10;
	minimap->y_shift = SCREEN_HEIGHT - minimap->y_len - 10;
}

void	init_data(t_data *data)
{
	init_texture(data, &data->north);
	init_texture(data, &data->east);
	init_texture(data, &data->south);
	init_texture(data, &data->west);
	init_minimap(data);
}
