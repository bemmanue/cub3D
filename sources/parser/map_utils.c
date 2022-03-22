#include <parser.h>

int	modi(int i)
{
	if (i < 0)
		i *= -1;
	return (i);
}

void	init_nods(int size, t_map *start, int y, char **src)
{
	t_map	*move;
	int		index;

	move = start;
	index = y;
	while (index > 0)
	{
		move->up = new_nod(NULL, move, src[--index], 0);
		move = move->up;
		if (move->begin < 0)
			break ;
	}
	move = start;
	index = y + 1;
	while (index < size)
	{
		move->down = new_nod(move, NULL, src[index++], 0);
		move = move->down;
		if (move->begin < 0)
			break ;
	}
}
