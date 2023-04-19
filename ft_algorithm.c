/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:54:19 by cschiavo          #+#    #+#             */
/*   Updated: 2023/04/19 12:19:34 by cschiavo         ###   ########.fr       */
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

//fill an array with stack content
int	*ft_fillarr(t_stack *lst, int *res, int pos)
{
	while (pos >= 0)
	{
		res[pos] = ft_checknode(lst, res[pos]);
		pos--;
	}
	return (res);
}

//its a LIS algorithm
int	*ft_algorithm(t_stack *lst, int argc, int *len_arr)
{
	int	i;
	int	k;
	int	*res;
	int	*arr;
	int	lenght;
	t_stack	*end;
	t_stack	*start;

	arr = malloc(sizeof(int) * argc);
	end = lst;
	k = 0;
	i = 0;
	while (i < argc)
		arr[i++] = 1;
	while (end->next != lst)
	{
		start = lst;
		i = 0;
		while (start != end)
		{
			if (start->content < end->content && arr[k] <= arr[i])
				arr[k] = arr[i] + 1;
			i++;
			start = start ->next;
		}
		end = end->next;
		k++;
	}
	start = lst;
	i = 0;
	while (start != end)
	{
		if (start->content < end->content && arr[k] <= arr[i])
			arr[k] = arr[i] + 1;
		i++;
		start = start ->next;
	}
	lenght = 0;
	i = 0;
	while (i < argc)
	{
		if (arr[i] > lenght)
			lenght = arr[i];
		i++;
	}
	res = malloc(sizeof(int) * lenght);
	i = argc - 1;
	*len_arr = lenght;
	while (i > 0)
	{
		if (lenght == arr[i])
			break ;
		i--;
	}
	k = lenght - 1;
	res[--lenght] = i;
	while (lenght > 0)	
	{
		if (arr[i] == lenght && \
		ft_checknode(lst, i) < ft_checknode(lst, res[lenght]))
			res[--lenght] = i;
		i--;
	}
	res = ft_fillarr(lst, res, k);
	free(arr);
	return (res);
}

//mini algorithm for 2/3 number in stack
void	ft_minialgo(t_stack **a, int len)
{
	if (len == 2)
	{
		if ((*a)->content > (*a)->next->content)
			ft_swap(*a, 'a');
	}
	else
	{
		if ((*a)->content > (*a)->prev->content && \
		(*a)->content > (*a)->next->content && \
		(*a)->next->content < (*a)->prev->content)
			ft_rotate(a, 'a');
		if ((*a)->content < (*a)->next->content && \
		(*a)->prev->content < (*a)->next->content)
			ft_rrotate(a, 'a');
		if ((*a)->content < (*a)->prev->content && \
		(*a)->next->content > (*a)->prev->content)
			ft_rrotate(a, 'a');
		if ((*a)->content > (*a)->next->content && \
		(*a)->prev->content < (*a)->next->content)
			ft_rotate(a, 'a');
		if ((*a)->content < (*a)->prev->content && \
		(*a)->content > (*a)->next->content)
			ft_swap(*a, 'a');
	}
}
