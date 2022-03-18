
#include "../cub.h"

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
	else if (ray.wall_direct == 'w' || ray.wall_direct == 'e')
	{
		while (i <= texture->width)
		{
			if (ray.wall_ypos <= (int)ray.wall_ypos + (i / texture->width))
				position++;
			i += 1.0;
		}
	}
	if (ray.wall_direct == 's' || ray.wall_direct == 'w')
		position = texture->width - position + 1;
	return (position);
}


unsigned int	*define_color(t_data *data, int x, int y, double wall_height)
{
	unsigned int	*color;
	int				text_x;
	int				text_y;
	t_texture		*texture;

	if (data->ray[x].wall_direct == 'n')
		texture = &data->north;
	else if (data->ray[x].wall_direct == 's')
		texture = &data->south;
	else if (data->ray[x].wall_direct == 'e')
		texture = &data->east;
	else
		texture = &data->west;
	text_x = texture_x_position(texture, data->ray[x]) - 1;
	text_y = ((double)y / wall_height) * (double)texture->height - 1;
	color = (unsigned int *)(texture->image->addr
		+ (text_y * texture->image->len + text_x * (texture->image->bpp / 8)));
	return (color);
}

void	print_line(t_data *data, int x)
{
	double			wall_height;
	double			wall_top;
	double			wall_bottom;
	unsigned int	*color;
	int				y;

	wall_height = ((double)SCREEN_HEIGHT / (data->ray[x].ray_len));
	wall_top = ((double)SCREEN_HEIGHT - wall_height) / 2.0;
	wall_bottom = ((double)SCREEN_HEIGHT + wall_height) / 2.0;
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		if (y <= wall_top)
			my_mlx_pixel_put(&data->image, x, y, data->ceiling);
		else if (y < wall_bottom)
		{
			color = define_color(data, x, y - wall_top, wall_height);
			my_mlx_pixel_put(&data->image, x, y, *color);
		}
		else
			my_mlx_pixel_put(&data->image, x, y, data->floor);
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
