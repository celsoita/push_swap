/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:23:02 by cschiavo          #+#    #+#             */
/*   Updated: 2023/05/04 14:23:02 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

// this function free the matrix 
void	ft_freematrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{	
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

// this function free the list
void	ft_free_lst(t_stack **lst)
{
	t_stack	*temp;

	if (!*lst)
		return ;
	(*lst)->prev->next = NULL;
	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}	
}
