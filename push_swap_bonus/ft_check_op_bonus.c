/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_op_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:34:50 by cschiavo          #+#    #+#             */
/*   Updated: 2023/05/04 16:55:04 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

// Check order of stack
int	ft_checkorder(t_stack *stack)
{
	t_stack	*temp;

	temp = stack->prev;
	while (stack != temp)
	{
		if (stack->content > stack->next->content)
			return (1);
		stack = stack->next;
	}
	return (0);
}

t_bool	ft_conditions_check_op(t_all *all, char *check)
{
	if (!ft_strncmp(check, "sa\n", 3))
		ft_swap(all->a);
	else if (!ft_strncmp(check, "sb\n", 3))
		ft_swap(all->b);
	else if (!ft_strncmp(check, "ss\n", 3))
		ft_ss(all->a, all->b);
	else if (!ft_strncmp(check, "ra\n", 3))
		ft_rotate(&all->a);
	else if (!ft_strncmp(check, "rb\n", 3))
		ft_rotate(&all->b);
	else if (!ft_strncmp(check, "rr\n", 3))
		ft_rr_rotate(&all->a, &all->b);
	else if (!ft_strncmp(check, "rrr\n", 4))
		ft_rrr_rrotate(&all->a, &all->b);
	else if (!ft_strncmp(check, "rra\n", 4))
		ft_rrotate(&all->a);
	else if (!ft_strncmp(check, "rrb\n", 4))
		ft_rrotate(&all->b);
	else if (!ft_strncmp(check, "pb\n", 3))
		ft_push(&all->a, &all->b);
	else if (!ft_strncmp(check, "pa\n", 3))
		ft_push(&all->b, &all->a);
	else
		return (TRUE);
	return (FALSE);
}

// Check if the numbers are in order after all the operations
int	ft_check_op(t_all *all)
{
	char	*check;

	check = "1";
	while (check != NULL)
	{
		check = get_next_line(1);
		if (check == NULL)
			break ;
		if (ft_conditions_check_op(all, check) == TRUE)
			return (-1);
	}
	if (!all->a || all->b || ft_checkorder(all->a))
		return (0);
	return (1);
}
