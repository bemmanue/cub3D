/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:25:19 by bemmanue          #+#    #+#             */
/*   Updated: 2022/03/29 13:25:20 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	texture_x_position(t_texture *texture, t_ray ray)
{
	double	i;
	int		position;

	i = 1.0;
	position = 0;
	if (ray.wall_direct == 'n' || ray.wall_direct == 's')
	{
		while (i <= texture->height)
		{
			if (ray.wall_xpos <= (int)ray.wall_xpos + (i / texture->height))
				position++;
			i += 1.0;
		}
	}
	else if (ray.wall_direct == 'e' || ray.wall_direct == 'w')
	{
		while (i <= texture->width)
			if (ray.wall_ypos <= (int)ray.wall_ypos + (i++ / texture->width))
				position++;
	}
	if (ray.wall_direct == 'e' || ray.wall_direct == 'w')
		position = texture->width - position + 1;
	return (position);
}

int	texture_y_position(t_texture *texture, t_ray ray, int y)
{
	int		position;

	y = (double)y - ray.wall_top;
	position = y / ray.wall_height * (double)texture->height;
	return (position);
}

unsigned int	define_color(t_data *data, int x, int y)
{
	t_texture		*texture;
	int				text_x;
	int				text_y;
	unsigned int	color;

	if (data->ray[x].wall_direct == 'n')
		texture = &data->north;
	else if (data->ray[x].wall_direct == 'e')
		texture = &data->east;
	else if (data->ray[x].wall_direct == 's')
		texture = &data->south;
	else
		texture = &data->west;
	text_x = texture_x_position(texture, data->ray[x]) - 1;
	text_y = texture_y_position(texture, data->ray[x], y);
	color = *(uint32_t *)(texture->image->addr
			+ (text_y * texture->image->len + text_x
				* (texture->image->bpp / 8)));
	return (color);
}

void	print_line(t_data *data, int x)
{
	unsigned int	color;
	t_ray			ray;
	int				y;

	ray = data->ray[x];
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		if (y <= ray.wall_top)
			color = data->ceiling;
		else if (y >= ray.wall_bottom)
			color = data->floor;
		else
			color = define_color(data, x, y);
		my_mlx_pixel_put(&data->image, x, y, color);
		y++;
	}
}

void	draw_walls(t_data *data)
{
	int	x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		print_line(data, x);
		x++;
	}
}
