/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three_one_stack.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 06:46:48 by vearleen          #+#    #+#             */
/*   Updated: 2022/01/24 20:41:23 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"all.h"

static void	ft_addithipnal_cases(int *arr)
{
	if (arr[0] < arr[2])
	{
		ft_swap(&arr[0], &arr[1]);
		write(1, "sa\n", 3);
	}
	else if (arr[1] < arr[2])
	{
		ft_rotate(arr, 3);
		write(1, "ra\n", 3);
	}
	else if (arr[1] > arr[2])
	{
		ft_rotate(arr, 3);
		write(1, "ra\n", 3);
		ft_swap(&arr[0], &arr[1]);
		write(1, "sa\n", 3);
	}
}

void	ft_sort_three_min_max_a(int *arr)
{
	if (arr[0] < arr[1])
	{
		if (arr[0] > arr[2])
		{
			ft_rev_rotate(arr, 3);
			write(1, "rra\n", 4);
		}
		else if (arr[1] > arr[2] && arr[2] > arr[0])
		{
			ft_rev_rotate(arr, 3);
			write(1, "rra\n", 4);
			ft_swap(&arr[0], &arr[1]);
			write(1, "sa\n", 3);
		}
	}
	else
		ft_addithipnal_cases(arr);
}
