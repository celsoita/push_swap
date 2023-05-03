/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mvorder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:14:29 by cschiavo          #+#    #+#             */
/*   Updated: 2023/05/03 14:42:38 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_order_b(t_stack **a, t_stack **b, int len)
{
	int	i;

	if ((*a)->content < ft_less_stack_n(*b))
	{
		while (ft_checkindex(*b, ft_less_stack_n(*b), len) > -1)
			ft_rotate(b, 'b');
		while (ft_checkindex(*b, ft_less_stack_n(*b), len) < -1)
			ft_rrotate(b, 'b');
		ft_push(a, b, 'b');
		return ;
	}
	if ((*a)->content > ft_bigger_stack_n(*b))
	{
		while (ft_checkindex(*b, ft_bigger_stack_n(*b), len) > 0)
			ft_rotate(b, 'b');
		while (ft_checkindex(*b, ft_bigger_stack_n(*b), len) < 0)
			ft_rrotate(b, 'b');
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
	t_bool	rot;
	int		i;
	int		k;
	int		number;

	i = 0;
	k = 0;
	number = alg[i];
	while (k < stack->len)
	{
		rot = FALSE;
		if (number != stack->a->content)
		{	
			if (ft_stacksize(stack->b) > 1)
			{
				if (number == stack->a->next->content)
					rot = TRUE;
				ft_order_b(&stack->a, &stack->b, ft_stacksize(stack->b));
				// ft_order_stack(&stack->b, 1, 'b');
			}
			else
			{
				ft_push(&stack->a, &stack->b, 'b');
				if (ft_stacksize(stack->b) == 2 && !ft_checkorder(stack->b))
					ft_rotate(&stack->b, 'b');
			}
		}
		else
		{
			ft_rotate(&stack->a, 'a');
			i++;
			if (i < arr_len)
				number = alg[i];
		}
		if (rot == TRUE && i < arr_len)
			number = alg[++i];
		k++;
	}
}

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
		res[k++] = ft_calculatemv(a, b);
		a = a->next;
	}
	res[k] = ft_calculatemv(a, b);
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

//be positive a num
int	ft_topositive(int n)
{
	if (n < 0)
		n = -n;
	return (n);
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
	i = 0;
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
			naction[i] = ft_topositive(stacks->mov_a[i]) + ft_topositive(stacks->mov_b[i]);
		else
		{
			if (stacks->mov_b[i] > stacks->mov_a[i])
				naction[i] = stacks->mov_b[i];
			else
				naction[i] = stacks->mov_a[i];
		}
		i++;
	}
	start = ft_checklessnum(naction, len - 1);
	i = 0;
	while(naction[i] != start)
		i++;
	//ft_convertmv_ordinate(naction, start, stacks);
	free(naction);
	return (ft_checknode(stacks->a, i));
}
