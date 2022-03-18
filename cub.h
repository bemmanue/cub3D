
#ifndef CUB_H
# define CUB_H

# include <mlx.h>
# include "libft/libft.h"
# include <stdio.h>
# include <math.h>

#define 	SCREEN_WIDTH	600
#define		SCREEN_HEIGHT	500
#define 	MAP_WIDTH		10
#define		MAP_HEIGHT		10
#define		RANGE			66
# define 	ARROW_RIGHT 	2
# define 	ARROW_LEFT 		0
# define 	ARROW_UP		13
# define 	ARROW_DOWN		1
# define 	KEY_RIGHT		47
# define 	KEY_LEFT		43
#define		ESCAPE			53

typedef struct	s_image
{
	void		*img;
	char		*addr;
	int			bpp;
	int			len;
	int			end;
}				t_image;

typedef	struct	s_texture
{
	int			width;
	int			height;
	t_image		*image;
}				t_texture;

typedef	struct	s_data
{
	void			*mlx;
	void			*mlx_win;
	t_texture		*north;
	t_texture		*south;
	t_texture		*east;
	t_texture		*west;
	unsigned int	floor;
	unsigned int	ceiling;
	t_image			image;
	double			angle;
	double			posx;
	double 			posy;
	double			ray_len[SCREEN_WIDTH];
	char			direct[SCREEN_WIDTH];
	double			block_xpos[SCREEN_WIDTH];
	double			block_ypos[SCREEN_WIDTH];
	double			x_ratio;
	double			y_ratio;
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
int		is_wall(double x, double y);

void	draw_map(t_data *data);
void	draw_walls(t_data *data);
char	is_walls(int x, int y, t_data *data);

int		key_hook(int keycode, t_data *data);

#endif
