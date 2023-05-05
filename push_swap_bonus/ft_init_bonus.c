/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:39:06 by cschiavo          #+#    #+#             */
/*   Updated: 2023/05/05 11:09:00 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

//check if number is not a int
int	ft_check_is_int(char *str)
{
	long int	res;
	int			i;
	int			sign;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	res *= sign;
	if (res < -2147483648 || res > 2147483647)
		return (1);
	return (0);
}

//check continue is int
int	ft_continue_check_is_int(int argc, char **str)
{
	int	i;

	i = 0;
	while (i < argc)
		if (ft_check_is_int(str[i++]))
			return (1);
	return (0);
}

//  initialize stacks
void	ft_init(int *argc, char **argv, t_bool *noarray, char ***temp)
{
	*temp = argv + 1;
	*argc -= 1;
	*noarray = FALSE;
	if (*argc == 0)
		exit (0);
	if (*argc == 1)
	{
		*temp = ft_checkarr(argc, **temp);
		*noarray = TRUE;
	}
	if (ft_checkarg(*argc, *temp) || ft_continue_check_is_int(*argc, *temp) \
	|| ft_checknum(*argc, *temp) || ft_strlarg(*argc, *temp) || !**temp)
	{
		if (**temp)
			write(2, "error\n", 6);
		if (*noarray == TRUE)
			ft_freematrix(*temp);
		exit (0);
	}
}
