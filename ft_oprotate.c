/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oprotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:19:35 by cschiavo          #+#    #+#             */
/*   Updated: 2023/04/20 12:18:02 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// this function rotate stack 
void	ft_rotate(t_stack **lst, char name)
{
	if (!*lst || (*lst)->next == *lst)
		return ;
	*lst = (*lst)->next;
	if (!name)
		return ;
	ft_printf("r%c\n", name);
}

// this function rotate stack in reverse order
void	ft_rrotate(t_stack **lst, char name)
{
	if (!*lst || (*lst)->prev == *lst)
		return ;
	*lst = (*lst)->prev;
	if (!name)
		return ;
	ft_printf("rr%c\n", name);
}

// this function rotate both stacks
void	ft_rr_rotate(t_all *lst)
{
	ft_rotate(&lst->a, 0);
	ft_rotate(&lst->b, 0);
	ft_printf("rr\n");
}

// this function  reverse rotate both stacks
void	ft_rrr_rrotate(t_all *lst)
{
	ft_rrotate(&lst->a, 0);
	ft_rrotate(&lst->b, 0);
	ft_printf("rrr\n");
}
