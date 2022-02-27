
#include "../cub.h"

void	init_pos(t_pos *pos, t_data *data)
{
	pos->x = (float)X_POSITION * (float)data->x_ratio;
	pos->y = (float)Y_POSITION * (float)data->y_ratio;
	pos->angle = 0;
}

t_texture	*init_texture(t_data *data)
{
	t_texture	*texture;
	char		*relative_path = "./textures/blue.xpm";

	if (!fopen(relative_path, "r"))
		return (NULL);
	texture = malloc(sizeof(t_texture));
	texture->image = malloc(sizeof(t_image));
	texture->image->img = mlx_xpm_file_to_image(data->mlx.mlx, relative_path, &texture->width, &texture->height);
	printf("%d\n", texture->width);
	printf("%d\n", texture->height);
	texture->image->addr = mlx_get_data_addr
		(texture->image->img, &texture->image->bpp, &texture->image->len, &texture->image->end);
	return (texture);
}

void	init_data(t_data *data)
{
	data->x_ratio = (float)WIDTH / (float)MAP_WIDTH;
	data->y_ratio = (float)HEIGHT / (float)MAP_HEIGHT;
	data->texture = init_texture(data);
	init_pos(&data->pos, data);
}
