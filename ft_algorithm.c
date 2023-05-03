/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:54:19 by cschiavo          #+#    #+#             */
/*   Updated: 2023/05/03 16:46:49 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Order stack s:
	rev = TRUE: Reverse
*/
void	ft_order_stack(t_stack **s, t_bool rev, char c)
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

// Order for 4 numbers
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

// mini algorithm for 2/3 number in stack
void	ft_minialgo(t_stack **a, int len)
{
	if (len == 2)
	{
		if ((*a)->content > (*a)->next->content)
			ft_swap(*a, 'a');
	}
	else
	{
		if ((*a)->content > (*a)->prev->content && \
		(*a)->content > (*a)->next->content && \
		(*a)->next->content < (*a)->prev->content)
			ft_rotate(a, 'a');
		if ((*a)->content < (*a)->next->content && \
		(*a)->prev->content < (*a)->next->content)
			ft_rrotate(a, 'a');
		if ((*a)->content < (*a)->prev->content && \
		(*a)->next->content > (*a)->prev->content)
			ft_rrotate(a, 'a');
		if ((*a)->content > (*a)->next->content && \
		(*a)->prev->content < (*a)->next->content)
			ft_rotate(a, 'a');
		if ((*a)->content < (*a)->prev->content && \
		(*a)->content > (*a)->next->content)
			ft_swap(*a, 'a');
	}
}
