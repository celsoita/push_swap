/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 09:14:37 by cschiavo          #+#    #+#             */
/*   Updated: 2023/05/03 16:22:04 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//this function push better number
void	ft_push_better(t_all *all, int n)
{
	int	ma;
	int	mb;

	if (ft_stacksize(all->a) > 1)
	{
		ma = all->mov_a[ft_check_content_pos(all->a, n) - 1];
		mb = all->mov_b[ft_check_content_pos(all->a, n) - 1];
	}
	else
	{
		mb = 0;
		ma = 0;
	}
	while (ma < 0 && mb < 0)
	{
		ft_rrr_rrotate(&all->a, &all->b);
		ma++;
		mb++;
	}
	while (ma > 1 && mb > 0)
	{
		ft_rr_rotate(&all->a, &all->b);
		ma--;
		mb--;
	}
	while (ft_checkindex(all->a, n, ft_stacksize(all->a)) > 0)
		ft_rotate(&all->a, 'a');
	while (ft_checkindex(all->a, n, ft_stacksize(all->a)) < 0)
		ft_rrotate(&all->a, 'a');
	ft_order_b(&all->a, &all->b, ft_stacksize(all->b));
}

void	ft_order_stack(t_stack **s, int rev, char c)
{
	int	len;

	len = ft_stacksize(*s);
	if (!rev)
	{
		if (ft_checkindex(*s, ft_less_stack_n(*s), len) < len / 2)
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
		if (ft_check_content_pos(*s, ft_less_stack_n(*s)) < len / 2)
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
			// t_bool	bigger_n;

			// bigger_n = FALSE;
			// arr = ft_algorithm(all.a, argc, &argc);
			// if (all.a->content == ft_bigger_stack_n(all.a))
			// {
			// 	ft_rotate(&all.a, 'a');
			// 	bigger_n = TRUE;
			// }
			ft_push(&all.a, &all.b, 'b');
			// if (all.a->content == ft_bigger_stack_n(all.a))
			// {
			// 	ft_rotate(&all.a, 'a');
			// 	bigger_n = TRUE;
			// }
			ft_push(&all.a, &all.b, 'b');
			while (all.a)
			{
				// if (all.a->content == ft_bigger_stack_n(all.a))
				// {
				// 	ft_rotate(&all.a, 'a');
				// 	bigger_n = TRUE;
				// }
				all.mov_b = ft_countmva(all.a, all.b, ft_stacksize(all.a));
				all.mov_a = ft_countmvb(ft_stacksize(all.a));
				ft_push_better(&all, ft_convertmv(&all));
				free(all.mov_b);
				free(all.mov_a);
			}
			ft_order_stack(&all.b, 1, 'b');
			while (all.b)
				ft_push(&all.b, &all.a, 'a');
			// ft_pushorder(arr, &all, ft_stacksize(all.a));
			//ft_printf("STACK A:\n");
			//ft_printstack_new(all.a);
			//ft_printf("STACK B:\n");
			//ft_printstack_new(all.b);
			// while (all.b)
			// {
			// 	all.mov_b = ft_countmvb(ft_stacksize(all.b));
			// 	all.mov_a = ft_countmva(all.a, all.b, ft_stacksize(all.b));
			// 	// ft_printf("\nstack A:\n");
			// 	// ft_printstack_new(all.a);
			// 	// ft_printf("STACK B:\n");
			// 	// ft_printstack_new(all.b);
			// 	ft_order(&all, ft_stacksize(all.a), ft_convertmv(&all));
			// 	free(all.mov_b);
			// 	free(all.mov_a);
			// }
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
