/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 20:13:36 by kbui              #+#    #+#             */
/*   Updated: 2018/10/05 20:31:39 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memdup(const void *src, size_t len)
{
	char	*r;

	if (!(r = (char *)malloc(len)))
		return (NULL);
	return (ft_memcpy(r, src, len));
}
