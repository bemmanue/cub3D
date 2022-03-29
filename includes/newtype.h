#ifndef NEWTYPE_H
# define NEWTYPE_H

# define 	SCREEN_WIDTH	800
# define	SCREEN_HEIGHT	600

# define	VIEW_RANGE		66

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
	int				x_len;
	int				y_len;
	double			x_ratio;
	double 			y_ratio;
	int				x_shift;
	int				y_shift;
}					t_minimap;

typedef	struct	s_data
{
	char			**map;
	void			*mlx;
	void			*mlx_win;
	t_image			image;
	t_texture		north;
	t_texture		east;
	t_texture		south;
	t_texture		west;
	t_minimap		minimap;
	unsigned int	floor;
	unsigned int	ceiling;
	double			map_width;
	double			map_height;
	double			angle;
	double			x_pos;
	double 			y_pos;
	t_ray			ray[SCREEN_WIDTH];
	double			x_ratio;
	double			y_ratio;
}					t_data;

enum e_const
{
	empty,
	map_error,
	pos_error,
	ceiling,
	floor_clr,
	news_error,
	news_op_error,
	colors_err,
	mem_error,
	get_error,
	dup_tex,
	dup_col,
	content_err,
	north = 'N',
	east = 'E',
	south = 'S',
	west = 'W'
};

struct s_byte
{
	unsigned map:	1;
	unsigned pos:	1;
	unsigned n:		1;
	unsigned e:		1;
	unsigned w:		1;
	unsigned s:		1;
	unsigned c:		1;
	unsigned f:		1;
};

typedef union u_flag
{
	char			val;
	struct s_byte	flag;
}				t_flag;

typedef struct s_map
{
	int				**interval;
	int				count;
	int				len;
	char			*str;
	struct s_map	*up;
	struct s_map	*down;
}					t_map;

#endif
