/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_maker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:05:31 by kbui              #+#    #+#             */
/*   Updated: 2018/11/12 16:21:14 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

/*
** I set min_row && min_col == 10 because size of the board never get bigger
** than 10. Why? Because maximum of tetro_vld they give me will be 26
** and sqrt(26 * 4) == 10
*/

static void		make_point(t_tetro *tetro_struct, char **tetro_split)
{
	int		i;
	int		j;
	int		min_row;
	int		min_col;
	int		point;

	min_row = 10;
	min_col = 10;
	i = -1;
	point = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (tetro_split[i][j] == '#')
			{
				tetro_struct->point[point].x = i;
				tetro_struct->point[point++].y = j;
				min_row = i < min_row ? i : min_row;
				min_col = j < min_col ? j : min_col;
			}
	}
	cut_off_space(tetro_struct, min_row, min_col);
}

static t_tetro	*get_tetro_struct(char *tetro_blocki)
{
	char		**tetro_split;
	int			i;
	t_tetro		*tetro_struct;

	if (!(tetro_struct = (t_tetro *)malloc(sizeof(*tetro_struct))))
		return (NULL);
	i = -1;
	while (++i < 4)
	{
		tetro_struct->point[i].x = 0;
		tetro_struct->point[i].y = 0;
	}
	if (!(tetro_split = ft_strsplit(tetro_blocki, '\n')))
		return (NULL);
	make_point(tetro_struct, tetro_split);
	i = -1;
	while (tetro_split[++i])
		ft_strdel(&tetro_split[i]);
	free(tetro_split);
	return (tetro_struct);
}

static t_tetro	**get_tetro_list(char **tetro_block, int tetro_vld)
{
	t_tetro		**tetro_list;
	int			i;

	tetro_list = (t_tetro **)malloc(sizeof(**tetro_list) * (tetro_vld + 1));
	i = -1;
	while (++i < tetro_vld)
		tetro_list[i] = get_tetro_struct(tetro_block[i]);
	tetro_list[i] = NULL;
	return (tetro_list);
}

static t_board	*create_board(t_tetro **tetro_list, int tetro_vld)
{
	t_board		*board;

	board = (t_board *)malloc(sizeof(*board));
	board->tetro_vld = tetro_vld;
	board->size = (int)ft_sqrt(tetro_vld * 4);
	board->tetro_list = tetro_list;
	board->board_state = new_board_state(board->size);
	return (board);
}

t_board			*get_board(char **tetro_block, int tetro_vld)
{
	int			tetro_index;
	t_board		*board;
	t_tetro		**tetro_list;

	tetro_list = get_tetro_list(tetro_block, tetro_vld);
	board = create_board(tetro_list, tetro_vld);
	tetro_index = 0;
	while (!do_backtrack(board, tetro_index))
		board_state_increase(board);
	return (board);
}
