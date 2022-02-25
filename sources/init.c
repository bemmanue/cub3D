
#include "../cub.h"

void	init_pos(t_pos *pos, t_data *data)
{
	pos->x = (float)X_POSITION * (float)data->x_ratio;
	pos->y = (float)Y_POSITION * (float)data->y_ratio;
	pos->angle = 0;
}

void	init_data(t_data *data)
{
	data->x_ratio = (float)WIDTH / (float)MAP_WIDTH;
	data->y_ratio = (float)HEIGHT / (float)MAP_HEIGHT;
	init_pos(&data->pos, data);
}
