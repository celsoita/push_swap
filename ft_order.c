/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:53:45 by cschiavo          #+#    #+#             */
/*   Updated: 2023/05/03 17:31:11 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Order number with basic mv rev 
void	ft_order_b_asic_r(int i, int len, t_stack **a, t_stack **b)
{
	i = len;
	while (i > 0)
	{
		if ((*a)->content > ft_checknode(*b, i) && \
		(*a)->content < ft_checknode(*b, i - 1))
		{
			while (i++ < len)
				ft_rrotate(b, 'b');
			ft_push(a, b, 'b');
			return ;
		}
		i--;
	}
}

// Order number with basic mv
void	ft_order_b_asic(int i, int len, t_stack **a, t_stack **b)
{
	while (i < len / 2)
	{
		if ((*a)->content > ft_checknode(*b, i) && \
		(*a)->content < ft_checknode(*b, i - 1))
		{
			while (i-- > 0)
				ft_rotate(b, 'b');
			ft_push(a, b, 'b');
			return ;
		}
		i++;
	}
	if (i)
		ft_order_b_asic_r(i, len, a, b);
}

// Order with best actions
void	ft_order_b(t_stack **a, t_stack **b, int len)
{
	if ((*a)->content < ft_less_stack_n(*b))
	{
		while (ft_checkindex(*b, ft_less_stack_n(*b), len) > -1)
			ft_rotate(b, 'b');
		while (ft_checkindex(*b, ft_less_stack_n(*b), len) < -1)
			ft_rrotate(b, 'b');
		ft_push(a, b, 'b');
		return ;
	}
	if ((*a)->content > ft_bigger_stack_n(*b))
	{
		while (ft_checkindex(*b, ft_bigger_stack_n(*b), len) > 0)
			ft_rotate(b, 'b');
		while (ft_checkindex(*b, ft_bigger_stack_n(*b), len) < 0)
			ft_rrotate(b, 'b');
		ft_push(a, b, 'b');
		return ;
	}
	ft_order_b_asic(0, len, a, b);
}

// Push better number rr
void	ft_push_better_both(int ma, int mb, t_all *all, int n)
{
	if (ft_stacksize(all->a) > 1)
	{
		ma = all->mov_a[ft_check_content_pos(all->a, n) - 1];
		mb = all->mov_b[ft_check_content_pos(all->a, n) - 1];
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
}

// Push better number
void	ft_push_better(t_all *all, int n)
{
	ft_push_better_both(0, 0, all, n);
	while (ft_checkindex(all->a, n, ft_stacksize(all->a)) > 0)
		ft_rotate(&all->a, 'a');
	while (ft_checkindex(all->a, n, ft_stacksize(all->a)) < 0)
		ft_rrotate(&all->a, 'a');
	ft_order_b(&all->a, &all->b, ft_stacksize(all->b));
}
