/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:14:41 by cschiavo          #+#    #+#             */
/*   Updated: 2023/04/26 19:14:41 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//this function check less number in stack (ONLY FOR 4 NUMBERS!!!)
int	ft_check_less_content(t_stack *s)
{
	t_stack	*temp;
	int		i;
	int		c;

	c = 5;
	temp = s;
	i = temp->content;
	while (c--)
	{
		if (temp->content < i)
			i = temp->content;
		temp = temp->next;
	}
	return (i);
}
//check content pos
int	ft_check_content_pos(t_stack *stack, int n)
{
	t_stack	*temp;
	int		i;

	i = 1;
	temp = stack->prev;
	while (stack != temp)
	{
		if (stack->content == n)
			return (i);
		stack = stack->next;
		i++;
	}
	return (i);
}
