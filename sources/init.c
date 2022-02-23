
#include "includes/cub.h"

void	init_pos(t_pos *pos, t_data *data)
{
	pos->x = X_POSITION * data->x_ratio;
	pos->y = Y_POSITION * data->y_ratio;
	pos->angle = 0;
}

void	init_data(t_data *data)
{
	data->x_ratio = WIDTH / MAP_WIDTH;
	data->y_ratio = HEIGHT / MAP_HEIGHT;
	init_pos(&data->pos, data);
}
