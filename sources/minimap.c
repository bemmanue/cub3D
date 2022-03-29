#include "cub.h"

static double	calculate_x_pos(t_data *data)
{
	double	shift;

	shift = 0.0;
	if (data->x_pos > 5.0)
	{
		if (data->map_width - data->x_pos > 5.0)
			shift = data->x_pos - 5.0;
		else
			shift = data->map_width - 10.0;
	}
	return (shift);
}

static double	calculate_y_pos(t_data *data)
{
	double	shift;
	(void)data;

	shift = 0.0;
	if (data->y_pos > 5.0)
	{
		if (data->map_height - data->y_pos > 5.0)
			shift = data->y_pos - 5.0;
		else
			shift = data->map_height - 10.0;
	}
	return (shift);
}

static void	draw_pos(t_data *data, double x_shift, double y_shift)
{
	t_minimap	*minimap;
	int 		x_pixel;
	int 		y_pixel;
	int 		i;
	int			j;

	minimap = &data->minimap;
	x_pixel = (int)((data->x_pos - x_shift) * minimap->ratio + minimap->x_shift);
	y_pixel = (int)((data->y_pos - y_shift) * minimap->ratio + minimap->y_shift);
	i = -3;
	while (i <= 3)
	{
		j = -3;
		while (j <= 3)
		{
			my_mlx_pixel_put(&data->image, x_pixel + i, y_pixel + j, 0x00FF0000);
			j++;
		}
		i++;
	}
}

static void	draw_map(t_data *data, double x_shift, double y_shift)
{
	t_minimap	*minimap;
	int			x_pixel;
	int			y_pixel;
	int			x;
	int			y;

	minimap = &data->minimap;
	y = 0;
	while (y < minimap->y_len)
	{
		x = 0;
		while (x < minimap->x_len)
		{
			x_pixel = x + minimap->x_shift;
			y_pixel = y + minimap->y_shift;
			if (is_wall(data, x / minimap->ratio + x_shift, y / minimap->ratio + y_shift))
				my_mlx_pixel_put(&data->image, x_pixel, y_pixel, 0x00000000);
			else
				my_mlx_pixel_put(&data->image, x_pixel, y_pixel, 0x00CCCCCC);
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_data *data)
{
	double		x_shift;
	double		y_shift;

	if (data->map_width > 10.0)
		x_shift = calculate_x_pos(data);
	else
		x_shift = 0;
	if (data->map_height > 10.0)
		y_shift = calculate_y_pos(data);
	else
		y_shift = 0;
	draw_map(data, x_shift, y_shift);
	draw_pos(data, x_shift, y_shift);
}
