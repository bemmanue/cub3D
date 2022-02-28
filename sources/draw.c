
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

float	find_width(t_data *data, float x, float y)
{
	float	width;
	char	direct;


	direct = is_walls(x, y, data);
	if (direct == 'n' || direct == 's')
		width = ((int)x % (int)(HEIGHT / 10.0)) / (float)(HEIGHT / 10.0);
	else
		width = ((int)y % (int)(WIDTH / 10.0)) / (float)(WIDTH / 10.0);
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
