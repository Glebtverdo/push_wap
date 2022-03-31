/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:54:54 by vearleen          #+#    #+#             */
/*   Updated: 2022/01/21 03:18:21 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"main_func.h"

void	ft_rev_rotate(int *arr, int len)
{
	int	i;

	if (len > 0)
	{
		i = len - 2;
		while (i > 0)
		{
			ft_swap(&arr[i], &arr[i - 1]);
			i--;
		}
		ft_swap(&arr[0], &arr[len - 1]);
	}
}

void	ft_rev_rotate_char(char **arr, int len)
{
	int	i;

	if (len > 0)
	{
		i = len - 2;
		while (i > 0)
		{
			ft_swap_char(&arr[i], &arr[i - 1]);
			i--;
		}
		ft_swap_char(&arr[0], &arr[len - 1]);
	}
}
