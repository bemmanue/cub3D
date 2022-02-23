
#include "../cub.h"

void	shift_position(int keycode, t_data *data)
{
	int	x_add;
	int y_add;
	int	new_x;
	int	new_y;
	int c;

	c = 10;
	new_x = data->pos.x;
	new_y = data->pos.y;
	x_add = (double)c * sin((double)((double)data->pos.angle * M_PI / 180.0));
	y_add = (double)c * cos((double)((double)data->pos.angle * M_PI / 180.0));
	if (keycode == ARROW_UP)
	{
		new_x -= x_add;
		new_y -= y_add;
	}
	else if (keycode == ARROW_DOWN)
	{
		new_x += x_add;
		new_y += y_add;
	}
	else if (keycode == ARROW_LEFT)
	{
		x_add = (double)c * sin((double)((double)(data->pos.angle - 90) * M_PI / 180.0));
		y_add = (double)c * cos((double)((double)(data->pos.angle - 90) * M_PI / 180.0));
		new_x -= x_add;
		new_y -= y_add;
	}
	else if (keycode == ARROW_RIGHT)
	{
		x_add = (double)c * sin((double)((double)(data->pos.angle + 90) * M_PI / 180.0));
		y_add = (double)c * cos((double)((double)(data->pos.angle + 90) * M_PI / 180.0));
		new_x -= x_add;
		new_y -= y_add;
	}
	if (!is_wall(new_x, new_y))
	{
		data->pos.x = new_x;
		data->pos.y = new_y;
	}
}

int		key_hook(int keycode, t_data *data)
{
	if (keycode == ARROW_RIGHT)
		shift_position(keycode, data);
	else if (keycode == ARROW_LEFT)
		shift_position(keycode, data);
	else if (keycode == ARROW_UP)
		shift_position(keycode, data);
	else if (keycode == ARROW_DOWN)
		shift_position(keycode, data);
	else if (keycode == KEY_RIGHT)
		data->pos.angle += 5;
	else if (keycode == KEY_LEFT)
		data->pos.angle -= 5;
	return (0);
}