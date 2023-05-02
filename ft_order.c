/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:58:57 by cschiavo          #+#    #+#             */
/*   Updated: 2023/05/02 16:50:23 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//search bigger than n 
int	ft_search_big(t_stack *a, int n)
{
	int	pos;

	pos = ft_check_content_pos(a, ft_less_stack_n(a));
	while (pos--)
		a = a->next;
	while (a->content < n)
		a = a->next;
	pos = ft_check_content_pos(a, a->prev->content);
	return (pos);
}

void	ft_order_ascendent(t_all *l, int c)
{
	while (1)
	{
		if (c > l->a->prev->content && c < l->a->content)
		{
			while (ft_checkindex(l->b, c, ft_stacksize(l->b)) > 0)
				ft_rotate(&l->b, 'b');
			while (ft_checkindex(l->b, c, ft_stacksize(l->b)) < 0)
				ft_rrotate(&l->b, 'b');
			ft_push(&l->b, &l->a, 'a');
			// ft_swap(l->a, 'a');
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
		while (ft_bigger_stack_n(l->a) != l->a->prev->content)
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
		// ft_swap(l->a, 'a');
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
	if (ft_search_big(l->a, c) < len / 2)
		ft_order_ascendent(l, c);
	else
		ft_order_descendent(l, c);
}
