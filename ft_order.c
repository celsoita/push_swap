/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:58:57 by cschiavo          #+#    #+#             */
/*   Updated: 2023/04/20 15:56:28 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_order_ascendent(int i, int len, t_all *l)
{
	int	c;
	
	c = 4;
	while (i < len)
	{
		if (c > l->a->content && c < l->a->next->content)
		{
			while (l->b->content != c)
				ft_rotate(l->b, 'b');
			ft_push(l->b, l->a, 'a');
			ft_swap(l->a, 'a');
			break ;
		}
		if(l->b->content != c && l->mov_b[c] > 0)
			ft_rr_rotate(l->a, l->b);
		else
			ft_rotate(l->a, 'a');
		i++;
	}
	// while (i--)
	// 	ft_rrotate(a, 'a');
}

void	ft_order_descendent(int i, int len, t_all *l)
{
	while (i < len)
	{
		if (l->a->content > l->b->content \
		&& l->a->prev->content < l->b->content)
		{
			ft_push(l->b, l->a, 'a');
			break ;
		}
		ft_rrotate(l->a, 'a');
		i++;
	}
	// while (i--)
	// 	ft_rotate(a, 'a');
}

void	ft_order(t_all *l, int len)
{
	int	i;

	i = 0;
	if (l->b->content > l->a->prev->content && l->a->prev->content > l->a->content)
	{
		ft_push(l->b, l->a, 'a');
		ft_rotate(l->a, 'a');
		return ;
	}
	if (l->b->content < l->a->content)
	{
		ft_push(l->b, l->a, 'a');
		return ;
	}
	if (ft_checknode(l->a, len / 2) > l->b->content)
		ft_order_ascendent(i, len, l);
	else
		ft_order_descendent(1, len, l);
}
