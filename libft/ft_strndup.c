/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 00:19:11 by kbui              #+#    #+#             */
/*   Updated: 2018/11/10 19:53:23 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *src, int size)
{
	char	*dup;
	int		i;

	size += 1;
	if (!(dup = (char *)malloc(sizeof(dup) * size)))
		return (NULL);
	i = -1;
	while (++i < size)
		dup[i] = src[i];
	dup[i] = '\0';
	return (dup);
}
