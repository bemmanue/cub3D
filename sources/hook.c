
#include "includes/cub.h"

int		key_hook(int keycode, t_data *data)
{
	if (keycode == ARROW_RIGHT)
	{
		if (!is_wall(data->pos.x - 10, data->pos.y))
			data->pos.x -= 10;
	}
	else if (keycode == ARROW_LEFT)
	{
		if (!is_wall(data->pos.x + 10, data->pos.y))
			data->pos.x += 10;
	}
	else if (keycode == ARROW_UP)
	{
		if (!is_wall(data->pos.x, data->pos.y - 10))
			data->pos.y -= 10;
	}
	else if (keycode == ARROW_DOWN)
	{
		if (!is_wall(data->pos.x, data->pos.y + 10))
			data->pos.y += 10;
	}
	else if (keycode == KEY_RIGHT)
		data->pos.angle += 5;
	else if (keycode == KEY_LEFT)
		data->pos.angle -= 5;
	return (0);
}