
#include "../cub.h"

char	is_walls(int x, int y, t_data *data)
{
	float	height;
	float	middle;
	float	wall_up;
	float	wall_down;

	middle = (float)HEIGHT / 2.0;
	height = ((float)HEIGHT / data->walls[x]) * 20.0;
	wall_up = middle - (height / 2.0);
	wall_down = middle + (height / 2.0);
	if (y >= wall_up && y <= wall_down)
		return (data->direct[x]);
//	else if (y > wall_down)
//		return ('f');
	return (0);
}

int	get_end(t_data *data, int x, int y)
{
	int end;

	end = x;
	while (data->block_ypos[end] == data->block_ypos[x])
	{
		end++;
	}
//	end = data->x_pos[end];
	return (end);
}

int	get_start(t_data *data, int x, int y)
{
	int start;

	start = x;
	while (data->block_ypos[start] == data->block_ypos[x])
	{
		start--;
	}
//	start = data->x_pos[start];
	return (start);
}

float	calculate_ratio(t_data *data, int x, int y)
{
	float	ratio;
	int		start;
	int		end;

	start = get_start(data, x, y);
//	printf("start = %d\n", start);
	end = get_end(data, x, y);
//	printf("end = %d\n", end);
	ratio = end - start;
	if (ratio == 0.0)
		ratio = 5.0;
	return (ratio);
}

float	find_width(t_data *data, int x, int y)
{
	float	width;
	char	direct;
	float	ratio;

	ratio = calculate_ratio(data, x, y);
	direct = is_walls(x, y, data);
	if (direct == 'n' || direct == 's')
		width = ((int)x % (int)ratio) / ratio;
	else
		width = ((int)y % (int)ratio) / ratio;
//	if (direct == 'n' || direct == 's')
//		width = ((int)x % (int)(HEIGHT / 10.0)) / (float)(HEIGHT / 10.0);
//	else
//		width = ((int)y % (int)(WIDTH / 10.0)) / (float)(WIDTH / 10.0);
	return (width);
}

unsigned int	*define_color(t_data *data, float x, float y)
{
	unsigned int	*color;
	float			height;
	float			width;
	float			middle;
	float			wall_up;
	float			wall_down;
	int				pos_x;
	int				pos_y;

	width = find_width(data, x, y);
	middle = (float)HEIGHT / 2.0;
	height = ((float)HEIGHT / data->walls[(int)x]) * 20.0;
	wall_up = middle - (height / 2.0);
	wall_down = middle + (height / 2.0);
	y = ((float)y - (float)wall_up);

	pos_x = (float)width * (float)data->texture->width;
	pos_y = ((float)y / (float)height) * (float)data->texture->height;
	color = (unsigned int *)(data->texture->image->addr
		+ (pos_y * data->texture->image->len + pos_x * (data->texture->image->bpp / 8)));
	return (color);
}

void	draw_walls(t_image *img, t_data *data)
{
	int				x;
	int				y;
	unsigned int	*color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (is_walls(x, y, data))
			{
				color = define_color(data, x, y);
				my_mlx_pixel_put(img, x, y, *color);
			}
			else
				my_mlx_pixel_put(img, x, y, 0x000066FF);
			x++;
		}
		y++;
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
