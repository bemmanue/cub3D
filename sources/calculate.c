
#include "../cub.h"

int	is_wall(t_data *data, double x, double y)
{
	if (map[(int)y][(int)x] == 1)
		return (1);
	return (0);
}

char	specify_direct(t_data *data, double x, double y, char d)
{
	if (y < data->ypos && (y - (int)y) > 0.99)
		return (0);
	else if (y > data->ypos && (y - (int)y) < 0.01)
		return (1);
	else
		return (d);
}

char	define_direct(t_data *data, double x, double y)
{
	double	next_up;
	double	next_down;
	char	direct;

	next_up = y - (1.0 / data->y_ratio);
	next_down = y + (1.0 / data->y_ratio);
	if (x < data->xpos)
	{
		if (map[(int)next_up][(int)x] && map[(int)next_down][(int)x])
			direct = 3;
		else
			direct = specify_direct(data, x, y, 3);
	}
	else
	{
		if (map[(int)next_up][(int)x] && map[(int)next_down][(int)x])
			direct = 2;
		else
			direct = specify_direct(data, x, y, 2);
	}
	return (direct);
}

void	cast_ray(t_data *data, double angle, int ray)
{
	double	ray_len;
	double	ray_x;
	double	ray_y;

	ray_x = data->xpos;
	ray_y = data->ypos;
	ray_len = 0.0;
	while (!is_wall(data, ray_x, ray_y))
	{
		ray_x = data->xpos + (ray_len * (sin(angle * M_PI / 180.0)));
		ray_y = data->ypos - (ray_len * (cos(angle * M_PI / 180.0)));
		ray_len += 0.01;
	}
	data->ray[ray].ray_len = ray_len
		* cos(fabs(data->angle - angle) * M_PI / 180.0);
	data->ray[ray].wall_direct = define_direct(data, ray_x, ray_y);
	data->ray[ray].wall_xpos = ray_x;
	data->ray[ray].wall_ypos = ray_y;
	if (SCREEN_HEIGHT < SCREEN_WIDTH)
		data->ray[ray].wall_height = ((double)SCREEN_HEIGHT / (data->ray[ray].ray_len));
	else
		data->ray[ray].wall_height = ((double)SCREEN_WIDTH / (data->ray[ray].ray_len));
	data->ray[ray].wall_top = ((double)SCREEN_HEIGHT - data->ray[ray].wall_height) / 2.0;
	data->ray[ray].wall_bottom = ((double)SCREEN_HEIGHT + data->ray[ray].wall_height) / 2.0;
}

void	calculate_rays(t_data *data)
{
	double	angle;
	double	ratio;
	int		ray;

	angle = data->angle - ((double)VIEW_RANGE / 2.0);
	ratio = (double)VIEW_RANGE / (double)SCREEN_WIDTH;
	ray = 0;
	while (ray < SCREEN_WIDTH)
	{
		cast_ray(data, angle, ray);
		angle += ratio;
		ray++;
	}
}
