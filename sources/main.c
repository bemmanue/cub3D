
#include "../cub.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, unsigned int color)
{
	char	*dst;

	dst = image->addr + (y * image->len + x * (image->bpp / 8));
	*(unsigned int*)dst = color;
}

void	draw_image(t_image *img, t_data *data)
{
//	my_mlx_pixel_put(img, data->pos.x, data->pos.y, 0x0000FFFF);
	draw_map(img, data);
	calculate_rays(img, data);
	draw_walls(img, data);
}

int	render_next_frame(t_data *data)
{
	t_image	img;

	img.img = mlx_new_image(data->mlx.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.len, &img.end);
	draw_image(&img, data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, img.img, 0, 0);
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
