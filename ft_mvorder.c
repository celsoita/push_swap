/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mvorder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:14:29 by cschiavo          #+#    #+#             */
/*   Updated: 2023/04/19 16:26:13 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			ft_push(&stack->a, &stack->b, 'b');
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
		if (!i)
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
		}
	}
	return (i);
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

//this function convert count in mv
void	ft_convertmv(t_all *stacks)
{
	int	i;
	int	len;
	int	*naction;
	int	start;

	len = ft_stacksize(stacks->b);
	stacks->fmov_a = stacks->mov_a;
	stacks->fmov_b = stacks->mov_b;
	naction = malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		if (stacks->fmov_b[i] < 0)
			naction[i] = stacks->fmov_a[i] + (stacks->(-fmov_b[i]));
		else
			naction[i] = mov_a[i] + mov_b[i];
		i++;
	}
	start = ft_checklessnum(naction, len - 1);
	i = 0;
	while (naction[i] != start)
		i++;
	start = 0;
	while (start++ < i)
	{
		if (stacks->fmov_b[i] < 0)
			ft_rrotate(&stacks->b, 'b');
		else
			ft_rotate(&stacks->b, 'b');
	}
	free(naction);
}