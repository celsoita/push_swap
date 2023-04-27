/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:58:57 by cschiavo          #+#    #+#             */
/*   Updated: 2023/04/26 20:55:54 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_order_ascendent(t_all *l, int c)
{
	while (1)
	{
		if (c > l->a->content && c < l->a->next->content)
		{
			while (ft_checkindex(l->b, c, ft_stacksize(l->b)) > 0)
				ft_rotate(&l->b, 'b');
			while (ft_checkindex(l->b, c, ft_stacksize(l->b)) < 0)
				ft_rrotate(&l->b, 'b');
			ft_push(&l->b, &l->a, 'a');
			ft_swap(l->a, 'a');
			break ;
		}
		if (ft_checkindex(l->b, c, ft_stacksize(l->b)) > 0)
			ft_rr_rotate(&l->a, &l->b);
		else
		{
			if (ft_checkindex(l->b, c, ft_stacksize(l->b)) < 0)
				ft_rrotate(&l->b, 'b');
			ft_rotate(&l->a, 'a');
		}
	}
}

void	ft_order_descendent(t_all *l, int c)
{
	while (1)
	{
		if (l->a->content > c && l->a->prev->content < c)
		{
			while (ft_checkindex(l->b, c, ft_stacksize(l->b)) > 0)
				ft_rotate(&l->b, 'b');
			while (ft_checkindex(l->b, c, ft_stacksize(l->b)) < 0)
				ft_rrotate(&l->b, 'b');
			ft_push(&l->b, &l->a, 'a');
			break ;
		}
		if (ft_checkindex(l->b, c, ft_stacksize(l->b)) < 0)
			ft_rrr_rrotate(&l->a, &l->b);
		else
		{
			if (ft_checkindex(l->b, c, ft_stacksize(l->b)) > 0)
				ft_rotate(&l->b, 'b');
			ft_rrotate(&l->a, 'a');
		}
	}
}

void	ft_order(t_all *l, int len, int c)
{
	if (ft_bigger_stack_n(l->a) < c)
	{
		while (ft_checkindex(l->a, ft_bigger_stack_n(l->a), len) > 0)
		{
			if (l->b->content != c && ft_checkindex(l->b, c, ft_stacksize(l->b)) > 0)
				ft_rr_rotate(&l->a, &l->b);
			else
				ft_rotate(&l->a, 'a');
		}
		while (ft_checkindex(l->a, ft_bigger_stack_n(l->a), len) < 0)
		{
			if (l->b->content != c && ft_checkindex(l->b, c, ft_stacksize(l->b)) < 0)
				ft_rrr_rrotate(&l->a, &l->b);
			else
				ft_rrotate(&l->a, 'a');
		}
		while (ft_checkindex(l->b, c, ft_stacksize(l->b)) > 0)
			ft_rotate(&l->b, 'b');
		while (ft_checkindex(l->b, c, ft_stacksize(l->b)) < 0)
			ft_rrotate(&l->b, 'b');
		ft_push(&l->b, &l->a, 'a');
		ft_swap(l->a, 'a');
		return ;
	}
	if (ft_less_stack_n(l->a) > c)
	{
		while (ft_checkindex(l->a, ft_less_stack_n(l->a), len) > 0)
		{
			if (l->b->content != c && ft_checkindex(l->b, c, ft_stacksize(l->b)) > 0)
				ft_rr_rotate(&l->a, &l->b);
			else
				ft_rotate(&l->a, 'a');
		}
		while (ft_checkindex(l->a, ft_less_stack_n(l->a), len) < 0)
		{
			if (l->b->content != c && ft_checkindex(l->b, c, ft_stacksize(l->b)) < 0)
				ft_rrr_rrotate(&l->a, &l->b);
			else
				ft_rrotate(&l->a, 'a');
		}
		while (ft_checkindex(l->b, c, ft_stacksize(l->b)) > 0)
			ft_rotate(&l->b, 'b');
		while (ft_checkindex(l->b, c, ft_stacksize(l->b)) < 0)
			ft_rrotate(&l->b, 'b');
		ft_push(&l->b, &l->a, 'a');
	
		return ;
	}
	if (ft_checknode(l->a, len / 2) > l->b->content)
		ft_order_ascendent(l, c);
	else
		ft_order_descendent(l, c);
}
