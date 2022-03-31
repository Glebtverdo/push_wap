/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:23:53 by vearleen          #+#    #+#             */
/*   Updated: 2022/01/24 19:46:03 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../struct.h"

int	ft_sort_check(t_vars *vars, int *a)
{
	int	i;
	int	counter;

	i = 1;
	counter = 1;
	while (i < vars->len_a)
	{
		if (a[i - 1] < a[i])
			counter++;
		else
			return (counter);
		i++;
	}
	return (counter);
}
