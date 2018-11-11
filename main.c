/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 00:11:28 by kbui              #+#    #+#             */
/*   Updated: 2018/11/10 20:18:30 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "./includes/fillit.h"
#include "./includes/libft.h"

static char	*get_whole_file(char *filename)
{
	int		fd;
	int		size;
	char	buffer[600];
	char	*whole_file;

	if ((fd = open(filename, O_RDONLY)) < 1)
		return (NULL);
	size = read(fd, buffer, 600);
	buffer[size] = '\0';
	if (size % 21 != 0 || (41 < size && size < 548))
		return (NULL);
	whole_file = (char *)malloc(sizeof(char) * (size + 1));
	whole_file = ft_strcpy(whole_file, buffer);
	return (whole_file);
}

static char		**get_tetro_block(char *whole_file, int tetro_vld)
{
	int		i;
	int		j;
	char	**tetro_block;

	i = -1;
	j = 0;
	tetro_block = (char **)malloc(sizeof(tetro_block) * tetro_vld);
	while (whole_file[j] && ++i < tetro_vld)
	{
		tetro_block[i] = ft_strndup(&whole_file[j], 20);
		j += 21;
	}
	return (tetro_block);
}

int		fillit(char *filename)
{
	char		*whole_file;
	char		**tetro_block;
	int			tetro_vld;
	t_board		*board;
	int			i;

	if (!(whole_file = get_whole_file(filename)) ||
			(tetro_vld = input_vld(whole_file)) == ERROR)
		return (ERROR);
	tetro_block = get_tetro_block(whole_file, tetro_vld);
	if (adv_vld(tetro_block) == ERROR)
		return (ERROR);
	board = get_board(tetro_block, tetro_vld);
	i = -1;
	while (board->board_state[++i])
		ft_putendl(board->board_state[i]);
	return (1);
}

int		main(int ar, char **av)
{
	if (ar != 2)
	{
		ft_putstr("usage: ./filit Please put a valid number of file.\n");
		return (1);
	}
	if (fillit(av[1]) == ERROR)
	{
		ft_putstr("error\n");
		return (2);
	}
	return (0);
}
