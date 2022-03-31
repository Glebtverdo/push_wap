/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:39:13 by vearleen          #+#    #+#             */
/*   Updated: 2022/01/24 20:40:49 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_H
# define ALL_H
# include"./libft/libft.h"
# include"./main_funcs/main_func.h"
# include"struct.h"
# include"stdio.h"

int		ft_sort_check(t_vars *vars, int *b);
void	ft_output(int len, int *a, int *b);
void	ft_check_dubs(int *b, int index);
void	ft_first_check(int *a, int *b, t_vars *vars);
void	ft_sort_three_min_max_a(int *arr);
void	ft_sort_main(int *a_int, int *b_int, t_vars *vars);

#endif
