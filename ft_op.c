/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:55:34 by cschiavo          #+#    #+#             */
/*   Updated: 2023/04/14 11:55:34 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// this function swap the first 2 element in the list
void	ft_swap(t_stack *lst, char name)
{
	int	temp;

	temp = lst->content;
	lst->content = lst->next->content;
	lst->next->content = temp;
	ft_printf("s%c\n", name);
}

// this function push the first element in stack_in to stack_out
void	ft_push(t_stack **stack_in, t_stack **stack_out, char n)
{
	t_stack	*temp;

	if (stack_in == NULL)
		return ;
	temp = (*stack_in)->next;
	if ((*stack_in)->next == *stack_in)
		temp = NULL;
	(*stack_in)->next->prev = (*stack_in)->prev;
	(*stack_in)->prev->next = temp;
	if (*stack_out)
	{
		(*stack_in)->next = *stack_out;
		(*stack_in)->prev = (*stack_out)->prev;
		(*stack_out)->prev->next = *stack_in;
		(*stack_out)->prev = *stack_in;
	}
	else
	{
		(*stack_in)->prev = *stack_in;
		(*stack_in)->next = *stack_in;
	}
	*stack_out = *stack_in;
	*stack_in = temp;
	ft_printf("p%c\n", n);
}
