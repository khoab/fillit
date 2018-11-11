/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 22:41:26 by kbui              #+#    #+#             */
/*   Updated: 2018/11/10 19:52:16 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnjoin(char *s1, char *src, int size)
{
	char	*new_str;
	int		i;
	int		s1_len;
	int		j;

	if (!s1 || !src)
		return (NULL);
	s1_len = ft_strlen(s1);
	new_str = ft_strnew(s1_len + size);
	if (!new_str)
		return (NULL);
	i = -1;
	while (++i < s1_len)
		new_str[i] = new_str[i];
	j = -1;
	i -= 1;
	while (++i < size)
		new_str[i] = src[++j];
	return (new_str);
}
