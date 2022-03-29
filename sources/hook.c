#include "cub.h"

void	shift_position(int keycode, t_data *data)
{
	double	new_x;
	double	new_y;
	double	angle;
	double	distance;

	distance = 0.3;
	angle = 0.0;
	if (keycode == KEY_W)
		angle = 0.0;
	else if (keycode == KEY_S)
		angle = 180.0;
	else if (keycode == KEY_A)
		angle = -90.0;
	else if (keycode == KEY_D)
		angle = 90.0;
	new_x = data->x_pos + (distance * (sin((data->angle + angle)
					* M_PI / 180.0)));
	new_y = data->y_pos - (distance * (cos((data->angle + angle)
					* M_PI / 180.0)));
	if (!is_wall(data, new_x, new_y))
	{
		data->x_pos = new_x;
		data->y_pos = new_y;
	}
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_A || keycode == KEY_D
		|| keycode == KEY_S || keycode == KEY_W)
		shift_position(keycode, data);
	else if (keycode == ARROW_RIGHT)
		data->angle += 6.0;
	else if (keycode == ARROW_LEFT)
		data->angle -= 6.0;
	else if (keycode == KEY_M)
	{
		if (!data->minimap.is_open)
			data->minimap.is_open = 1;
		else
			data->minimap.is_open = 0;
	}
	else if (keycode == ESCAPE)
		exit (0);
	return (0);
}

int	close_hook(void)
{
	exit(0);
}
