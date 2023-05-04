/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculatemv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:13:37 by cschiavo          #+#    #+#             */
/*   Updated: 2023/05/04 11:04:35 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (ft_check_is_int(str[++i]))
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
	if (ft_checkarg(*argc, *temp) || ft_continue_check_is_int(*argc, argv) \
	|| ft_checknum(*argc, *temp) || ft_strlarg(*argc, *temp))
	{
		ft_printf("error\n");
		if (*noarray == TRUE)
			ft_freematrix(*temp);
		exit (0);
	}
}

// algo for less six numbers
void	ft_less_six_numbers(t_all *all)
{
	if (all->len < 4)
		ft_minialgo(&all->a, all->len);
	if (all->len == 5)
	{
		while (all->a->content != ft_check_less_content(all->a))
		{
			if (ft_check_content_pos(all->a, ft_check_less_content(all->a)) < 3)
				ft_rotate(&all->a, 'a');
			else
				ft_rrotate(&all->a, 'a');
		}
		if (ft_checkorder(all->a))
			ft_push(&all->a, &all->b, 'b');
	}
	if (all->len > 3)
		ft_algofoure(all);
	if (all->len == 5 && ft_stacksize(all->b))
		ft_push(&all->b, &all->a, 'a');
}

// algo for more five numbers
void	ft_more_five_numbers(t_all *all)
{
	ft_push(&all->a, &all->b, 'b');
	ft_push(&all->a, &all->b, 'b');
	while (all->a)
	{
		all->mov_b = ft_countmva(all->a, all->b, ft_stacksize(all->a));
		all->mov_a = ft_countmvb(ft_stacksize(all->a));
		ft_push_better(all, ft_convertmv(all));
		free(all->mov_b);
		free(all->mov_a);
	}
	ft_order_stack(&all->b, TRUE, 'b');
	while (all->b)
		ft_push(&all->b, &all->a, 'a');
}
