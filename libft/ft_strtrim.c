/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 18:40:32 by kbui              #+#    #+#             */
/*   Updated: 2018/10/05 20:32:46 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_iswhitespace(int c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

static	char	*ft_cpy_strtrim(char const *s, size_t start, size_t end)
{
	size_t		i;
	char		*cpy;

	if (!(cpy = (char *)malloc(end - start + 1)))
		return (NULL);
	i = 0;
	while (start < end)
		cpy[i++] = s[start++];
	cpy[i] = '\0';
	return (cpy);
}

char			*ft_strtrim(char const *s)
{
	size_t		start;
	size_t		end;

	if (!s)
		return (NULL);
	end = ft_strlen(s);
	start = 0;
	if (end > 0)
	{
		while (s[start] != '\0' && ft_iswhitespace(s[start]))
			start++;
		if (s[start] == '\0')
			start = end;
		else
		{
			while (--end > 0 && ft_iswhitespace(s[end]))
				(void)0;
			end++;
		}
	}
	return (ft_cpy_strtrim(s, start, end));
}
