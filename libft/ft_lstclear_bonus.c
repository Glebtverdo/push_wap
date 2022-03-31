/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:35:56 by vearleen          #+#    #+#             */
/*   Updated: 2021/10/11 21:19:00 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*buf;

	if (*lst != NULL)
	{
		while (*lst != NULL)
		{
			buf = (*lst)->next;
			(*del)((*lst)->content);
			free(*lst);
			*lst = buf;
		}
	}
}
