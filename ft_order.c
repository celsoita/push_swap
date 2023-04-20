/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:58:57 by cschiavo          #+#    #+#             */
/*   Updated: 2023/04/20 12:18:04 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_order_ascendent(int i, int len, t_stack **a, t_stack **b)
{
	while (i < len)
	{
		if ((*b)->content > (*a)->content \
		&& (*b)->content < (*a)->next->content)
		{
			ft_push(b, a, 'a');
			ft_swap(*a, 'a');
			break ;
		}	
		ft_rotate(a, 'a');
		i++;
	}
	while (i--)
		ft_rrotate(a, 'a');
}

void	ft_order_descendent(int i, int len, t_stack **a, t_stack **b)
{
	while (i < len)
	{
		if ((*a)->content > (*b)->content \
		&& (*a)->prev->content < (*b)->content)
		{
			ft_push(b, a, 'a');
			break ;
		}
		ft_rrotate(a, 'a');
		i++;
	}
	while (i--)
		ft_rotate(a, 'a');
}

void	ft_order(t_stack **a, t_stack **b, int len)
{
	int	i;

	i = 0;
	if ((*b)->content > (*a)->prev->content)
	{
		ft_push(b, a, 'a');
		ft_rotate(a, 'a');
		return ;
	}
	if ((*b)->content < (*a)->content)
	{
		ft_push(b, a, 'a');
		return ;
	}
	if (ft_checknode(*a, len / 2) > (*b)->content)
		ft_order_ascendent(i, len, a, b);
	else
		ft_order_descendent(1, len, a, b);
}
