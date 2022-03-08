
#include "../cub.h"

t_texture	*init_texture(t_data *data, char *path)
{
	t_texture	*texture;
	char		*relative_path = path;

	if (!fopen(relative_path, "r"))
		return (NULL);
	texture = malloc(sizeof(t_texture));
	texture->image = malloc(sizeof(t_image));
	texture->image->img = mlx_xpm_file_to_image
		(data->mlx.mlx, relative_path, &texture->width, &texture->height);
	texture->image->addr = mlx_get_data_addr
		(texture->image->img, &texture->image->bpp, &texture->image->len, &texture->image->end);
	return (texture);
}

void	init_data(t_data *data)
{
	data->x_ratio = (float)WIDTH / (float)MAP_WIDTH;
	data->y_ratio = (float)HEIGHT / (float)MAP_HEIGHT;
	data->texture = init_texture(data, "./textures/grey.xpm");
//	data->north = init_texture(data, "");
//	data->south = init_texture(data, "");
//	data->east = init_texture(data, "");
//	data->west = init_texture(data, "");
	data->posx = 5.0;
	data->posy = 5.0;
	data->angle = 0.0;
}
