/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:54:19 by cschiavo          #+#    #+#             */
/*   Updated: 2023/05/02 10:15:59 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

//fill arr algorithm
void	ft_algorithm_arr(t_stack *lst, int i, int k, int *arr)
{
	while (lst->end->next != lst)
	{
		lst->start = lst;
		i = 0;
		while (lst->start != lst->end)
		{
			if (lst->start->content < lst->end->content && arr[k] <= arr[i])
				arr[k] = arr[i] + 1;
			i++;
			lst->start = lst->start->next;
		}
		lst->end = lst->end->next;
		k++;
	}
	lst->start = lst;
	i = 0;
	while (lst->start != lst->end)
	{
		if (lst->start->content < lst->end->content && arr[k] <= arr[i])
			arr[k] = arr[i] + 1;
		i++;
		lst->start = lst->start->next;
	}
}

//
int	ft_algorithm_subsq(int argc, int *len_arr, int *arr)
{
	int	i;
	int	lenght;

	i = 0;
	lenght = 0;
	while (i < argc)
	{
		if (arr[i] > lenght)
			lenght = arr[i];
		i++;
	}
	i = argc - 1;
	*len_arr = lenght;
	while (i > 0)
	{
		if (lenght == arr[i])
			break ;
		i--;
	}
	return (i);
}

//its a LIS algorithm
int	*ft_algorithm(t_stack *lst, int argc, int *len_arr)
{
	int	i;
	int	*res;
	int	*arr;
	int	lenght;

	arr = malloc(sizeof(int) * argc);
	lst->end = lst;
	i = 0;
	while (i < argc)
		arr[i++] = 1;
	ft_algorithm_arr(lst, i, 0, arr);
	i = ft_algorithm_subsq(argc, len_arr, arr);
	res = malloc(sizeof(int) * (*len_arr));
	lenght = *len_arr;
	res[--lenght] = i;
	while (lenght > 0)
	{
		if (arr[i] == lenght && \
		ft_checknode(lst, i) < ft_checknode(lst, res[lenght]))
			res[--lenght] = i;
		i--;
	}
	res = ft_fillarr(lst, res, *len_arr - 1);
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
