/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 15:33:05 by kbui              #+#    #+#             */
/*   Updated: 2018/10/05 21:08:43 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = 0;
	while (j < len && src[j])
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dst);
}
