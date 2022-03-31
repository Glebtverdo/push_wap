/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:19:10 by vearleen          #+#    #+#             */
/*   Updated: 2022/01/24 20:42:29 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all.h"

static int	ft_search(int *arr, int desired)
{
	int	i;

	i = 0;
	while (arr[i] != desired)
		i++;
	return (i);
}

static void	ft_sort_four(int *a, int *b, t_vars *vars)
{
	int	index_min;

	index_min = ft_search(a, vars->min_i);
	while (index_min)
	{
		ft_rotate(a, vars->len_a);
		write(1, "ra\n", 3);
		index_min--;
	}
	ft_push(a, b, vars->len);
	vars->len_a--;
	vars->len_b++;
	write(1, "pb\n", 3);
	ft_sort_three_min_max_a(a);
	ft_push(b, a, vars->len);
	vars->len_a++;
	vars->len_b--;
	write(1, "pa\n", 3);
}

static void	ft_push_back(int *a, int *b, t_vars *vars)
{
	if (b[0] == vars->max_i)
	{
		ft_swap(&b[0], &b[1]);
		write(1, "sb\n", 3);
	}
	ft_push(b, a, vars->len);
	ft_push(b, a, vars->len);
	vars->len_a += 2;
	vars->len_b -= 2;
	write(1, "pa\npa\n", 6);
	ft_rotate(a, vars->len_a);
	write(1, "ra\n", 3);
	exit(0);
}

static void	ft_sort_five(int *a, int *b, t_vars *vars)
{
	int	index_min;
	int	index_max;

	index_min = ft_search(a, vars->min_i);
	index_max = ft_search(a, vars->max_i);
	if (index_max > index_min)
		index_min = index_max;
	while (index_min + 1)
	{
		if (a[0] == vars->max_i || a[0] == vars->min_i)
		{
			ft_push(a, b, vars->len);
			vars->len_a--;
			vars->len_b++;
			write(1, "pb\n", 3);
		}
		else
		{
			ft_rotate(a, vars->len_a);
			write(1, "ra\n", 3);
		}
		index_min--;
	}
	ft_sort_three_min_max_a(a);
	ft_push_back(a, b, vars);
}

void	ft_first_check(int *a, int *b, t_vars *vars)
{
	if (vars->len == 2 && a[0] > a[1])
	{
		ft_swap(&a[0], &a[1]);
		write(1, "sa\n", 3);
		exit(0);
	}
	else if (vars->len == 3)
	{
		ft_sort_three_min_max_a(a);
		exit(0);
	}
	else if (vars->len == 4)
	{
		ft_sort_four(a, b, vars);
		exit(0);
	}	
	else if (vars->len == 5)
	{
		ft_sort_five(a, b, vars);
		exit(0);
	}	
}
