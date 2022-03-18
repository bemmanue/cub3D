
#include "../cub.h"

char	define_direct(t_data *data, double x, double y)
{
	double	next_up;
	double	next_down;
	char	direct;

	next_up = y - (1.0 / data->y_ratio);
	next_down = y + (1.0 / data->y_ratio);
	if (x < data->posx)
	{
		if (map[(int)next_up][(int)x] && map[(int)next_down][(int)x])
			direct = 'w';
		else
		{
			if (y < data->posy && (y - (int)y) > 0.99)
				direct = 'n';
			else if (y > data->posy && (y - (int)y) < 0.01)
				direct = 's';
			else
				direct = 'w';
		}
	}
	else
	{
		if (map[(int)next_up][(int)x] && map[(int)next_down][(int)x])
			direct = 'e';
		else
		{
			if (y < data->posy && (y - (int)y) > 0.99)
				direct = 'n';
			else if (y > data->posy && (y - (int)y) < 0.01)
				direct = 's';
			else
				direct = 'e';
		}
	}
	return (direct);
}

int	is_wall(double x, double y)
{
	if (map[(int)y][(int)x] == 1)
		return (1);
	return (0);
}

void	cast_ray(t_data *data, double angle, int ray)
{
	double	ray_len;
	double	ray_x;
	double	ray_y;

	ray_x = data->posx;
	ray_y = data->posy;
	ray_len = 0.0;
	while (!is_wall(ray_x, ray_y))
	{
		ray_x = data->posx + (ray_len * (sin(angle * M_PI / 180.0)));
		ray_y = data->posy - (ray_len * (cos(angle * M_PI / 180.0)));
		ray_len += 0.01;
	}
	data->ray_len[ray] = ray_len * cos(fabs(data->angle - angle) * M_PI / 180.0);
	data->direct[ray] = define_direct(data, ray_x, ray_y);
	data->block_xpos[ray] = ray_x;
	data->block_ypos[ray] = ray_y;
}

void	calculate_rays(t_data *data)
{
	double	angle;
	double	ratio;
	int		ray;

	angle = data->angle - ((double)RANGE / 2.0);
	ratio = (double)RANGE / (double)SCREEN_WIDTH;
	ray = 0;
	while (ray < SCREEN_WIDTH)
	{
		cast_ray(data, angle, ray);
		angle += ratio;
		ray++;
	}
}
