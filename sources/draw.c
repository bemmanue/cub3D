
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
	else if (y > wall_down)
		return ('f');
	return (0);
}

unsigned int	*define_color(t_data *data, int x, int y)
{
	unsigned int	*color;


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
			color = define_color(data, x, y);
			my_mlx_pixel_put(img, x, y, *color);
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
