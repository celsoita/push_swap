/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:28:07 by cschiavo          #+#    #+#             */
/*   Updated: 2023/04/26 16:44:32 by cschiavo         ###   ########.fr       */
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
int	ft_checkarg(int argc, char **argv);
int	ft_checknum(int argc, char **argv);
int	ft_strlarg(int argc, char **str);
char	**ft_checkarr(int *argc,char *str);
//ft_op
void	ft_swap(t_stack *lst, char name);
void	ft_push(t_stack **stack_in, t_stack **stack_out, char n);
int	ft_less_stack_n(t_stack *stack);
int	ft_bigger_stack_n(t_stack *stack);
//ft_oprotate
void	ft_rotate(t_stack **lst, char name);
void	ft_rrotate(t_stack **lst, char name);
void	ft_rr_rotate(t_stack **a, t_stack **b);
void	ft_rrr_rrotate(t_stack **a, t_stack **b);
//ft_stacks
t_stack	*ft_add(t_stack *prev, int n);
void	ft_printstack_new(t_stack *lst);
void	ft_printstack_rnew(t_stack *lst);
t_stack	*ft_createstack(int argc, char **argv);
//ft_algorithm
int	*ft_fillarr(t_stack *lst, int *res, int pos);
int	*ft_algorithm(t_stack *lst, int argc, int *len_arr);
void	ft_minialgo(t_stack **a, int len);
//ft_mvorder
void	ft_pushorder(int *alg, t_all *stack, int arr_len);
int	*ft_countmva(t_stack *a, t_stack *b, int len);
int	*ft_countmvb(int len);
int	ft_convertmv(t_all *stacks);
//ft_free
void	ft_freematrix(char **matrix);
void	ft_free_lst(t_stack **lst);
//ft_check_stack
int	ft_checknode(t_stack *lst, int pos);
int	ft_stacksize(t_stack *stack);
int	ft_checklessnum(int *arr,int len);
int	ft_checkindex(t_stack *b, int n, int len);
int	ft_checkorder(t_stack *stack);
//ft_order
void	ft_order(t_all *l, int len, int c);
//ft_calculatemv
int	ft_calculatemv(t_stack *a, t_stack *b, t_stack *start, int temp);

#endif
