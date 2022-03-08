
#include "../cub.h"

int	is_textstart(int x, t_data *data)
{
	double	i;
	int		count;

	i = 1.0;
	count = 0;
	if (data->direct[x] == 'n' || data->direct[x] == 's')
	{
		while (i <= 64)
		{
			if (data->block_xpos[x] <= (int)data->block_xpos[x] + (i / 64.0)
			&& data->block_xpos[x] > (int)data->block_xpos[x])
				count++;
			i += 1.0;
		}
	}
	else if (data->direct[x] == 'w' || data->direct[x] == 'e')
	{
		while (i <= 64)
		{
			if (data->block_ypos[x] <= (int)data->block_ypos[x] + (i / 64.0)
			&& data->block_ypos[x] > (int)data->block_ypos[x])
				count++;
			i += 1.0;
		}
	}
	if (data->direct[x] == 's' || data->direct[x] == 'w')
		count = data->texture->width - count + 1;
	return (count);
}


unsigned int	*define_color(t_data *data, int x, int y, int wall_height, int up)
{
	unsigned int	*color;
	int				text_x;
	int				text_y;
	int				new_y;
	int				count;

	count = is_textstart(x, data);
	new_y = y - up;
	text_x = count - 1;
	text_y = ((double)new_y / (double) wall_height) *
			(double) data->texture->height - 1;
	color = (unsigned int *) (data->texture->image->addr
			+ (text_y * data->texture->image->len +
			text_x * (data->texture->image->bpp / 8)));
	return (color);
}

void	print_line(t_data *data, int x)
{
	int				y;
	double			wall_height;
	double			up;
	double			down;
	unsigned int	*color;

	wall_height = ((double)HEIGHT / (data->walls[x]));
	up = ((double)HEIGHT - wall_height) / 2.0;
	down = ((double)HEIGHT + wall_height) / 2.0;
	y = 0;
	while (y < HEIGHT)
	{
		if (y <= up)
			my_mlx_pixel_put(&data->image, x, y, 0x0099CCDD);
		else if (y < down)
		{
			color = define_color(data, x, y, wall_height, up);
			my_mlx_pixel_put(&data->image, x, y, *color);
		}
		else
			my_mlx_pixel_put(&data->image, x, y, 0x0088BB66);
		y++;
	}
}

void	draw_walls(t_data *data)
{
	int	x;

	x = 0;
	while (x < WIDTH)
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
	while (y < HEIGHT)
	{
		x = 0;
		while (x < HEIGHT)
		{
			if (is_wall(data, x / data->x_ratio, y / data->y_ratio))
				my_mlx_pixel_put(&data->image, x, y, 0x00000099);
			x++;
		}
		y++;
	}
}
