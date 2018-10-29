/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 19:51:17 by kbui              #+#    #+#             */
/*   Updated: 2018/10/18 10:11:12 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <sys/types.h>

int		ft_isfile(char *filename)
{
	struct stat		buffer;
	int				ret;

	ret = stat(filename, &buffer);
	if (ret == 0 && !S_ISDIR(buffer.st_mode))
		return (1);
	return (0);
}
