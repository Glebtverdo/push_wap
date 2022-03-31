/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:44:42 by vearleen          #+#    #+#             */
/*   Updated: 2022/01/21 03:18:21 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"main_func.h"

void	ft_push(int *arr1, int *arr2, int len)
{
	ft_rev_rotate(arr2, len);
	ft_swap(&arr1[0], &arr2[0]);
	ft_rotate(arr1, len);
}

void	ft_push_char(char **arr1, char **arr2, int len)
{
	ft_rev_rotate_char(arr2, len);
	ft_swap_char(&arr1[0], &arr2[0]);
	ft_rotate_char(arr1, len);
}
