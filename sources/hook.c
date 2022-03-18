
#include "../cub.h"

void	shift_position(int keycode, t_data *data)
{
	double	new_x;
	double	new_y;
	double	angle;
	double 	distance;

	distance = 0.2;
	if (keycode == ARROW_UP)
		angle = 0.0;
	else if (keycode == ARROW_DOWN)
		angle = 180.0;
	else if (keycode == ARROW_LEFT)
		angle = -90.0;
	else if (keycode == ARROW_RIGHT)
		angle = 90.0;
	new_x = data->posx + (distance * (sin((data->angle + angle) * M_PI / 180.0)));
	new_y = data->posy - (distance * (cos((data->angle + angle) * M_PI / 180.0)));
	if (!is_wall(new_x, new_y))
	{
		data->posx = new_x;
		data->posy = new_y;
	}
}

int		key_hook(int keycode, t_data *data)
{
	if (keycode == ARROW_UP || keycode == ARROW_DOWN
		|| keycode == ARROW_RIGHT || keycode == ARROW_LEFT)
		shift_position(keycode, data);
	else if (keycode == KEY_RIGHT)
		data->angle += 3.0;
	else if (keycode == KEY_LEFT)
		data->angle -= 3.0;
	else if (keycode == ESCAPE)
		exit (0);
	return (0);
}