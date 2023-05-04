/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oprotate_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:19:35 by cschiavo          #+#    #+#             */
/*   Updated: 2023/05/04 16:15:38 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

// this function rotate stack 
void	ft_rotate(t_stack **lst)
{
	if (!*lst || (*lst)->next == *lst)
		return ;
	*lst = (*lst)->next;
}

// this function rotate stack in reverse order
void	ft_rrotate(t_stack **lst)
{
	if (!*lst || (*lst)->prev == *lst)
		return ;
	*lst = (*lst)->prev;
}

// this function rotate both stacks
void	ft_rr_rotate(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	ft_rotate(b);
}

// this function  reverse rotate both stacks
void	ft_rrr_rrotate(t_stack **a, t_stack **b)
{
	ft_rrotate(a);
	ft_rrotate(b);
}
