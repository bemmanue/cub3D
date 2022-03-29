#include "cub.h"

void	init_texture(t_data *data, t_texture *texture)
{
	texture->image = malloc(sizeof(t_image));
	if (!texture->image)
		exit_error("Memory error\n");
	texture->image->img = mlx_xpm_file_to_image
		(data->mlx, texture->path, &texture->width, &texture->height);
	if (!texture->image->img)
		exit_error("Memory error\n");
	texture->image->addr = mlx_get_data_addr(texture->image->img,
			&texture->image->bpp,
			&texture->image->len, &texture->image->end);
}

void	init_minimap(t_data *data)
{
	t_minimap	*minimap;
	int 		max_map_size;

	minimap = &data->minimap;
	max_map_size = MINIMAP_SIZE;
	minimap->ratio = max_map_size / 10.0;
	if (data->map_width >= 10)
		minimap->x_len = max_map_size;
	else
		minimap->x_len = (int)(data->map_width * minimap->ratio);
	if (data->map_height >= 10)
		minimap->y_len = max_map_size;
	else
		minimap->y_len = (int)(data->map_height * minimap->ratio);
	minimap->x_shift = 10;
	minimap->y_shift = SCREEN_HEIGHT - minimap->y_len - 10;
	minimap->is_open = 0;
}

void	init_data(t_data *data)
{
	init_texture(data, &data->north);
	init_texture(data, &data->east);
	init_texture(data, &data->south);
	init_texture(data, &data->west);
	init_minimap(data);
}
