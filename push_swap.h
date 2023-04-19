/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:28:07 by cschiavo          #+#    #+#             */
/*   Updated: 2023/04/19 12:19:37 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_all
{
	int		len;
	t_stack	*a;
	t_stack	*b;
	int		*mov_a;
	int		*mov_b;
}	t_all;

//ft_check_error
int	ft_checkarg(int argc, char **argv);
int	ft_checknum(int argc, char **argv);
int	ft_strlarg(int argc, char **str);
char	**ft_checkarr(int *argc,char *str);
//ft_op
void	ft_rotate(t_stack **lst, char name);
void	ft_swap(t_stack *lst, char name);
void	ft_rrotate(t_stack **lst, char name);
void	ft_push(t_stack **stack_in, t_stack **stack_out, char n);
//ft_stacks
t_stack	*ft_add(t_stack *prev, int n);
void	ft_printstack_new(t_stack *lst);
void	ft_printstack_rnew(t_stack *lst);
t_stack	*ft_createstack(int argc, char **argv);

#endif
