/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dubs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:38:52 by vearleen          #+#    #+#             */
/*   Updated: 2022/01/21 03:19:41 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../all.h"

void	ft_check_dubs(int *a, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (a[i] == a[index])
		{
			write(1, "ERROR DUBLICATE SUMBOLS\n", 24);
			exit(-1);
		}
		i++;
	}
}
