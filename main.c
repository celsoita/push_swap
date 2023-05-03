/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 09:14:37 by cschiavo          #+#    #+#             */
/*   Updated: 2023/05/03 17:52:48 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// asdasd
int	ft_init(int *argc, char **argv, t_bool *noarray, char ***temp)
{
	*temp = argv + 1;
	*argc -= 1;
	*noarray = FALSE;
	if (*argc == 1)
	{
		*temp = ft_checkarr(argc, **temp);
		*noarray = TRUE;
	}
	if (*argc <= 0 || ft_checkarg(*argc, *temp) \
	|| ft_checknum(*argc, *temp) || ft_strlarg(*argc, *temp))
	{
		ft_printf("error\n");
		if (*noarray == TRUE)
			ft_freematrix(*temp);
		return (0);
	}
	return (1);
}

// asdadad
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

// asdsadas
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

int	main(int argc, char **argv)
{
	t_all	all;
	char	**temp;
	t_bool	noarray;	

	if (ft_init(&argc, argv, &noarray, &temp) == 0)
		return (0);
	all.len = argc;
	all.a = ft_createstack(argc, temp);
	all.b = NULL;
	if (ft_checkorder(all.a) == 1)
	{
		if (all.len < 6)
			ft_less_six_numbers(&all);
		else
			ft_more_five_numbers(&all);
	}
	ft_free_lst(&all.a);
	ft_free_lst(&all.b);
	if (noarray == TRUE)
		ft_freematrix(temp);
}
