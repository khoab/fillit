/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 17:55:17 by kbui              #+#    #+#             */
/*   Updated: 2018/11/11 21:43:46 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fillit.h"
#include <stdio.h>

static void	remove_or_add(t_board *board, int tetro_index, t_point pos,
												int remove_or_add)
{
	int			i;
	char		c;
	t_tetro		*tetro_struct;

	tetro_struct = board->tetro_list[tetro_index];
	i = -1;
	printf("Work\n");
	/*
	** It fucking segfault as some where I dont fucking know. But I knew that 
	** it will only run for one fucking time only. Then if you redo it, it will
	** not working anymore. So I need to fix that situation.
	*/
	c = (remove_or_add == 1) ? 'A' : '.';
	while (++i < 4)
		board->board_state[tetro_struct->point[i].x + pos.x]
			[tetro_struct->point[i].y + pos.y] = c;
}

static int	is_safe(t_board *board, t_tetro *tetro_struct, t_point pos)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (tetro_struct->point[i].x + pos.x >= board->size ||
					tetro_struct->point[i].y + pos.y >= board->size ||
					(board->board_state[tetro_struct->point[i].x + pos.x]
						[tetro_struct->point[i].y + pos.y] != '.'))
			return (0);
		i++;
	}
	return (1);
}

char		**new_board_state(int size)
{
	int		i;
	int		j;
	char	**board_state;

	board_state = (char **)malloc(sizeof(**board_state) * (size + 1));
	i = -1;
	while (++i < size)
	{
		board_state[i] = ft_strnew(size + 1);
		j = -1;
		while (++j < size)
			board_state[i][j] = '.';
	}
	board_state[i] = NULL;
	return (board_state);
}

int			board_state_increase(t_board *board)
{
/*
**	char	**prev;
**	char	**curr;
**
**	printf("Work\n");
**	while (*prev)
**	{
**		curr = prev + 1;
**		ft_strdel(prev);
**		prev = curr;
**	}
*/	free(board->board_state);
	board->board_state = NULL;
	board->size += 1;
	board->board_state = new_board_state(board->size);
	return (1);
}

int			do_backtrack(t_board *board, int tetro_index)
{
	int		i;
	int		j;
	t_point	pos;

	if (tetro_index >= board->tetro_vld)
		return (1);
	i = -1;
	while (++i < board->size)
	{
		j = -1;
		while (++j < board->size)
		{
			pos.x = i;
			pos.y = j;
			if (is_safe(board, board->tetro_list[tetro_index], pos))
			{
				remove_or_add(board, tetro_index, pos, 1);
				if (do_backtrack(board, tetro_index + 1))
					return (1);
				remove_or_add(board, tetro_index, pos, 0);
			}
		}
	}
	return (0);
}
