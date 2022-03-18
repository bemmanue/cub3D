
#include "../cub.h"

t_texture	*init_texture(t_data *data, char *relative_path)
{
	t_texture	*texture;

	texture = malloc(sizeof(t_texture));
	if (!texture)
		return (NULL);
	texture->image = malloc(sizeof(t_image));
	if (!texture->image)
		return (NULL);
	texture->image->img = mlx_xpm_file_to_image
		(data->mlx, relative_path, &texture->width, &texture->height);
	texture->image->addr = mlx_get_data_addr
		(texture->image->img, &texture->image->bpp, &texture->image->len, &texture->image->end);
	return (texture);
}

void	init_data(t_data *data)
{
	data->x_ratio = (double)SCREEN_WIDTH / (double)MAP_WIDTH;
	data->y_ratio = (double)SCREEN_HEIGHT / (double)MAP_HEIGHT;
	data->north = init_texture(data, "./textures/blue.xpm");
	data->south = init_texture(data, "./textures/brick.xpm");
	data->east = init_texture(data, "./textures/wood.xpm");
	data->west = init_texture(data, "./textures/grey.xpm");
	data->floor = 0x0088BB66;
	data->ceiling = 0x0099CCDD;
	data->posx = 5.0;
	data->posy = 5.0;
	data->angle = 0.0;
}
