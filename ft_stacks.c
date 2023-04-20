/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:54:39 by cschiavo          #+#    #+#             */
/*   Updated: 2023/04/20 15:56:27 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

t_stack	*ft_add(t_stack *prev, int n)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	node->prev = prev;
	node->next = NULL;
	node->content = n;
	return (node);
}

//print stack (print list)
void	ft_printstack_new(t_stack *lst)
{
	t_stack	*temp;

	if (!lst)
		return ;
	temp = lst;
	while (temp->next != lst)
	{
		ft_printf("%d\n", temp->content);
		temp = temp->next;
	}
	ft_printf("%d\n", temp->content);
}

// reverse print stack
void	ft_printstack_rnew(t_stack *lst)
{
	t_stack	*temp;

	if (!lst)
		return ;
	temp = lst->prev;
	while (temp != lst)
	{
		ft_printf("%d\n", temp->content);
		temp = temp->prev;
	}
	ft_printf("%d\n", temp->content);
}

//this function create stack and we need a len = argc 
// and argument = argv and return all the stack
t_stack	*ft_createstack(int argc, char **argv)
{
	t_stack	*lst;
	t_stack	*temp;
	int		i;
	int		n;

	i = 0;
	n = ft_atoi(argv[i]);
	lst = ft_add(NULL, n);
	temp = lst;
	while (++i < argc)
	{
		n = ft_atoi(argv[i]);
		temp->next = ft_add(temp, n);
		temp = temp->next;
	}
	lst->prev = temp;
	temp->next = lst;
	return (lst);
}
