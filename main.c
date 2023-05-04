/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 09:14:37 by cschiavo          #+#    #+#             */
/*   Updated: 2023/05/04 10:02:00 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_all	all;
	char	**temp;
	t_bool	noarray;

	ft_init(&argc, argv, &noarray, &temp);
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
