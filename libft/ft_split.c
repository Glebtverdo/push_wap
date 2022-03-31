/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:37:49 by vearleen          #+#    #+#             */
/*   Updated: 2022/01/24 19:44:17 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static void	*free_all(char **new, long long int max)
{
	long long int	i;

	i = 0;
	free(new[max]);
	while (new[i])
	{
		free(new[i]);
		i++;
	}
	free(new);
	return (NULL);
}	

static int	skip_c(long long int i, char const *s, char c)
{
	while (s[i] == c && s[i] != '\0')
		i++;
	return (i);
}

static long long int	arr_count_counter(const char *s, \
			long long int i, char c)
{
	long long int	arr_count;

	if (s[i] != c && s[i])
		arr_count = 1;
	else
		arr_count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			i = skip_c(i, s, c);
			if (s[i] != c && s[i] != '\0')
				arr_count++;
		}
		if (s[i] != '\0')
			i++;
	}
	return (arr_count);
}

static char	**ft_main_logic(long long int arr_count, \
			const char *s, char c, char **new)
{
	long long int	ii;
	long long int	iii;
	long long int	i;

	ii = 0;
	new[0] = NULL;
	iii = 1;
	i = skip_c(0, s, c);
	while (arr_count >= iii)
	{
		ii = 0;
		while (s[i] != c && s[i] != '\0')
		{	
			ii++;
			i++;
		}
		new[iii] = malloc(sizeof(char) * (ii + 1));
		if (new[iii] == NULL)
			return (free_all(new, arr_count));
		ft_strlcpy(new[iii], &s[i - ii], ii + 1);
		iii++;
		i = skip_c(i, s, c);
	}
	return (new);
}

const char	**ft_split(char const *s, char c, int *argc)
{
	long long int	i;
	long long int	arr_count;
	char			**new;

	if (s == NULL)
		return (NULL);
	i = 0;
	i = skip_c(i, s, c);
	arr_count = arr_count_counter(s, i, c);
	new = (char **)malloc(sizeof(char *) * (arr_count + 2));
	if (new == NULL)
		return (NULL);
	*argc = (int)arr_count + 1;
	new[arr_count] = NULL;
	new = ft_main_logic(arr_count, s, c, new);
	return ((const char **)new);
}
