/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:48:48 by cschiavo          #+#    #+#             */
/*   Updated: 2023/05/04 16:50:27 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	char	**temp;
	int		res;
	t_bool	noarray;
	t_all	all;

	ft_init(&argc, argv, &noarray, &temp);
	all.len = argc;
	all.a = ft_createstack(argc, temp);
	all.b = NULL;
	res = ft_check_op(&all);
	if (res == 1)
		write(1, "OK\n", 3);
	else if (res == 0)
		write(1, "KO\n", 3);
	else
		write(2, "error\n", 6);
	ft_free_lst(&all.a);
	ft_free_lst(&all.b);
	if (noarray == TRUE)
		ft_freematrix(temp);
}
