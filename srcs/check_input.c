/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 13:33:30 by kbui              #+#    #+#             */
/*   Updated: 2018/11/12 15:52:01 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		block_check(char *whole_file, int *i)
{
	int		row;
	int		col;
	int		hash;

	col = -1;
	hash = 0;
	while (++col < 4)
	{
		row = -1;
		while (++row < 4)
		{
			if (whole_file[*i] == '#')
				hash++;
			else if (whole_file[*i] != '.')
				return (0);
			(*i)++;
		}
		if (whole_file[(*i)++] != '\n')
			return (0);
	}
	if (hash != 4)
		return (0);
	return (1);
}

int		input_vld(char *whole_file)
{
	int		i;
	int		tetro_vld;

	i = 0;
	tetro_vld = 0;
	while (whole_file[i])
	{
		tetro_vld++;
		if (!block_check(whole_file, &i))
			return (0);
		if (whole_file[i] == '\n' && !whole_file[i + 1])
			return (0);
		else if (whole_file[i] && whole_file[i] != '\n')
			return (0);
		else if (!whole_file[i])
			return (tetro_vld);
		i++;
	}
	if (whole_file[i - 1] == '\n' && whole_file[i - 2] == '\n')
		return (0);
	return (tetro_vld);
}

int		tetro_vld(char *tetro_vld)
{
	int		i;
	int		j;
	int		list[4];

	i = 0;
	while (i < 4)
		list[i++] = 0;
	i = -1;
	j = 0;
	while (j < 4 && tetro_vld[++i])
	{
		if (tetro_vld[i] == '#' && i - 5 >= 0)
			list[j] += (tetro_vld[i - 5] == '#') ? 1 : 0;
		if (tetro_vld[i] == '#' && i + 5 <= 19)
			list[j] += (tetro_vld[i + 5] == '#') ? 1 : 0;
		if (tetro_vld[i] == '#' && i > 0)
			list[j] += (tetro_vld[i - 1] == '#') ? 1 : 0;
		if (tetro_vld[i] == '#' && i < 19)
			list[j] += (tetro_vld[i + 1] == '#') ? 1 : 0;
		if (tetro_vld[i] == '#')
			j++;
	}
	if (list[0] + list[1] + list[2] + list[3] >= 6)
		return (1);
	return (0);
}

int		adv_vld(char **tetro_block)
{
	int		i;

	i = -1;
	while (tetro_block[++i])
		if (!tetro_vld(tetro_block[i]))
			return (0);
	return (1);
}
