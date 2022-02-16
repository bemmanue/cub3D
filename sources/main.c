
#include "../cub.h"

static int ang;

int	map[10][10] =
					{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
					 {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
					 {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
					 {1, 0, 1, 1, 0, 0, 1, 1, 1, 1},
					 {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
					 {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
					 {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
					 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
					 {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
					 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

int	is_wall(int x, int y)
{
	int	map_pos_x;
	int	map_pos_y;
	int	x_ratio;
	int	y_ratio;

	x_ratio = WIDTH / MAP_WIDTH;
	y_ratio = HEIGHT / MAP_HEIGHT;
	map_pos_x = x / x_ratio;
	map_pos_y = y / y_ratio;
	if (map[map_pos_y][map_pos_x] == 1)
		return (1);
	else
		return (0);
}

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->len + x * (image->bpp / 8));
	*(unsigned int*)dst = color;
}

int	is_walls(int x, int y, t_data *data)
{
	int	degree;
	int	height;
	int middle;
	int wall_up;
	int wall_down;

	middle = HEIGHT / 2;
	degree = (float)x / (float)((float)WIDTH / (float)RANGE);
	if (degree < RANGE)
		height = HEIGHT - data->walls[degree];
	wall_up = middle - (height / 2);
	wall_down = middle + (height / 2);
	if (y > wall_up && y < wall_down)
		return (1);
	return (0);
}

void	draw_walls(t_image *img, t_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (is_walls(x, y, data))
				my_mlx_pixel_put(img, x, y, 0x0000FF00);
			x++;
		}
		y++;
	}
}

void	cast_ray(t_image *img, t_data *data, float angle, int i)
{
	double	ray_len;
	int		x;
	int		y;

	x = data->pos.x;
	y = data->pos.y;
	ray_len = 0;
	while (!is_wall(x, y))
	{
		x = data->pos.x - (int)(ray_len * sin(angle));
		y = data->pos.y - (int)(ray_len * cos(angle));
		ray_len++;
	}
	if (is_wall(x, y))
	{
//		my_mlx_pixel_put(img, x, y, 0x00FFFF00);
		data->walls[i] = ray_len;
	}
}

void	calculate_rays(t_image *img, t_data *data)
{
	int		angle;
	int		i;

	i = 0;
	angle = data->pos.angle - (RANGE / 2);
	while (angle < 0)
		angle += 360;
	while (angle > 360)
		angle -= 360;
	while (i < RANGE)
	{
		angle++;
		while (angle < 0)
			angle += 360;
		while (angle >= 360)
			angle -= 360;
		cast_ray(img, data, angle * M_PI / 180.0, i);
		i++;
	}
}


void	draw_map(t_image *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < HEIGHT)
		{
			if (is_wall(x, y))
				my_mlx_pixel_put(img, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
}

void	init_pos(t_pos *pos, t_data *data)
{
	pos->x = X_POSITION * data->x_ratio;
	pos->y = Y_POSITION * data->y_ratio;
	pos->angle = 0;
}

void	init_data(t_data *data)
{
	data->x_ratio = WIDTH / MAP_WIDTH;
	data->y_ratio = HEIGHT / MAP_HEIGHT;
	init_pos(&data->pos, data);
}

void	draw_image(t_image *img, t_data *data)
{
//	draw_map(img);
	calculate_rays(img, data);
	draw_walls(img, data);
}

int	render_next_frame(t_data *data)
{
	t_image	img;

	img.img = mlx_new_image(data->mlx.mlx, 400, 400);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.len, &img.end);
	draw_image(&img, data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, img.img, 0, 0);
	return (0);
}

int		key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_RIGHT)
		data->pos.angle++;
	if (keycode == KEY_LEFT)
		data->pos.angle--;
	return (0);
}

int main(void)
{
	t_data	data;

	init_data(&data);
	data.mlx.mlx = mlx_init();
	data.mlx.mlx_win = mlx_new_window(data.mlx.mlx, WIDTH, HEIGHT, "Cub3D");
	mlx_hook(data.mlx.mlx_win, 2, 0, key_hook, &data);
	mlx_loop_hook(data.mlx.mlx, render_next_frame, &data);
	mlx_loop(data.mlx.mlx);
	return (0);
}
