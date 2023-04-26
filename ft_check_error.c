/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:10:56 by cschiavo          #+#    #+#             */
/*   Updated: 2023/04/14 12:10:56 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//if the char is present in array
//return 1 u can use it for comparison with - || +
int	ft_char_in_array(char c, char *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

//check double number
int	ft_checkarg(int argc, char **argv)
{
	int	c;
	int	*arr;
	int	n;
	int	i;

	c = 0;
	i = 0;
	arr = malloc(sizeof(int) * argc);
	while (c < argc)
	{
		n = ft_atoi(argv[c]);
		arr[c] = n;
		i = c++ - 1;
		while (i >= 0)
		{
			if (arr[i--] == n)
			{
				free(arr);
				return (1);
			}
		}
	}
	free(arr);
	return (0);
}

//check arg for see in are only number
int	ft_checknum(int argc, char **argv)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (c < argc)
	{
		i = 0;
		while (argv[c][i])
		{
			while (ft_isdigit(argv[c][i]))
				i++;
			if (i > 0 && (argv[c][i] == '-' || argv[c][i] == '+'))
				return (1);
			if (argv[c][i])
				i++;
		}	
		c++;
	}
	return (0);
}

//this function check if present in array  "-" " +"
int	ft_strlarg(int argc, char **str)
{
	int	j;
	int	i;
	int	k;

	j = 0;
	k = 0;
	while (k < argc)
	{
		i = 0;
		if (ft_char_in_array(str[k][i], "-+") && \
		!ft_char_in_array(str[k][i + 1], "-+") && str[k][i + 1])
			i++;
		while (str[k][i] >= '0' && str[k][i] <= '9')
			i++;
		if (i > 0)
			j++;
		k++;
	}
	if (j == argc)
		return (0);
	return (1);
}

//this function is a check for accept  
//the string and create a matrix for it for example " 1 2 3" be a "1" "2" "3"
char	**ft_checkarr(int *argc, char *str)
{
	char	**res;
	int		i;

	res = ft_split(str, ' ');
	i = 0;
	while (res[i])
		i++;
	*argc = i;
	return (res);
}
