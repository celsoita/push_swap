/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculatemv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:13:37 by cschiavo          #+#    #+#             */
/*   Updated: 2023/05/03 17:52:50 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// this function is a support for ft_countmva
int	ft_calculatemv(t_stack *a, t_stack *b)
{
	return (ft_checkindex(b, \
	ft_search_higher_to_n(b, a->content), ft_stacksize(b)) + 1);
}
