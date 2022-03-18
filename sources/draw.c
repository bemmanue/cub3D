
#include "../cub.h"

int	texture_x_position(t_data *data, t_texture *texture, int x)
{
	double	i;
	int		position;

	i = 1.0;
	position = 0;
	if (data->direct[x] == 'n' || data->direct[x] == 's')
	{
		while (i <= texture->height)
		{
			if (data->block_xpos[x] <= (int)data->block_xpos[x] + (i / texture->height))
				position++;
			i += 1.0;
		}
	}
	else if (data->direct[x] == 'w' || data->direct[x] == 'e')
	{
		while (i <= texture->width)
		{
			if (data->block_ypos[x] <= (int)data->block_ypos[x] + (i / texture->width))
				position++;
			i += 1.0;
		}
	}
	if (data->direct[x] == 's' || data->direct[x] == 'w')
		position = texture->width - position + 1;
	return (position);
}


unsigned int	*define_color(t_data *data, int x, int y, double wall_height)
{
	unsigned int	*color;
	int				text_x;
	int				text_y;
	t_texture		*texture;

	if (data->direct[x] == 'n')
		texture = data->north;
	else if (data->direct[x] == 's')
		texture = data->south;
	else if (data->direct[x] == 'e')
		texture = data->east;
	else
		texture = data->west;
	text_x = texture_x_position(data, texture, x) - 1;
	text_y = ((double)y / wall_height) * (double)texture->height - 1;
	color = (unsigned int *)(texture->image->addr
		+ (text_y * texture->image->len + text_x * (texture->image->bpp / 8)));
	return (color);
}

void	print_line(t_data *data, int x)
{
	int				y;
	double			wall_height;
	double			wall_top;
	double			wall_bottom;
	unsigned int	*color;

	wall_height = ((double)SCREEN_HEIGHT / (data->ray_len[x]));
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

void	draw_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_HEIGHT)
		{
			if (is_wall(x / data->x_ratio, y / data->y_ratio))
				my_mlx_pixel_put(&data->image, x, y, 0x00000099);
			x++;
		}
		y++;
	}
}
