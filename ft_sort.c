/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 22:55:45 by vearleen          #+#    #+#             */
/*   Updated: 2022/01/24 20:57:16 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"all.h"

static void	ft_push_back(char **a, char **b, t_vars *vars)
{
	while (vars->len_b)
	{
		ft_push_char(b, a, vars->len);
		write(1, "pa\n", 3);
		vars->len_b--;
		vars->len_a++;
	}
}

static void	ft_dec_to_binary(char *point, long int value, long int grade)
{
	point[0] = (value / grade) + 48;
	if (value >= grade)
		value -= grade;
	grade /= 2;
	if (grade != 0)
		ft_dec_to_binary(&point[1], value, grade);
	else
		point[1] = '\0';
}

static char	**ft_make_binary(int *arr_int, int len)
{
	char	**arr_char;
	int		i;

	i = 0;
	arr_char = (char **)(malloc(sizeof(char *) * len));
	while (i < len)
	{
		arr_char[i] = malloc(sizeof(char) * 33);
		ft_dec_to_binary(arr_char[i], arr_int[i], 2147483648);
		i++;
	}
	return (arr_char);
}

static void	ft_sort_logic(char **a, char **b, t_vars *vars, int index)
{
	int	i;

	i = 0;
	while (i < vars->len)
	{
		if (a[0][index] == '0')
		{
			ft_push_char(a, b, vars->len);
			vars->len_a--;
			vars->len_b++;
			write(1, "pb\n", 3);
		}
		else
		{	
			ft_rotate_char(a, vars->len_a);
			write(1, "ra\n", 3);
		}
		i++;
	}
	ft_push_back(a, b, vars);
}

void	ft_sort_main(int *a_int, int *b_int, t_vars *vars)
{
	char	**a;
	char	**b;
	int		index;
	int		i;
	int		counter;

	a = ft_make_binary(a_int, vars->len);
	b = ft_make_binary(b_int, vars->len);
	index = 31;
	while (index)
	{
		i = 1;
		counter = 1;
		while (i < vars->len_a)
		{
			if (a[i][index] == a[i - 1][index])
				counter++;
			i++;
		}
		if (counter != vars->len_a)
			ft_sort_logic(a, b, vars, index);
		index--;
	}
	exit(0);
}
