/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 09:14:37 by cschiavo          #+#    #+#             */
/*   Updated: 2023/04/20 15:56:24 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_order_stack(t_stack **a)
{
	
}
int	main(int argc, char **argv)
{
	t_all	all;
	char	**temp;
	int		*arr;
	char	noarray;	

	temp = argv + 1;
	argc--;
	noarray = 0;
	if (argc == 1)
	{
		temp = ft_checkarr(&argc,*temp);
		noarray = 1;
	}
	if (argc <= 0 || ft_checkarg(argc, temp) \
	|| ft_checknum(argc, temp) || ft_strlarg(argc, temp))
	{
		ft_printf("error\n");
		if (noarray == 1)
			ft_freematrix(temp);
		return (0);
	}
	all.len = argc;
	all.a = ft_createstack(argc, temp);
	all.b = NULL;
	ft_printf("STACK A:\n");
	ft_printstack_new(all.a);
	arr = 0;
	if (all.len < 4)
		ft_minialgo(&all.a, all.len);
	else
	{
		arr = ft_algorithm(all.a, argc, &argc);
		ft_pushorder(arr, &all, argc);
		ft_printf("STACK A:\n");
		ft_printstack_new(all.a);
		ft_printf("STACK B:\n");
		ft_printstack_new(all.b);
		while (all.b)
		{
			all.mov_b = ft_countmvb(ft_stacksize(all.b));
			all.mov_a = ft_countmva(all.a, all.b, ft_stacksize(all.b));
			ft_convertmv(&all);
			ft_printf("\nstack A:\n");
			ft_printstack_new(all.a);
			ft_printf("STACK B:\n");
			ft_printstack_new(all.b);
			ft_order(&all.a, &all.b, ft_stacksize(all.a), all.mov_b);
			free(all.mov_b);
			free(all.mov_a);
		}
		
	}	
	ft_printf("STACK A:\n");
	ft_printstack_new(all.a);
	ft_free_lst(&all.a);
	ft_free_lst(&all.b);
	if (noarray == 1)
		ft_freematrix(temp);
	if (arr)
		free(arr);
}
