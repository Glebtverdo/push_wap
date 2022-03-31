/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:24:11 by vearleen          #+#    #+#             */
/*   Updated: 2022/01/24 19:42:09 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"main_func.h"

void	ft_rotate(int *arr, int len)
{
	int	i;

	if (len > 0)
	{
		ft_swap(&arr[0], &arr[len - 1]);
		i = 0;
		while (i < len - 2)
		{
			ft_swap(&arr[i], &arr[i + 1]);
			i++;
		}
	}
}

void	ft_rotate_char(char **arr, int len)
{
	int	i;

	if (len > 0)
	{
		ft_swap_char(&arr[0], &arr[len - 1]);
		i = 0;
		while (i < len - 2)
		{
			ft_swap_char(&arr[i], &arr[i + 1]);
			i++;
		}
	}
}
