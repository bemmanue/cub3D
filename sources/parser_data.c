#include "cub.h"

t_data	*parser_data(char *path)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		exit_error("Memory error\n");
	data->north.path = ft_strdup("./textures/grey.xpm");
	data->east.path = ft_strdup("./textures/blue.xpm");
	data->south.path = ft_strdup("./textures/grey.xpm");
	data->west.path = ft_strdup("./textures/blue.xpm");
	data->map_width = 10.0;
	data->map_height = 7.0;
	data->floor = 0x0088BB66;
	data->ceiling = 0x0099CCDD;
	data->xpos = 5.0;
	data->ypos = 5.0;
	data->angle = 0.0;
	data->x_ratio = (double)SCREEN_WIDTH / data->map_width;
	data->y_ratio = (double)SCREEN_HEIGHT / data->map_height;
	return (data);
}
