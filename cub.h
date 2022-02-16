
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
#define		RANGE		90
# define 	KEY_RIGHT 	124
# define 	KEY_LEFT 	123

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
	int			x_ratio;
	int			y_ratio;
}				t_data;

#endif
