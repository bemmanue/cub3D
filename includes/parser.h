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

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../sources/parser/get_next_line/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <newtype.h>

t_data			*parser(int argc, char **argv);
t_map			*new_nod(t_map *up, t_map *down, char *str);
char			**real_array(t_map *start);
int				check_str(char *str, t_data *info);
int				modi(int i);
int				cub_atoi(const char *str);
void			duplicate(t_data *info);
void			check_chips(t_map *line);
void			init_nods(int size, t_map *start, int y, char **src);
void			get_info(t_data *info, int fd);
void			get_params(t_data *info);
void			map(t_data *info, int fd, char *line, t_flag *flags);
void			explore_map(t_data *info);
void			destroy_map(t_map *start);
_Noreturn void	err_msg(int flag);
void			replace(char *str);

#endif
