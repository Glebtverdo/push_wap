/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:36:58 by vearleen          #+#    #+#             */
/*   Updated: 2021/10/11 21:18:33 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_elem;
	t_list	*buf;
	int		len;

	if (lst == NULL)
		return (NULL);
	len = ft_lstsize(lst);
	buf = lst;
	while (len > 0)
	{
		new_elem = ft_lstnew((*f)(lst->content));
		if (new_elem == NULL)
			ft_lstclear(&lst, (*del));
		ft_lstadd_back(&buf, new_elem);
		lst = lst->next;
		len--;
	}
	return (lst);
}
