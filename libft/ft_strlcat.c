/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 15:56:49 by kbui              #+#    #+#             */
/*   Updated: 2018/09/13 16:01:08 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	src_i;
	size_t	dst_i;

	dstlen = ft_strnlen(dst, size);
	srclen = ft_strlen(src);
	if (dstlen < size)
	{
		src_i = 0;
		dst_i = dstlen;
		while (dst_i < size && src_i < srclen)
			dst[dst_i++] = src[src_i++];
		if (dst_i < size)
			dst[dst_i] = '\0';
		else
			dst[size - 1] = '\0';
	}
	return (dstlen + srclen);
}
