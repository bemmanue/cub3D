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

enum e_const
{
	empty,
	map_error,
	pos_error,
	ceiling,
	floor,
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
}				t_map;

typedef struct s_data
{
	char		*n_tex;
	char		*s_tex;
	char		*w_tex;
	char		*e_tex;
	char		**inmap;
	char		**map;
	int			floor;
	int			ceiling;
	int			height;
	int			width;
	double		xpos;
	double		ypos;
	double		angle;
}				t_data;

t_data			*parser(int argc, char **argv);
t_map			*new_nod(t_map *up, t_map *down, char *str);
char			**real_array(t_map *start);
int				check_str(char *str, t_data *info);
int				modi(int i);
void			check_chips(t_map *line);
void			init_nods(int size, t_map *start, int y, char **src);
void			get_info(t_data *info, char *cub);
void			get_params(t_data *info);
void			map(t_data *info, int fd, char *line, t_flag *flags);
void			explore_map(t_data *info);
void			destroy_map(t_map *start);
_Noreturn void	err_msg(int flag);
void			check(t_map *start);

#endif
