/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculatemv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:13:37 by cschiavo          #+#    #+#             */
/*   Updated: 2023/05/03 15:58:13 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	ft_calculatemv_ascendent(t_stack *a, t_stack *b, int len, t_stack *start)
// {
// 	int	i;
//
// 	i = 0;
// 	while (1)
// 	{
// 		ft_checkindex(b, ft_search_higher_to_n(b, a->content), ft_stacksize(b));
// 		if (1)
// 		{
// 			i += 1;
// 			break ;
// 		}
// 		b = b->next;
// 		i += 1;
// 		if (i > len / 2)
// 			return (0);
// 	}
// 	return (i);
// }

// int	ft_calculatemv_discendent(int temp, t_stack *a, t_stack *b, int i)
// {
// 	while (temp-- > 0)
// 	{
// 		if (a->content < b->content && a->content > b->prev->content)
// 		{
// 			i -= 2;
// 			break ;
// 		}
// 		a = a->prev;
// 		i -= 1;
// 	}
// 	if (temp < 0)
// 		i = -2;
// 	return (i);
// }

// this function is a support for ft_countmva
int	ft_calculatemv(t_stack *a, t_stack *b)
{
	int	i;
	// int	len;

	// len = temp;
	i = ft_search_higher_to_n(b, a->content);
	i = ft_checkindex(b, i, ft_stacksize(b));
	if (i >= 0)
		i += 1;
	else
		i += 1;
	// i = ft_calculatemv_ascendent(a, b, len, start);
	// if (!i)
	// 	i = ft_calculatemv_discendent(temp, a, b, i);
	return (i);
}
