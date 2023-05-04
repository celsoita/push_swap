/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:28:07 by cschiavo          #+#    #+#             */
/*   Updated: 2023/05/04 10:03:59 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

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
	int		*mov_a;
	int		*mov_b;
}	t_all;

//ft_check_error
int			ft_checkarg(int argc, char **argv);
int			ft_checknum(int argc, char **argv);
int			ft_strlarg(int argc, char **str);
char		**ft_checkarr(int *argc, char *str);
//ft_op
void		ft_swap(t_stack *lst, char name);
void		ft_push(t_stack **stack_in, t_stack **stack_out, char n);
int			ft_less_stack_n(t_stack *stack);
int			ft_bigger_stack_n(t_stack *stack);
//ft_oprotate
void		ft_rotate(t_stack **lst, char name);
void		ft_rrotate(t_stack **lst, char name);
void		ft_rr_rotate(t_stack **a, t_stack **b);
void		ft_rrr_rrotate(t_stack **a, t_stack **b);
//ft_stacks
t_stack		*ft_add(t_stack *prev, int n);
t_stack		*ft_createstack(int argc, char **argv);
//ft_algorithm
void		ft_order_stack(t_stack **s, t_bool rev, char c);
void		ft_algofoure(t_all *stacks);
void		ft_minialgo(t_stack **a, int len);
//ft_order
void		ft_order_b(t_stack **a, t_stack **b, int len);
void		ft_push_better(t_all *all, int n);
//ft_mvorder
int			*ft_countmva(t_stack *a, t_stack *b, int len);
int			*ft_countmvb(int len);
int			ft_convertmv(t_all *stacks);
//ft_free
void		ft_freematrix(char **matrix);
void		ft_free_lst(t_stack **lst);
//ft_check_stack
int			ft_checknode(t_stack *lst, int pos);
int			ft_stacksize(t_stack *stack);
int			ft_checklessnum(int *arr, int len);
int			ft_checkindex(t_stack *b, int n, int len);
int			ft_checkorder(t_stack *stack);
//ft_calculatemv
int			ft_calculatemv(t_stack *a, t_stack *b);
void		ft_init(int *argc, char **argv, t_bool *noarray, char ***temp);
void		ft_less_six_numbers(t_all *all);
void		ft_more_five_numbers(t_all *all);
//ft_search_content
int			ft_check_less_content(t_stack *s);
int			ft_check_content_pos(t_stack *stack, int n);
int			ft_search_higher_to_n(t_stack *b, int n);

#endif
