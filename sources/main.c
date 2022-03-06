
#include "../cub.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, unsigned int color)
{
	char	*dst;

	dst = image->addr + (y * image->len + x * (image->bpp / 8));
	*(unsigned int*)dst = color;
}

void	draw_image(t_data *data)
{
//	draw_map(data);
	calculate_rays(data);
	draw_walls(data);
}

int	render_next_frame(t_data *data)
{
	data->image.img = mlx_new_image(data->mlx.mlx, WIDTH, HEIGHT);
	data->image.addr = mlx_get_data_addr(data->image.img, &data->image.bpp, &data->image.len, &data->image.end);
	draw_image(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->image.img, 0, 0);
	return (0);
}

int main(void)
{
	t_data	data;

	data.mlx.mlx = mlx_init();
	init_data(&data);
	data.mlx.mlx_win = mlx_new_window(data.mlx.mlx, WIDTH, HEIGHT, "Cub3D");
	mlx_hook(data.mlx.mlx_win, 2, 0, key_hook, &data);
	mlx_loop_hook(data.mlx.mlx, render_next_frame, &data);
	mlx_loop(data.mlx.mlx);
	return (0);
}
