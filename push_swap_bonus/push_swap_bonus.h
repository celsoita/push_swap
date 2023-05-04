/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:51:44 by cschiavo          #+#    #+#             */
/*   Updated: 2023/05/04 16:50:40 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"

typedef enum e_bool
{
	TRUE	= 1,
	FALSE	= 0
}	t_bool;

typedef struct s_stack
{
	int				content;
	struct s_stack	*prev;
	struct s_stack	*next;
	struct s_stack	*end;
	struct s_stack	*start;
}	t_stack;

typedef struct s_all
{
	int		len;
	t_stack	*a;
	t_stack	*b;
}	t_all;

//ft_check_error_bonus
int			ft_checkarg(int argc, char **argv);
int			ft_checknum(int argc, char **argv);
int			ft_strlarg(int argc, char **str);
char		**ft_checkarr(int *argc, char *str);
//ft_free_bonus
void		ft_freematrix(char **matrix);
void		ft_free_lst(t_stack **lst);
//ft_init_bonus
void		ft_init(int *argc, char **argv, t_bool *noarray, char ***temp);
//ft_stacks_bonus
t_stack		*ft_add(t_stack *prev, int n);
t_stack		*ft_createstack(int argc, char **argv);
//ft_op_bonus
void		ft_swap(t_stack *lst);
void		ft_push(t_stack **stack_in, t_stack **stack_out);
void		ft_ss(t_stack *a, t_stack *b);
//ft_oprotate_bonus
void		ft_rotate(t_stack **lst);
void		ft_rrotate(t_stack **lst);
void		ft_rr_rotate(t_stack **a, t_stack **b);
void		ft_rrr_rrotate(t_stack **a, t_stack **b);
//ft_check_op_bonus
int			ft_checkorder(t_stack *stack);
int			ft_check_op(t_all *all);

#endif
