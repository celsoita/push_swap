/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 09:14:37 by cschiavo          #+#    #+#             */
/*   Updated: 2023/04/27 20:14:14 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_order_stack(t_stack **s, int rev, char c)
{
	int	i;

	i = 0;
	if (!rev)
	{
		while (ft_checknode(*s, i) > ft_checknode(*s, i + 1))
			i++;
		if (i < ft_stacksize(*s) / 2)
		{
			while ((*s)->content > (*s)->prev->content)
				ft_rotate(s, c);
		}
		else
			while ((*s)->content > (*s)->prev->content)
				ft_rrotate(s, c);
	}
	if (rev)
	{
		while (ft_checknode(*s, i) < ft_checknode(*s, i + 1))
			i++;
		if (i < ft_stacksize(*s) / 2)
		{
			while ((*s)->content < (*s)->prev->content)
				ft_rotate(s, c);
		}
		else
			while ((*s)->content < (*s)->prev->content)
				ft_rrotate(s, c);
	}
}

void	ft_algofoure(t_all *stacks)
{
	int	i;
	
	i = ft_check_less_content(stacks->a);
	while (stacks->a->content != i)
	{
		if (ft_check_content_pos(stacks->a, i) < 3)
			ft_rotate(&stacks->a, 'a');
		else
			ft_rrotate(&stacks->a, 'a');
	}
	if (ft_checkorder(stacks->a))
	{
		ft_push(&stacks->a, &stacks->b, 'b');
		ft_minialgo(&stacks->a, 3);
		ft_push(&stacks->b, &stacks->a, 'a');
	}
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
	arr = 0;
	// ft_printf("STACK A:\n");
	// ft_printstack_new(all.a);
	if (ft_checkorder(all.a) == 1)
	{
		if (all.len < 6)
		{
			if (all.len < 4)
				ft_minialgo(&all.a, all.len);
			if (all.len == 5)
			{
				while(all.a->content != ft_check_less_content(all.a))
				{
					if (ft_check_content_pos(all.a, ft_check_less_content(all.a)) < 3)
						ft_rotate(&all.a, 'a');
					else
						ft_rrotate(&all.a, 'a');
				}
				if (ft_checkorder(all.a))
					ft_push(&all.a, &all.b, 'b');
			}
			if (all.len > 3)
				ft_algofoure(&all);
			if (all.len == 5 && ft_stacksize(all.b))
				ft_push(&all.b, &all.a, 'a');
		}
		else
		{
			arr = ft_algorithm(all.a, argc, &argc);
			ft_pushorder(arr, &all, argc);
			//ft_printf("STACK A:\n");
			//ft_printstack_new(all.a);
			//ft_printf("STACK B:\n");
			//ft_printstack_new(all.b);
			while (all.b)
			{
				all.mov_b = ft_countmvb(ft_stacksize(all.b));
				all.mov_a = ft_countmva(all.a, all.b, ft_stacksize(all.b));
				// ft_printf("\nstack A:\n");
				// ft_printstack_new(all.a);
				// ft_printf("STACK B:\n");
				// ft_printstack_new(all.b);
				ft_order(&all, ft_stacksize(all.a), ft_convertmv(&all));
				free(all.mov_b);
				free(all.mov_a);
			}
			ft_order_stack(&all.a, 0, 'a');
		}
	}	
	// ft_printf("STACK A:\n");
	// ft_printstack_new(all.a);
	ft_free_lst(&all.a);
	ft_free_lst(&all.b);
	if (noarray == 1)
		ft_freematrix(temp);
	if (arr)
		free(arr);
}
