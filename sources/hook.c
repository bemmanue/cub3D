
#include "../cub.h"

void	shift_position(int keycode, t_data *data)
{
	int		new_x;
	int		new_y;
	float	angle;
	float 	distance;

	distance = 10.0;
	if (keycode == ARROW_UP)
		angle = 0.0;
	else if (keycode == ARROW_DOWN)
		angle = 180.0;
	else if (keycode == ARROW_LEFT)
		angle = -90.0;
	else if (keycode == ARROW_RIGHT)
		angle = 90.0;
	new_x = data->pos.x + (distance * (sin((data->pos.angle + angle) * M_PI / 180.0)));
	new_y = data->pos.y - (distance * (cos((data->pos.angle + angle) * M_PI / 180.0)));
	if (!is_wall(data, new_x, new_y))
	{
		data->pos.x = new_x;
		data->pos.y = new_y;
	}
}

int		key_hook(int keycode, t_data *data)
{
	if (keycode == ARROW_UP || keycode == ARROW_DOWN
		|| keycode == ARROW_RIGHT || keycode == ARROW_LEFT)
		shift_position(keycode, data);
	else if (keycode == KEY_RIGHT)
		data->pos.angle += 3.0;
	else if (keycode == KEY_LEFT)
		data->pos.angle -= 3.0;
	return (0);
}