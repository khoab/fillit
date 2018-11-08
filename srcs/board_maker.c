/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_maker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:05:31 by kbui              #+#    #+#             */
/*   Updated: 2018/10/25 20:53:21 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

static void		make_point(t_tetro *tetro_struct, char **tetro_split)
{
	
}

static char		*get_tetro_struct(char *tetro_blocki)
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
		ft_strdel(tetro_split[i]);
	free(tetro_split);
	return (tetro_struct);
}

static char		*create_board(t_tetro **tetro_list, int tetro_vld)
{
	t_board		*board;
	int			i;
	int			j;
	char		**board_state;

	if (board = (t_board *)malloc(sizeof(*board)))
		return (NULL);
	board->tetro_vld = tetro_vld;
	board->size = (int)ft_sqrt(tetro_vld * 4);
	board->tetro_list = tetro_list;
	if (!(board_state = (char **)malloc(sizeof(**board_state) * board->size)))
		return (NULL);
	i = -1;
	while (++i < board->size)
	{
		if (!(board_state[i] = ft_strnew(board->size + 1)))
			return (NULL);
		j = -1;
		while (++j < board->size)
			board_state[i][j] = '.';
	}
	board->broad_state = board_state;
	return (board);
}

t_board			*get_board(char **tetro_block, int tetro_vld)
{
	int			tetro_index;
	t_board		*board;
	t_tetro		**tetro_list;
	int			i;

	if (!(tetro_list = (char **)malloc(sizeof(tetro_list) * (tetro_vld))))
		return (NULL);
	i = -1;
	while (++i < tetro_vld)
		tetro_list[i] = get_tetro_struct(tetro_block[i]);
	board = create_broad(tetro_list, tetro_vld);
	tetro_index = 0;
	while (!do_backtrack(board, tetro_index))
		board_state_increase(board);
	return (board);
}