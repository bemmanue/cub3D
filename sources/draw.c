
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
	float	ratio;
	double		p;

	p = (float)y / (float)data->y_ratio;
//	ratio = calculate_ratio(data, x, y);
//	ratio = (float)(WIDTH / MAP_WIDTH) / direct;
//	ratio = (WIDTH / MAP_WIDTH) / (data->pos.x - data->x_pos[x]) / 40.0;
//	width = ((int)x % (int)ratio) / (float)ratio;
//	width = (x % (int)((float)WIDTH / (float)MAP_WIDTH)) / (float)(WIDTH / MAP_WIDTH);
wall = (double)p + (double)((double)data->walls[x]) * (double)((double)data->pos.y - (double)data->y_pos[x]);
	wall -= floor(wall);
	width = (int)(wall * (double)64.0);
//	width = 64.0 - width - 1.0;
	return (width);
}

unsigned int	*define_color(t_data *data, int x, int y, int wall_height, int up, t_image *img)
{
	unsigned int	*color;
	float			width;
	int				pos_x;
	int				pos_y;

	width = find_width(data, x, y, wall_height);
	y = y - up;
	pos_x = (float)width * (float)data->texture->width;
	pos_y = ((float)y / (float) wall_height) *
			(float) data->texture->height;
	color = (unsigned int *) (data->texture->image->addr
		  + (pos_y * data->texture->image->len +
		  pos_x * (data->texture->image->bpp / 8)));
	return (color);
}

void	print_line(t_image *img, t_data *data, int x)
{
	int				y;
	float			wall_height;
	int				up;
	int				down;
	unsigned int	*color;

	wall_height = ((float)HEIGHT / (float)data->walls[x]) * (float)40.0;
	up = (float)((float)HEIGHT - (float)wall_height) / (float)2.0;
	down = (float)((float)HEIGHT + (float)wall_height) / (float)2.0;
	y = 0;
	while (y < HEIGHT)
	{
		if (y <= up)
			my_mlx_pixel_put(img, x, y, 0x0099CCDD);
		else if (y < down)
		{
			color = define_color(data, x, y, wall_height, up, img);
			my_mlx_pixel_put(img, x, y, *color);
		}
		else
			my_mlx_pixel_put(img, x, y, 0x0055AA88);
		y++;
	}
}

void	draw_walls(t_image *img, t_data *data)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		print_line(img, data, x);
		x++;
	}
}

void	draw_map(t_image *img, t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < HEIGHT)
		{
			if (is_wall(data, x, y))
				my_mlx_pixel_put(img, x, y, 0x00000099);
			x++;
		}
		y++;
	}
}
