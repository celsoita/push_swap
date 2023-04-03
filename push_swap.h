#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int	content;
	struct s_stack *prev;
	struct s_stack *next;
	
} t_stack;
typedef struct s_all
{
	int	len;
	t_stack *a;
	t_stack *b;
	int	*mov_a;
	int	*mov_b;

}t_all;
#endif
