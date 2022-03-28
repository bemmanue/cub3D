
#include "cub.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, unsigned int color)
{
	char	*dst;

	dst = image->addr + (y * image->len + x * (image->bpp / 8));
	*(unsigned int*)dst = color;
}

void	draw_image(t_data *data)
{
	cast_rays(data);
	draw_walls(data);
	draw_minimap(data);
}

int	render_next_frame(t_data *data)
{
	data->image.img = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	data->image.addr = mlx_get_data_addr(data->image.img,
		 &data->image.bpp,&data->image.len, &data->image.end);
	draw_image(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->image.img, 0, 0);
	return (0);
}

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
	data->x_pos = 5.0;
	data->y_pos = 5.0;
	data->angle = 0.0;
	data->x_ratio = (double)SCREEN_WIDTH / data->map_width;
	data->y_ratio = (double)SCREEN_HEIGHT / data->map_height;
	return (data);
}

int main(int argc, char **argv)
{
	t_data	*data;

	data = parser(argc, argv);
	data->mlx = mlx_init();
	init_data(data);
	data->mlx_win = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
	mlx_hook(data->mlx_win, 2, 0, key_hook, data);
	mlx_hook(data->mlx_win, 17, 0, close_hook, NULL);
	mlx_loop_hook(data->mlx, render_next_frame, data);
	mlx_loop(data->mlx);
	return (0);
}
