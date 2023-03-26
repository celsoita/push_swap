#include "push_swap.h"
#include "libft/libft.h"

t_stack *ft_add(t_stack *prev, int n)
{
		t_stack *node;

		node = malloc(sizeof(t_stack));
		node->prev = prev;
		node->next = NULL;
		node->content = n;
		return(node);
}

t_stack 	*ft_createstack(int argc, char **argv)
{
		t_stack	*lst;
		t_stack *temp;

		int	i;
		int n;

		i = 1;
		n = ft_atoi(argv[i]);
		lst = ft_add(NULL,n);
		temp = lst;
		while(++i < argc)
		{
				n = ft_atoi(argv[i]);
				temp->next = ft_add(temp,n);
				temp = temp->next;
		}
		lst->prev = temp;
		temp->next = lst;
		return(lst);
}
void	ft_printstack_new(t_stack lst)
{
	lst.prev->next = NULL;
	while (1)
	{
		ft_printf("%d\n",lst.content);
		if (!lst.next)
			return ;
		lst = *lst.next;
	}
}
void	ft_pb(t_all *lst)
{
	t_stack	*temp;

	temp = lst->a->next;
	temp->prev = lst->a->prev;
	lst->a->next = lst->b;
	lst->a->prev = lst->b->prev;
	lst->b->prev->next = lst->a;
	lst->b->prev = lst->a;
	lst->b = lst->a;
	lst->a = temp;
}

int main(int argc, char **argv)
{
	t_all stack;
	if(argc <= 1)
	{
		ft_printf("cazzo culo");
		return(0);
	}
	stack.len =  argc-1;
	stack.a = ft_createstack(argc,argv);
	ft_printf("stack a:\n");
	ft_printstack_new(*stack.a);
	ft_printf("stack b:\n");
	stack.b = ft_createstackB(argc);
	ft_printstack_new(*stack.b);
	ft_pb(&stack);
}