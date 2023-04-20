/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculatemv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:13:37 by cschiavo          #+#    #+#             */
/*   Updated: 2023/04/20 15:56:22 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_calculatemv_ascendent(t_stack *a, t_stack *b, int len, t_stack *start)
{
	int	i;

	i = 0;
	while (1)
	{
		if (a->content < b->content && a->next->content > b->content)
		{
			i += 2;
			break ;
		}
		a = a->next;
		i += 2;
		if (i / 2 > len / 2)
		{
			i = 0;
			a = start;
			break ;
		}
	}
	return (i);
}

int	ft_calculatemv_discendent(int temp, t_stack *a, t_stack *b, int i)
{
	while (temp-- > 0)
	{
		if (a->content < b->content && a->next->content > b->content)
		{
			i += 2;
			break ;
		}
		a = a->prev;
		i += 2;
	}
	if (temp < 0)
		i = 2;
	return (i);
}

// this function is a support for ft_countmva
int	ft_calculatemv(t_stack *a, t_stack *b, t_stack *start, int temp)
{
	int	i;
	int	len;

	len = temp;
	i = 0;
	if (a->content > b->content)
		i = 1;
	else
	{
		i = ft_calculatemv_ascendent(a, b, len, start);
		if (!i)
			i = ft_calculatemv_discendent(temp, a, b, i);
	}
	return (i);
}
