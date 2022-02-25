
#ifndef CUB_H
# define CUB_H

# include "mlx/mlx.h"
# include "../libft/libft.h"
//# include <parser.h>
# include <stdio.h>
# include <math.h>

#define 	WIDTH		360
#define		HEIGHT		360
#define 	MAP_WIDTH	10
#define		MAP_HEIGHT	10
#define 	X_POSITION	3
#define		Y_POSITION	7
#define		RANGE		90
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
	char	*north_texture; // ./path_to_the_north_texture
	char	*south_texture; // ./path_to_the_south_texture
	char	*west_texture; // ./path_to_the_west_texture
	char	*east_texture; // ./path_to_the_east_texture
	char	**map; // 1 - стена, 0 - свободное место, 2-5 - NESW соответственно
	// пробел - место за пределом карты
	int		floor_color; // 0x00FFFFFF
	int		ceiling_color; // 0x00FFFFFF
	int		x_pos; // x-позиция ячейки на карте
	int		y_pos; // y-позиция ячейки на карте
	int		angle; // 0/90/180/270
	int		width; // ширина карты в ячейках
	int		he ight; // высота карты в ячейках
}				t_param;

typedef	struct	s_pos
{
	int			x;
	int			y;
	int			angle;
}				t_pos;

typedef	struct	s_data
{
	t_pos		pos;
	t_param		mlx;
	int			walls[RANGE];
	char		direct[RANGE];
	int			x_ratio;
	int			y_ratio;
}				t_data;

static int ang;

static int	map[10][10] =
		{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		 {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
		 {1, 0, 0, 0, 0, 1, 1, 1, 0, 1},
		 {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		 {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		 {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

int		render_next_frame(t_data *data);
void	draw_image(t_image *img, t_data *data);
void	my_mlx_pixel_put(t_image *image, int x, int y, int color);

void	init_data(t_data *data);
void	init_pos(t_pos *pos, t_data *data);

void	calculate_rays(t_image *img, t_data *data);
void	cast_ray(t_image *img, t_data *data, float angle, int i);
int		is_wall(int x, int y);

void	draw_map(t_image *img);
void	draw_walls(t_image *img, t_data *data);
char	is_walls(int x, int y, t_data *data);

int		key_hook(int keycode, t_data *data);

#endif
