/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:53:16 by vearleen          #+#    #+#             */
/*   Updated: 2022/01/21 04:44:47 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"all.h"

void	ft_output(int len, int *a, int *b)
{
	int	i;

	i = 0;
	write(1, "a ", 2);
	while (i < len)
	{
		ft_putnbr_fd(a[i], 1);
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
	i = 0;
	write(1, "b ", 2);
	while (i < len)
	{
		ft_putnbr_fd(b[i], 1);
		write(1, " ", 1);
		i++;
	}
	write(1, "\n\n", 2);
}
