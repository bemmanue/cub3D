
#ifndef CUB_H
# define CUB_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
//# include <parser.h>
# include <stdio.h>
# include <math.h>

#define 	SCREEN_WIDTH	800
#define		SCREEN_HEIGHT	600

#define		VIEW_RANGE		66

# define 	KEY_D 			2
# define 	KEY_A	 		0
# define 	KEY_W			13
# define 	KEY_S			1
# define 	ARROW_RIGHT		47
# define 	ARROW_LEFT		43
# define	ESCAPE			53

typedef struct	s_image
{
	void			*img;
	char			*addr;
	int				bpp;
	int				len;
	int				end;
}					t_image;

typedef	struct	s_texture
{
	char			*path;
	int				width;
	int				height;
	t_image			*image;
}					t_texture;

typedef struct		s_ray
{
	double			angle;
	double			ray_len;
	char			wall_direct;
	double			wall_xpos;
	double			wall_ypos;
	double			wall_height;
	double			wall_top;
	double			wall_bottom;
}					t_ray;

typedef	struct		s_minimap
{
	double			x_len;
	double			y_len;
	double			x_ratio;
	double 			y_ratio;
	int				x_shift;
	int				y_shift;
}					t_minimap;

typedef	struct	s_data
{
	void			*mlx;
	void			*mlx_win;
	t_image			image;
//	t_texture		north;
//	t_texture		south;
//	t_texture		east;
//	t_texture		west;
	t_texture		texture[4];
	t_minimap		minimap;
	unsigned int	floor;
	unsigned int	ceiling;
	double			map_width;
	double			map_height;
	double			angle;
	double			xpos;
	double 			ypos;
	t_ray			ray[SCREEN_WIDTH];
	double			x_ratio;
	double			y_ratio;
	char			**map;
}					t_data;

static int ang;

static int	map[7][10] =
		{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		 {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
		 {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
		 {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
		 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		 {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

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
