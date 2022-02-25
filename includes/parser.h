
#ifndef PARSER_H
# define PARSER_H

//# include "cub.h"
# include "../libft/libft.h"
# include <stdio.h>

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
	int		height; // высота карты в ячейках
}				t_param;

t_param			*parser(int argc, char **argv);



_Noreturn void	err_msg(int flag);

#endif
