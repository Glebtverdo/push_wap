/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:34:04 by vearleen          #+#    #+#             */
/*   Updated: 2022/01/24 20:54:59 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"all.h"
#include<stdio.h>

static int	*ft_additional_func_for_smaller_numbers(int i, t_vars *vars, \
int *a, int *new_a)
{
	long int	buf_for_min_i;
	int			ii;
	int			save_index;

	while (i != vars->len)
	{
		ii = 0;
		buf_for_min_i = 2147483648;
		while (ii < vars->len)
		{
			if (a[ii] > vars->min_i && a[ii] < buf_for_min_i)
			{
				buf_for_min_i = a[ii];
				save_index = ii;
			}
			ii++;
		}
		vars->min_i = buf_for_min_i;
		new_a[save_index] = i;
		i++;
	}
	return (new_a);
}

static int	*ft_make_numbers_smaller(int *a, t_vars *vars)
{
	int			*new_a;
	int			i;

	new_a = malloc(sizeof(int) * vars->len);
	i = 0;
	while (a[i] != vars->min_i)
		i++;
	new_a[i] = 0;
	i = 1;
	return (ft_additional_func_for_smaller_numbers(i, vars, a, new_a));
}

static void	ft_additional_func_for_main(int *a, \
int *b, t_vars *vars, const char **argv)
{
	int	i;

	i = 1;
	while (i <= vars->len)
	{
		a[i - 1] = ft_atoi(argv[i]);
		if (i == 1)
		{
			vars->min_i = a[0];
			vars->max_i = a[0];
		}
		if (a[i - 1] < vars->min_i)
			vars->min_i = a[i - 1];
		if (a[i - 1] > vars->max_i)
			vars->max_i = a[i - 1];
		ft_check_dubs(a, i - 1);
		b[i - 1] = 0;
		i++;
	}
	if (ft_sort_check(vars, a) == vars->len)
		exit(0);
}

static const char	**ft_check_args(int *argc, const char **argv)
{
	if (*argc < 2)
	{	
		write(1, "ERROR NO DATA\n", 14);
		exit(0);
	}
	if (*argc == 2)
		argv = ft_split(argv[1], ' ', argc);
	if (*argc == 2)
		exit(0);
	return (argv);
}

int	main(int argc, char const **argv)
{
	int			*a;
	int			*new_a;
	int			*b;
	t_vars		*vars;

	argv = ft_check_args(&argc, argv);
	a = (int *)malloc(sizeof(int) * (argc - 1));
	b = (int *)malloc(sizeof(int) * (argc - 1));
	vars = (t_vars *)malloc(sizeof(t_vars));
	if (!a || !b || !vars)
	{
		write(1, "malloc Error\n", 13);
		exit(-1);
	}
	vars->len = argc - 1;
	vars->len_a = argc - 1;
	vars->len_b = 0;
	ft_additional_func_for_main(a, b, vars, argv);
	ft_first_check(a, b, vars);
	new_a = ft_make_numbers_smaller(a, vars);
	free(a);
	ft_sort_main(new_a, b, vars);
	exit(0);
	return (0);
}
