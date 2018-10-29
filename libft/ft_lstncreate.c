/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstncreate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 20:18:21 by kbui              #+#    #+#             */
/*   Updated: 2018/10/05 22:20:42 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstncreate(size_t n)
{
	t_list	*first;
	t_list	*second;

	first = NULL;
	while (n--)
	{
		second = first;
		first = ft_lstnew(NULL, 0);
		first->next = second;
	}
	return (first);
}
