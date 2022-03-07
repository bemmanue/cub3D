
#ifndef CUB_H
# define CUB_H

# include <mlx.h>
# include "libft/libft.h"
# include <stdio.h>
# include <math.h>

#define 	WIDTH		400
#define		HEIGHT		400
#define 	MAP_WIDTH	10
#define		MAP_HEIGHT	10
#define 	X_POSITION	3
#define		Y_POSITION	7
#define		RANGE		66
# define 	ARROW_RIGHT 124
# define 	ARROW_LEFT 	123
# define 	ARROW_UP	126
# define 	ARROW_DOWN	125
# define 	KEY_RIGHT	47
# define 	KEY_LEFT	43

typedef struct	s_image
{
	void		*img;
	char		*addr;
	int			bpp;
	int			len;
	int			end;
}				t_image;

typedef struct	s_param
{
	void		*mlx;
	void		*mlx_win;
}				t_param;

typedef	struct	s_texture
{
	int			width;
	int			height;
	t_image		*image;
}				t_texture;

typedef	struct	s_data
{
	t_param		mlx;
	t_texture	*texture;
	t_image		image;
	double		angle;
	double		posx;
	double 		posy;
	double		walls[WIDTH];
	char		direct[WIDTH];
	double		block_xpos[WIDTH];
	double		block_ypos[WIDTH];
	double		x_pos[WIDTH];
	double		y_pos[WIDTH];
	double		len[WIDTH];
	double 		ang[WIDTH];
	double		x_ratio;
	double		y_ratio;
}				t_data;

static int ang;

static int	map[10][10] =
		{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		 {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
		 {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
		 {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
		 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

void	my_mlx_pixel_put(t_image *image, int x, int y, unsigned int color);
void	init_data(t_data *data);

void	calculate_rays(t_data *data);
void	cast_ray(t_data *data, double angle, int i);
int		is_wall(t_data *data, double x, double y);

void	draw_map(t_data *data);
void	draw_walls(t_data *data);
char	is_walls(int x, int y, t_data *data);

int		key_hook(int keycode, t_data *data);

#endif
