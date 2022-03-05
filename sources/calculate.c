
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

char	define_direct(t_data *data, float x, float y)
{
	int		pos_x;
	int		pos_y;
	int		next_up;
	int		next_down;
	int		next_right;
	int		next_left;
	char	direct;

	pos_x = x / data->x_ratio;
	pos_y = y / data->y_ratio;
	next_up = (y - 0.1) / data->y_ratio;
	next_down = (y + 0.1) / data->y_ratio;
	next_right = (x + 0.1) / data->x_ratio;
	next_left = (x - 0.1) / data->x_ratio;
	if (x < data->pos.x)
	{
		if (map[next_up][pos_x] && map[next_down][pos_x])
			direct = 'w';
		else if (map[pos_y][next_right] == 0)
			direct = 'w';
		else
		{
			if (y < data->pos.y)
				direct = 'n';
			else
				direct = 's';
		}
	}
	else
	{
		if (map[next_up][pos_x] && map[next_down][pos_x])
			direct = 'e';
		else if (map[pos_y][next_left] == 0)
			direct = 'e';
		else
		{
			if (y < data->pos.y)
				direct = 'n';
			else
				direct = 's';
		}
	}
	return (direct);
}

float	calculate_fov(t_data *data, float angle, float ray_len)
{
	float	angle2;
	float	len;

	angle2 = fabs(data->pos.angle - angle);
	len = ray_len * cos(angle2 * M_PI / 180.0);
//	len = ray_len;
	return (len);
}

int	define_blockxpos(t_data *data, float x)
{
	int		pos;

	pos = (int)((float)x / data->x_ratio);
	return (pos);
}

int	define_blockypos(t_data *data, float y)
{
	int		pos;

	pos = (int)((float)y / data->y_ratio);
	return (pos);
}

int	is_perpwall(t_data *data, int x, int y, int i)
{
	int		map_pos_x;
	int		map_pos_y;
	int		player_pos_x;
	int		player_pos_y;

	if (data->perpwalldist[i] != 0)
		return (0);
	map_pos_x = (float)x / (float)data->x_ratio;
	map_pos_y = (float)y / (float)data->y_ratio;
	player_pos_x = (float)data->pos.x / (float)data->x_ratio;
	player_pos_y = (float)data->pos.x / (float)data->y_ratio;
	if (map_pos_x - 1 == player_pos_x || map_pos_x + 1 == player_pos_x)
	{
		if (map_pos_y - 1 == player_pos_y
			|| map_pos_y + 1 == player_pos_y)
			return (1);
	}
	if (map_pos_y - 1 == player_pos_y || map_pos_y + 1 == player_pos_y)
	{
		if (map_pos_x - 1 == player_pos_x
			|| map_pos_x + 1 == player_pos_x)
			return (1);
	}
	return (0);
}

int	is_perpwall2(t_data *data, int x, int y, int i)
{
	int		map_pos_x;
	int		map_pos_y;
	int		player_pos_x;
	int		player_pos_y;

	if (data->perpwalldist2[i] != 0)
		return (0);
	map_pos_x = (float)x / (float)data->x_ratio;
	map_pos_y = (float)y / (float)data->y_ratio;
	player_pos_x = (float)data->pos.x / (float)data->x_ratio;
	player_pos_y = (float)data->pos.x / (float)data->y_ratio;
	if (map_pos_x - 2 == player_pos_x || map_pos_x + 2 == player_pos_x)
	{
		if (map_pos_y - 1 == player_pos_y
			|| map_pos_y + 1 == player_pos_y)
			return (1);
	}
	if (map_pos_y - 2 == player_pos_y || map_pos_y + 2 == player_pos_y)
	{
		if (map_pos_x - 1 == player_pos_x
			|| map_pos_x + 1 == player_pos_x)
			return (1);
	}
	return (0);
}

void	cast_ray(t_image *img, t_data *data, float angle, int i)
{
	float	ray_len;
	float	x;
	float	y;

	x = (float)data->pos.x;
	y = (float)data->pos.y;
	ray_len = 0.0;
	data->perpwalldist[i] = 0;
	while (!is_wall(data, x, y))
	{
		if (is_perpwall(data, x, y, i))
			data->perpwalldist[i] = ray_len;
		if (is_perpwall2(data, x, y, i))
			data->perpwalldist2[i] = ray_len;
		x = (float)data->pos.x + (ray_len * (sin(angle * M_PI / 180.0)));
		y = (float)data->pos.y - (ray_len * (cos(angle * M_PI / 180.0)));
//		my_mlx_pixel_put(img, x, y, 0x0000FFFF);
		ray_len += 0.05;
	}
//	my_mlx_pixel_put(img, x, y, 0x0000FFFF);
	data->walls[i] = calculate_fov(data, angle, ray_len);
	data->direct[i] = define_direct(data, x, y);
	data->block_xpos[i] = define_blockxpos(data, x);
	data->block_ypos[i] = define_blockypos(data, y);
	data->x_pos[i] = (int)x;
	data->y_pos[i] = (int)y;
	data->ang[i] = angle;
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
		cast_ray(img, data, angle, i);
		angle += ratio;
		i++;
	}
}
