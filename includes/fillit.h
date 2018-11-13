/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 01:38:29 by kbui              #+#    #+#             */
/*   Updated: 2018/11/12 16:20:24 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define ERROR -1

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef	struct	s_tetro
{
	t_point		point[4];
}				t_tetro;

typedef struct	s_board
{
	t_tetro		**tetro_list;
	char		**board_state;
	int			size;
	int			tetro_vld;
}				t_board;

/*
** Main fillit function and getting input
*/

int				fillit(char *filename);

/*
** Check if input is valid
*/

int				block_check(char *whole_file, int *i);
int				input_vld(char *whole_file);
int				tetro_vld(char *tetro_vld);
int				adv_vld(char **tetro_block);

/*
** Then make a broad if everything seem valid
*/

t_board			*get_board(char **tetro_block, int tetro_vld);
void			cut_off_space(t_tetro *tetro_struct, int min_row, int min_col);
int				do_backtrack(t_board *board, int tetro_index);
int				board_state_increase(t_board *board);
char			**new_board_state(int size);

#endif
