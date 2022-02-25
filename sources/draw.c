
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

void	draw_walls(t_image *img, t_data *data)
{
	int		x;
	int		y;
	char	color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = is_walls(x, y, data);
			if (color)
			{
				if (color == 'n')
					my_mlx_pixel_put(img, x, y, 0x00009955);
				else if (color == 'e')
					my_mlx_pixel_put(img, x, y, 0x0000AA99);
				else if (color == 's')
					my_mlx_pixel_put(img, x, y, 0x0000CC77);
				else if (color == 'w')
					my_mlx_pixel_put(img, x, y, 0x0055DD00);
				else if (color == 'f')
					my_mlx_pixel_put(img, x, y, 0x0055DD77);
			}
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
