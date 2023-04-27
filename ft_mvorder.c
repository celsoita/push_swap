/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mvorder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:14:29 by cschiavo          #+#    #+#             */
/*   Updated: 2023/04/27 21:16:01 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_order_b(t_stack **a, t_stack **b, int len)
{
	int	i;

	if ((*a)->content < (*b)->prev->content)
	{
		ft_push(a, b, 'b');
		ft_rotate(b, 'b');
		return ;
	}
	if ((*a)->content > (*b)->content)
	{
		ft_push(a, b, 'b');
		return ;
	}
	i = 0;
	while (i < len / 2)
	{
		if ((*a)->content > ft_checknode(*b, i) && (*a)->content < ft_checknode(*b, i - 1))
		{
			while (i-- > 0)
				ft_rotate(b, 'b');
			ft_push(a, b, 'b');
			return ;
		}
		i++;
	}
	if (i)
	{
		i = len;
		while (i > 0)
		{
			if ((*a)->content > ft_checknode(*b, i) && (*a)->content < ft_checknode(*b, i - 1))
			{
				while (i++ < len)
					ft_rrotate(b, 'b');
				ft_push(a, b, 'b');
				return ;
			}
			i--;
		}
	}
}

//this function check the number in stack and push
// the element not in order in b ... remaining stack a in order
void	ft_pushorder(int *alg, t_all *stack, int arr_len)
{
	int	i;
	int	k;
	int	number;

	i = 0;
	k = 0;
	number = alg[i];
	while (k < stack->len)
	{
		if (number != stack->a->content)
		{	
			if (ft_stacksize(stack->b) > 1)
			{
				ft_order_b(&stack->a, &stack->b, ft_stacksize(stack->b));
				ft_order_stack(&stack->b, 1, 'b');
			}
			else
				ft_push(&stack->a, &stack->b, 'b');
		}
		else
		{
			ft_rotate(&stack->a, 'a');
			i++;
			if (i < arr_len)
				number = alg[i];
		}
		k++;
	}
}

// function countmovement for push element in right order
int	*ft_countmva(t_stack *a, t_stack *b, int len)
{
	t_stack	*startb;
	int		*res;
	int		k;

	k = 0;
	startb = b;
	res = malloc(sizeof(int) * len);
	while (startb != b->next)
	{
		res[k++] = ft_calculatemv(a, b, a, len);
		b = b->next;
	}
	res[k] = ft_calculatemv(a, b, a, len);
	return (res);
}

// this function count the movement necessary
//for move the element in the first position
int	*ft_countmvb(int len)
{
	int	*res;
	int	c;
	int	i;

	res = malloc(sizeof(int) * len);
	i = 0;
	c = 0;
	while (c < len / 2)
		res[i++] = c++;
	while (c < len)
		res[i++] = c++ - len;
	return (res);
}

void	ft_convertmv_ordinate(int *naction, int start, t_all *stacks)
{
	int	i;

	i = 0;
	while (naction[i] != start)
		i++;
	start = 0;
	while (start++ < i)
	{
		if (stacks->mov_b[i] < 0)
			ft_rrotate(&stacks->b, 'b');
		else
			ft_rotate(&stacks->b, 'b');
	}
}

//this function convert count in mv
int	ft_convertmv(t_all *stacks)
{
	int	i;
	int	len;
	int	*naction;
	int	start;

	len = ft_stacksize(stacks->b);
	naction = malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		if (stacks->mov_b[i] < 0)
			naction[i] = stacks->mov_a[i] + (-stacks->mov_b[i]);
		else
			naction[i] = stacks->mov_a[i] + stacks->mov_b[i];
		i++;
	}
	start = ft_checklessnum(naction, len - 1);
	i = 0;
	while(naction[i] != start)
		i++;
	//ft_convertmv_ordinate(naction, start, stacks);
	free(naction);
	return (ft_checknode(stacks->b, i));
}
