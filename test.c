
#include "cub.h"

void	my_mlx_pix_put(t_image *image, int x, int y, unsigned int color)
{
	char	*dst;

	dst = image->addr + (y * image->len + x * (image->bpp / 8));
	*(unsigned int*)dst = color;
}

unsigned int	*define_color(t_image *buf, int w, int h, int x, int y)
{
	unsigned int	*color;
	int				pos_x;
	int				pos_y;

	pos_x = ((float)x / (float)WIDTH) * (float)w;
	pos_y = ((float)y / (float)HEIGHT) * (float)h;
	color = (unsigned int *)(buf->addr + (pos_y * buf->len + pos_x * (buf->bpp / 8)));
	return (color);
}

void	draw_imag(t_image *img, t_data *data, t_image *buf, int w, int h)
{
	int				x;
	int 			y;
	unsigned int	*color;

	color = define_color(buf, w, h, 50, 50);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = define_color(buf, w, h, x, y);
//			color = (unsigned int *)(buf->addr + (y * buf->len + x * (buf->bpp / 8)));
			my_mlx_pix_put(img, x, y, *color);
			x++;
		}
		y++;
	}

}

int	render_next_frame(t_data *data)
{
	t_image	img;
	t_image	buf;
	char	*relative_path = "./textures/brick.xpm";
	int		img_width;
	int		img_height;

	buf.img = mlx_xpm_file_to_image(data->mlx.mlx, relative_path, &img_width, &img_height);
	if (img_width >= WIDTH || img_height >= HEIGHT)
		return (-1);
	buf.addr = mlx_get_data_addr(buf.img, &buf.bpp, &buf.len, &buf.end);
	img.img = mlx_new_image(data->mlx.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.len, &img.end);
	draw_imag(&img, data, &buf, img_width, img_height);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, img.img, 0, 0);
	return (0);
}

int main(void)
{
	t_data	data;

	data.mlx.mlx = mlx_init();
	data.mlx.mlx_win = mlx_new_window(data.mlx.mlx, WIDTH, HEIGHT, "test");
	mlx_loop_hook(data.mlx.mlx, render_next_frame, &data);
	mlx_loop(data.mlx.mlx);
	return (0);
}