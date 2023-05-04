/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mvorder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:14:29 by cschiavo          #+#    #+#             */
/*   Updated: 2023/05/04 10:43:05 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// function countmovement for push element in right order
int	*ft_countmva(t_stack *a, t_stack *b, int len)
{
	t_stack	*starta;
	int		*res;
	int		k;

	k = 0;
	starta = a;
	res = malloc(sizeof(int) * len);
	while (starta != a->next)
	{
		res[k++] = ft_checkindex(b, \
					ft_search_higher_to_n(b, a->content), ft_stacksize(b)) + 1;
		a = a->next;
	}
	res[k] = ft_checkindex(b, \
					ft_search_higher_to_n(b, a->content), ft_stacksize(b)) + 1;
	return (res);
}

/*
	Count the movement necessary
	for move the element in the first position
*/
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

// absolute n
int	ft_topositive(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

// Array with number of mvs
int	*ft_naction(int i, int len, t_all *stacks, int *naction)
{
	while (i < len)
	{
		if (stacks->mov_a[i] < 0 && stacks->mov_b[i] < 0)
		{
			if (stacks->mov_b[i] < stacks->mov_a[i])
				naction[i] = ft_topositive(stacks->mov_b[i]);
			else
				naction[i] = ft_topositive(stacks->mov_a[i]);
		}
		else if (stacks->mov_b[i] < 0 || stacks->mov_a[i] < 0)
			naction[i] = ft_topositive(stacks->mov_a[i]) \
			+ ft_topositive(stacks->mov_b[i]);
		else
		{
			if (stacks->mov_b[i] > stacks->mov_a[i])
				naction[i] = stacks->mov_b[i];
			else
				naction[i] = stacks->mov_a[i];
		}
		i++;
	}
	return (naction);
}

//this function convert count in mv
int	ft_convertmv(t_all *stacks)
{
	int	i;
	int	len;
	int	*naction;
	int	start;

	len = ft_stacksize(stacks->a);
	naction = malloc(sizeof(int) * len);
	naction = ft_naction(0, len, stacks, naction);
	start = ft_checklessnum(naction, len - 1);
	i = 0;
	while (naction[i] != start)
		i++;
	free(naction);
	return (ft_checknode(stacks->a, i));
}
