/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 00:11:28 by kbui              #+#    #+#             */
/*   Updated: 2018/11/12 16:15:57 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fillit.h"
#include "libft.h"

static char	*get_whole_file(char *filename)
{
	int		fd;
	int		size;
	char	buffer[600];
	char	*whole_file;

	if ((fd = open(filename, O_RDONLY)) < 1)
		return (NULL);
	if (!(size = read(fd, buffer, 600)))
		return (NULL);
	buffer[size] = '\0';
	if (((size + 1) % 21) || (size <= 41 && size >= 548))
		return (NULL);
	whole_file = (char *)malloc(sizeof(char) * (size + 1));
	whole_file = ft_strcpy(whole_file, buffer);
	return (whole_file);
}

static char	**get_tetro_block(char *whole_file, int tetro_vld)
{
	int		i;
	int		j;
	char	**tetro_block;

	i = 0;
	j = 0;
	tetro_block = (char **)malloc(sizeof(*tetro_block) * (tetro_vld + 1));
	while (whole_file[j] && i < tetro_vld)
	{
		tetro_block[i] = ft_strndup(&whole_file[j], 20);
		i++;
		j += 21;
	}
	tetro_block[i] = NULL;
	return (tetro_block);
}

char		**new_board_state(int size)
{
	int		i;
	int		j;
	char	**board_state;

	board_state = (char **)malloc(sizeof(*board_state) * (size + 1));
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

int			fillit(char *filename)
{
	char		*whole_file;
	char		**tetro_block;
	int			tetro_vld;
	t_board		*board;
	int			i;

	if (!(whole_file = get_whole_file(filename)) ||
			!(tetro_vld = input_vld(whole_file)))
		return (0);
	tetro_block = get_tetro_block(whole_file, tetro_vld);
	if (!adv_vld(tetro_block))
		return (0);
	board = get_board(tetro_block, tetro_vld);
	i = -1;
	while (board->board_state[++i])
		ft_putendl(board->board_state[i]);
	return (1);
}

int			main(int ar, char **av)
{
	if (ar != 2)
	{
		ft_putstr("usage: ./filit Please put a valid number of file.\n");
		return (1);
	}
	if (!fillit(av[1]))
	{
		ft_putstr("error\n");
		return (2);
	}
	return (0);
}
