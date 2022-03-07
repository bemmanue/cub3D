
#include "../cub.h"

int	get_end(t_data *data, int x, int y)
{
	int end;
	int i = 0;

	end = x;
	while (data->block_ypos[end] == data->block_ypos[x])
	{
		end++;
	}
	end = data->ang[end];
	return (end);
}

int	get_start(t_data *data, int x, int y)
{
	int start;
	int i = 0;

	start = x;
	while (data->block_ypos[start] == data->block_ypos[x])
	{
		start--;
	}
	start = data->ang[start];
	return (start);
}

float	calculate_ratio(t_data *data, int x, int y)
{
	float	ratio;
	int		start;
	int		end;

	start = get_start(data, x, y);
	end = get_end(data, x, y);
	ratio = end - start;
	if (ratio == 0.0)
		ratio = 5.0;
	return (ratio);
}

float	find_width(t_data *data, int x, int y, int h)
{
	double	width;
	double	wall;

	wall = data->posy +
		(data->walls[x]) * (fabs(data->posy - data->block_ypos[x]));
	wall -= floor(wall);
	width = wall * (double) data->texture->width;
	return (width);
}

unsigned int	*define_color(t_data *data, int x, int y, int wall_height, int up)
{
	unsigned int	*color;
	double			new_x;
	int				text_x;
	int				text_y;
	int				new_y;

	new_x = find_width(data, x, y, wall_height);
	new_y = y - up;
	text_x = new_x - 1;
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

	wall_height = ((double)HEIGHT / (data->walls[x] * 40.0)) * 40.0;
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
//			if (data->direct[x] == 's' || data->direct[x] == 'n')
//				my_mlx_pixel_put(&data->image, x, y, 0x0000AAFF);
//			else
//				my_mlx_pixel_put(&data->image, x, y, 0x00FFAA00);
		}
		else
			my_mlx_pixel_put(&data->image, x, y, 0x0055AA88);
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
