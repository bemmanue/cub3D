/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:24:19 by bemmanue          #+#    #+#             */
/*   Updated: 2022/03/29 13:24:22 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <parser.h>

# define SCREEN_WIDTH	800
# define SCREEN_HEIGHT	600

# define VIEW_RANGE		66

# define KEY_D 			2
# define KEY_A	 		0
# define KEY_W			13
# define KEY_S			1
# define ARROW_RIGHT		47
# define ARROW_LEFT		43
# define ESCAPE			53

void	my_mlx_pixel_put(t_image *image, int x, int y, unsigned int color);
void	init_data(t_data *data);

void	cast_rays(t_data *data);
void	init_ray(t_data *data, double angle, t_ray *ray);
int		is_wall(t_data *data, double x, double y);

void	draw_minimap(t_data *data);
void	draw_walls(t_data *data);
char	is_walls(int x, int y, t_data *data);

int		close_hook(void);
int		key_hook(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);

void	exit_error(char *message);

t_data	*parser_data(char *path);

#endif
