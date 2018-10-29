/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 20:16:46 by kbui              #+#    #+#             */
/*   Updated: 2018/10/05 20:31:45 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstlen(const t_list *lst)
{
	t_list	*current;
	size_t	r;

	current = (t_list *)lst;
	r = 0;
	while (current != NULL)
	{
		r++;
		current = current->next;
	}
	return (r);
}
