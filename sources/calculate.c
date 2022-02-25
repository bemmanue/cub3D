
#include "../cub.h"

int	is_wall(t_data *data, float x, float y)
{
	int		map_pos_x;
	int		map_pos_y;

	map_pos_x = x / data->x_ratio;
	map_pos_y = y / data->y_ratio;
	if (map[map_pos_y][map_pos_x] == 1)
		return (1);
	else
		return (0);
}

void	define_direct(t_data *data, float x, float y, int i, float angle)
{
	int	wall_pos_x;
	int	wall_pos_y;
	int	next_up;
	int	next_down;
	int	next_right;
	int	next_left;

	wall_pos_x = x / data->x_ratio;
	wall_pos_y = y / data->y_ratio;
	next_up = (y - 0.1) / data->y_ratio;
	next_down = (y + 0.1) / data->y_ratio;
	next_right = (x + 0.1) / data->x_ratio;
	next_left = (x - 0.1) / data->x_ratio;
	if (x < data->pos.x)
	{
		if (y < data->pos.y)
		{
			if (map[next_up][wall_pos_x] && map[next_down][wall_pos_x])
				data->direct[i] = 'w';
			else if (map[wall_pos_y][next_right] == 0)
				data->direct[i] = 'w';
			else
				data->direct[i] = 'n';
		}
		else
		{
			if (map[next_up][wall_pos_x] && map[next_down][wall_pos_x])
				data->direct[i] = 'w';
			else if (map[wall_pos_y][next_right] == 0)
				data->direct[i] = 'w';
			else
				data->direct[i] = 's';
		}
	}
	else
	{
		if (y < data->pos.y)
		{
			if (map[next_up][wall_pos_x] && map[next_down][wall_pos_x])
				data->direct[i] = 'e';
			else if (map[wall_pos_y][next_left] == 0)
				data->direct[i] = 'e';
			else
				data->direct[i] = 'n';
		}
		else
		{
			if (map[next_up][wall_pos_x] && map[next_down][wall_pos_x])
				data->direct[i] = 'e';
			else if (map[wall_pos_y][next_left] == 0)
				data->direct[i] = 'e';
			else
				data->direct[i] = 's';
		}
	}
}

float	calculate_fov(t_data *data, float angle, float ray_len)
{
	float	angle2;
	float	len;

	angle2 = fabs(data->pos.angle - angle);
	len = ray_len * cos(angle2 * M_PI / 180.0);
	return (len);
}

void	cast_ray(t_image *img, t_data *data, float angle, int i)
{
	float	ray_len;
	float	x;
	float	y;

	x = (float)data->pos.x;
	y = (float)data->pos.y;
	ray_len = 0.0;
	while (!is_wall(data, x, y))
	{
		x = (float)data->pos.x - (ray_len * (sin(-angle * M_PI / 180.0)));
		y = (float)data->pos.y - (ray_len * (cos(-angle * M_PI / 180.0)));
		my_mlx_pixel_put(img, x, y, 0x0000FFFF);
		ray_len += 0.0500;
	}
//	my_mlx_pixel_put(img, x, y, 0x0000FFFF);
	data->walls[i] = calculate_fov(data, angle, ray_len);
	define_direct(data, x, y, i, angle);
}

void	calculate_rays(t_image *img, t_data *data)
{
	float	angle;
	float	ratio;
	int		i;

	angle = data->pos.angle - (RANGE / 2);
	ratio = (float)RANGE / (float)WIDTH;
	i = 0;
	while (i < WIDTH)
	{
		angle += (float)ratio;
		cast_ray(img, data, angle, i);
		i++;
	}
}
