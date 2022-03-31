/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 20:42:21 by vearleen          #+#    #+#             */
/*   Updated: 2022/01/24 19:45:29 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_check_long(size_t counter, int minus, size_t result)
{
	if ((result > 2147483647 && minus != -1) || \
	(result > 2147483648 && minus == -1))
	{
		write(1, "to long number", 15);
		exit(-1);
	}
	if (counter > 19)
	{
		if (minus == -1)
			return (0);
		else
			return (-1);
	}
	return (result * minus);
}

static int	ft_minus(const char *str, size_t *i)
{
	int	minus;

	minus = 1;
	if (str[*i] == '-')
	{
		minus = -1;
		*i += 1;
	}
	else if (str[*i] == '+')
		*i += 1;
	return (minus);
}

int	ft_atoi(const char *str)
{
	size_t					i;
	unsigned long long int	result;
	int						minus;
	size_t					counter;
	size_t					len;

	result = 0;
	i = 0;
	minus = ft_minus(str, &i);
	counter = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (!ft_isdigit(str[i]))
		{
			write(1, "ERROR WRONG INPUT\n", 18);
			exit(-1);
		}
		counter++;
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (ft_check_long(counter, minus, result));
}
