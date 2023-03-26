#include "push_swap.h"
#include "libft/libft.h"

int	ft_atoi_error(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	if(*str)
		exit(write(2,"error\n", 6));
	return (res * sign);
}

int ft_checknum(int argc, char **argv)
{
	int	i;
	int	c;
	i = 0;
	c = 0;
	//2 3 4 - 3v 1c
	// devo scorrere argv se in esso c'e' solo una lettera return 1
	while(c < argc)
	{
		while(argv[c][i])
		{
			if(ft_isdigit(argv[c][i])!= 1 && argv[c][i] != '-' && argv[c][i] != '+')
				return(1);
			i++;
		}	
		c++;
	}
	return(0);
}
int	ft_checkarg(int argc, char **argv)
{
	int	c;
	int	*arr;
	int	n;
	int	i;
	c = 0;
	n = 0;	
	i = 0;
	n = ft_atoi(argv[c]);
	arr = malloc(sizeof(int) * argc);
	while(c < argc)
	{
		n = ft_atoi(argv[c]);
		arr[c] = n;
		i = c - 1;
		while(i >= 0)
	  	{	
	  		if(arr[i] == n)
	  		{
				free(arr);
				return(1); // se uguale a 1 errore
			}	
		i--;
		}
		c++;
	}
	free(arr);
	return(0);
}
// funzione per creare un nodo e aggiungervi un numero e collegare il prev con il successivo
t_stack	*ft_add(t_stack *prev, int n)
{
	t_stack *node;
	
	node = malloc(sizeof(t_stack));
	node->prev = prev;
	node->next = NULL;
	node->content = n;
	return(node);
}
//serve  a printare la lista finche' la mia len esiste la len sarebbe il mio argc.
void	ft_printstack_new(t_stack *lst)
{
	t_stack	*temp;

	if(!lst)
	return ;
	temp = lst;
	while (temp->next != lst)
		{
			ft_printf("%d\n",temp->content);
			temp = temp->next;
		}
		ft_printf("%d\n",temp->content);
}
// questa e' una funzione per creare tutto lo stack essa ha bisogno di una len = argc, e degli argomenti = argv e restituisce tutto lo stack.
t_stack	*ft_createstack(int argc, char **argv)
{
	t_stack *lst;
	t_stack *temp;
	int	i;
	int	n;

	i = 0;
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
// questa funzione swappa i primi due elementi dello stack che si vuole
void	ft_swap(t_stack *lst)
{
	int	temp;
	temp = lst->content;
	lst->content = lst->next->content;
	lst->next->content = temp;
}
// questa funzione e' fatta con il culo  pusha il primo elemento di b in a
void	ft_pa(t_all *lst)
{
	t_stack	*temp;
	if(lst->b == NULL)
		return ;
	temp = lst->b->next;
	temp->prev = lst->b->prev;

	if(lst->a)
	{
	lst->b->next = lst->a;
	lst->b->prev = lst->a->prev;
	lst->a->prev->next = lst->b;
	lst->a->prev = lst->b;
	}
	else
	{	
		lst->b->prev->next = temp;
		lst->b->next = lst->b;
		lst->b->prev = lst->b;
	}
		lst->a = lst->b;
		if(lst->b != temp)
			lst->b = temp;
		else
			lst->b = NULL;
	
	//lst->b->next = lst->b->prev;	
}
void	ft_ra(t_stack **lst)
{
		if(!*lst || (*lst)->next == *lst)
			return ;
		 *lst = (*lst)->next;
}
void ft_rra(t_stack **lst)
{
		if(!*lst || (*lst)->prev == *lst)
			return ;
		*lst = (*lst)->prev;
}
void	ft_rrr(t_stack **lsta, t_stack **lstb)
{
	ft_rra(lsta);
	ft_rra(lstb);
}
// questa funzione e' fatta con il culo  pusha il primo elemento di a in b 
void	ft_pb(t_all *lst)
{
	t_stack	*temp;
	if(lst->a == NULL)
		return ;
	temp = lst->a->next;
	temp->prev = lst->a->prev;
	if(lst->b)
	{
		lst->a->next = lst->b;
		lst->a->prev = lst->b->prev;
		lst->b->prev->next = lst->a;
		lst->b->prev = lst->a;
	}
	else
	{
		lst->a->prev->next = temp;
		lst->a->next = lst->a;
		lst->a->prev = lst->a;
	}
		lst->b = lst->a;
		if(lst->a != temp)
			lst->a = temp;
		else
			lst->a = NULL;
}

void	ft_free_lst(t_stack **lst)
{
	t_stack *temp;

	if(!*lst)
		return ;
	(*lst)->prev->next = NULL;
	while(*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
			
}
char	**ft_checkarr(int *argc,char *str)
{
	char	**res;
	int		i;
	res = ft_split(str,' ');
	i = 0;
	while(res[i])
		i++;
	*argc = i;
	return(res);
}
//"2 3 4 5" 
int  main(int argc, char **argv)
{
	t_all	all;
	char **temp;
	temp = argv + 1;
	argc--;
	if(argc == 1)
		temp = ft_checkarr(&argc,*temp);
	if(argc <= 0 || ft_checkarg(argc,temp) || ft_checknum(argc,temp))
	{
		ft_printf("sto cazzo");
		return(0);
	}
	all.len = argc;
	all.a = ft_createstack(argc,temp);
	all.b = NULL;
	ft_printf("STACK A:\n");
	ft_printstack_new(all.a);
	
	ft_ra(&all.a);
	ft_printf("\nSTACK RA:\n");
	ft_printstack_new(all.a);

	ft_rra(&all.a);
	ft_printf("\nSTACK RRA:\n");
	ft_printstack_new(all.a);
	ft_free_lst(&all.a);
	ft_free_lst(&all.b);

	/*ft_printf("STACK B:\n");
	ft_printstack_new(all.b);

	ft_printf("PB:\n");
	ft_pb(&all);
	ft_printstack_new(all.b);

	ft_printf("STACK A:\n");
	ft_printstack_new(all.a);

	
	ft_printf("STACK B:\n");
	ft_printstack_new(all.b);

	ft_printf("PA:\n");
	ft_pa(&all);
	ft_printstack_new(all.a);
		
	ft_printf("STACK B:\n");
	ft_printstack_new(all.b);

	ft_printf("PA:\n");
	ft_pa(&all);
	ft_printstack_new(all.a);
	*/
}
