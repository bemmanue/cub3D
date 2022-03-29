/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:25:32 by bemmanue          #+#    #+#             */
/*   Updated: 2022/03/29 13:25:33 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	condition(double x, double y, t_data *data, t_minimap *minimap)
{
	if (x / minimap->x_ratio < data->x_pos + minimap->x_ratio / 50.0
		&& x / minimap->x_ratio > data->x_pos - minimap->x_ratio / 50.0
		&& y / minimap->y_ratio < data->y_pos + minimap->y_ratio / 50.0
		&& y / minimap->y_ratio > data->y_pos - minimap->y_ratio / 50.0)
		return (1);
	return (0);
}

void	draw_minimap(t_data *data)
{
	t_minimap	*minimap;
	double		x;
	double		y;
	int			x_pixel;
	int			y_pixel;

	minimap = &data->minimap;
	y = 0.0;
	while (y < minimap->y_len)
	{
		x = 0.0;
		while (x < minimap->x_len)
		{
			x_pixel = x + minimap->x_shift;
			y_pixel = y + minimap->y_shift;
			if (is_wall(data, x / minimap->x_ratio, y / minimap->y_ratio))
				my_mlx_pixel_put(&data->image, x_pixel, y_pixel, 0x00000000);
			else
				my_mlx_pixel_put(&data->image, x_pixel, y_pixel, 0x00CCCCCC);
			if (condition(x, y, data, minimap))
				my_mlx_pixel_put(&data->image, x_pixel, y_pixel, 0x00FF0000);
			x++;
		}
		y++;
	}
}
