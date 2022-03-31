/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:35:33 by vearleen          #+#    #+#             */
/*   Updated: 2021/10/11 21:19:20 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst == NULL)
	{
		*lst = new;
		new->next = NULL;
	}
	else
	{		
		*lst = ft_lstlast(*lst);
		(*lst)->next = new;
		new->next = NULL;
	}
}
