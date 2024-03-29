/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:25:30 by bemmanue          #+#    #+#             */
/*   Updated: 2022/03/29 13:25:31 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, unsigned int color)
{
	char	*dst;

	dst = image->addr + (y * image->len + x * (image->bpp / 8));
	if (color > 0x00FFFFFF)
		*(unsigned int *)dst = 0x00000000;
	else
		*(unsigned int *)dst = color;
}

void	draw_image(t_data *data)
{
	cast_rays(data);
	draw_walls(data);
	if (data->minimap.is_open)
		draw_minimap(data);
}

int	render_next_frame(t_data *data)
{
	data->image.img = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	data->image.addr = mlx_get_data_addr(data->image.img,
			&data->image.bpp,
			&data->image.len, &data->image.end);
	draw_image(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->image.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = parser(argc, argv);
	data->mlx = mlx_init();
	init_data(data);
	data->mlx_win = mlx_new_window(data->mlx, SCREEN_WIDTH,
			SCREEN_HEIGHT, "Cub3D");
	render_next_frame(data);
	mlx_hook(data->mlx_win, 2, 0, key_hook, data);
	mlx_hook(data->mlx_win, 17, 0, close_hook, NULL);
	mlx_loop(data->mlx);
	return (0);
}
