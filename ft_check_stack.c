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

//take content at position of lst
int	ft_checknode(t_stack *lst, int pos)
{
	while (pos-- > 0)
		lst = lst->next;
	return (lst->content);
}

//this function count the size of stack
int	ft_stacksize(t_stack *stack)
{
	t_stack	*temp;
	int		i;

	if (!stack)
		return (0);
	temp = stack->next;
	i = 1;
	while (temp != stack)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

//search the less num in array iny
int	ft_checklessnum(int *arr, int len)
{
	int	res;

	res = arr[len];
	while (len >= 0)
	{
		if (arr[len] < res)
			res = arr[len];
		len--;
	}
	return (res);
}

//index of stack if rra negative
int	ft_checkindex(t_stack *b, int n, int len)
{
	int	i;
	t_stack	*start;

	if (len <= 1)
		return (0);
	start = b;
	i = -1;
	while(++i < len / 2)
	{
		if(b->content == n)
			return(i);
		b = b->next;
	}
	i = 0;
	b = start;
	while(len-- > 0)
	{
		i--;
		if(b->content == n)
			return(i);
		b = b->prev;
	}
	return(i);
}
//this function check order of stack
int	ft_checkorder(t_stack *stack)
{
	t_stack *temp;
	
	temp = stack->prev;
	while (stack != temp)
	{
		if (stack->content > stack->next->content)
			return (1);
		stack = stack->next;
	}
	return (0);
}