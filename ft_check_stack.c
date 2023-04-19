/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:08:31 by cschiavo          #+#    #+#             */
/*   Updated: 2023/04/19 21:08:31 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//this function count the size of stack
int	ft_stacksize(t_stack *stack)
{
	t_stack *temp;
	int 	i;
	temp = stack->next;
	i = 1;
	while(temp != stack)
	{
		temp = temp->next;
		i++; 
	}
	return(i);
}

//search the less num in array iny
int	ft_checklessnum(int *arr,int len)
{
	int	res;

	res = arr[len];
	while(len >= 0)
	{
		if(arr[len] < res)
			res = arr[len];
		len--;	
	}
	return(res);
}

void	ft_order(t_stack **a, t_stack **b, int len)
{
	int	i;

	i = 0;
	if((*b)->content > (*a)->prev->content)
	{
		ft_push(b,a,'a');
		ft_rotate(a,'a');
		return ;
	}
	if((*b)->content < (*a)->content)
	{
		ft_push(b,a,'a');
		return ;
	}
	if(ft_checknode(*a,len/2) > (*b)->content)
	{
		while(i < len)
		{
			if((*b)->content > (*a)->content && (*b)->content < (*a)->next->content)
			{
				ft_push(b,a,'a');
				ft_swap(*a,'a');
				break;
			}	
			ft_rotate(a,'a');
			i++;
		}
		while(i--)
			ft_rrotate(a,'a');
	}
	else
	{
		i = 1;
		while(i < len)
		{
			if((*a)->content > (*b)->content && (*a)->prev->content < (*b)->content)
			{
				ft_push(b,a,'a');
				break ;
			}
			ft_rrotate(a,'a');
			i++;
		}
		while(i--)
			ft_rotate(a,'a');
	}
}