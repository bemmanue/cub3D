
#include "../cub.h"

int	is_wall(int x, int y)
{
	int		map_pos_x;
	int		map_pos_y;
	float	x_ratio;
	float	y_ratio;

	x_ratio = (float)((float)WIDTH / (float)MAP_WIDTH);
	y_ratio = (float)((float)HEIGHT / (float)MAP_HEIGHT);
	map_pos_x = (float)((float)x / (float)x_ratio);
	map_pos_y = (float)((float)y / (float)y_ratio);
	if (map[map_pos_y][map_pos_x] == 1)
		return (1);
	else
		return (0);
}

void	define_direct(t_data *data, int x, int y, int i, int angle)
{
	int	wall_pos_x;
	int	wall_pos_y;
	int	next_up;
	int	next_down;
	int	next_right;
	int	next_left;

	wall_pos_x = (float)x / (float)((float)WIDTH / (float)MAP_WIDTH);
	wall_pos_y = (float)y / (float)((float)HEIGHT / (float)MAP_HEIGHT);
	next_up = (float)(y - 1) / (float)((float)HEIGHT / (float)MAP_HEIGHT);
	next_down = (float)(y + 1) / (float)((float)HEIGHT / (float)MAP_HEIGHT);
	next_right = (float)(x + 1) / (float)((float)WIDTH / (float)MAP_WIDTH);
	next_left = (float)(x - 1) / (float)((float)WIDTH / (float)MAP_WIDTH);
	if (x < data->pos.x)
	{
		if (y < data->pos.y)
		{
			if (!map[next_up][wall_pos_x] || !map[next_down][wall_pos_x])
			{
//				if ((!map[wall_pos_y][next_left] || !map[wall_pos_y][next_right]))
//					data->direct[i] = 'w';
//				else
					data->direct[i] = 'n';
			}
			else
				data->direct[i] = 'w';
		}
		else
		{
			if (!map[next_up][wall_pos_x] || !map[next_down][wall_pos_x])
			{
//				if ((!map[wall_pos_y][next_left] || !map[wall_pos_y][next_right]))
//					data->direct[i] = 'w';
//				else
					data->direct[i] = 's';
			}
			else
				data->direct[i] = 'w';
		}
	}
	else
	{
		if (y <= data->pos.y)
		{
			if (!map[next_up][wall_pos_x] || !map[next_down][wall_pos_x])
			{
//				if ((!map[wall_pos_y][next_left] || !map[wall_pos_y][next_right]))
//					data->direct[i] = 'e';
//				else
					data->direct[i] = 'n';
			}
			else
				data->direct[i] = 'e';
		}
		else
		{
			if (!map[next_up][wall_pos_x] || !map[next_down][wall_pos_x])
			{
//				if ((!map[wall_pos_y][next_left] || !map[wall_pos_y][next_right]))
//					data->direct[i] = 'e';
//				else
					data->direct[i] = 's';
			}
			else
				data->direct[i] = 'e';
		}
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
		data->walls[i] = ray_len;
		define_direct(data, x, y, i, angle);
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
