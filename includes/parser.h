/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:17:27 by dwillard          #+#    #+#             */
/*   Updated: 2022/03/10 16:25:19 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

//# include "cub.h"
# include "../libft/libft.h"
# include "../sources/parser/get_next_line/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

# define EMPTY 0
# define MAP 1
# define NORTH 'N'
# define EAST 'E'
# define SOUTH 'S'
# define WEST 'W'
# define CEILING 6
# define FLOOR 7
# define NEWS_ERROR 8
# define NEWS_OP_ER 9
# define COLORS_ERR 10
# define MEM_ERROR 11
# define DUP_TEX 12
# define DUP_COL 13

struct s_byte
{
	unsigned map:	1;
	unsigned n:		1;
	unsigned e:		1;
	unsigned s:		1;
	unsigned w:		1;
	unsigned c:		1;
	unsigned f:		1;
};

typedef union u_flag
{
	char			val;
	struct s_byte	flag;
}				t_flag;

typedef struct s_param
{
	char	*n_tex; // ./path_to_the_north_texture
	char	*s_tex; // ./path_to_the_south_texture
	char	*w_tex; // ./path_to_the_west_texture
	char	*e_tex; // ./path_to_the_east_texture
	char	**map; // 1 - стена, 0 - свободное место, 2-5 - NESW соответственно
	// пробел - место за пределом карты
	int		floor; // 0x00FFFFFF
	int		ceiln; // 0x00FFFFFF
	double	x_pos; // x-позиция ячейки на карте
	double	y_pos; // y-позиция ячейки на карте
	double	angle; // 0/90/180/270
}				t_param;

t_param			*parser(int argc, char **argv);

void			get_info(t_param *info, char *cub);

void			map(t_param *info, int fd);

int				check_str(char *str, t_param *info);

_Noreturn void	err_msg(int flag);

#endif
