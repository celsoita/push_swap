#include "push_swap.h"
#include "libft/libft.h"

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
// questa e' una 
void	ft_printstack_rnew(t_stack *lst)
{
	t_stack	*temp;

	if(!lst)
	return ;
	temp = lst->prev;
	while (temp != lst)
		{
			ft_printf("%d\n",temp->content);
			temp = temp->prev;
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
void	ft_pb(t_stack **stack_in, t_stack **stack_out)
{
		t_stack	*temp;

		if(stack_in == NULL)
		 	return ;
		temp = (*stack_in)->next;
		if((*stack_in)->next == *stack_in)
			temp = NULL;
		(*stack_in)->next->prev = (*stack_in)->prev; 
		(*stack_in)->prev->next = temp;
		if(*stack_out)
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
}
// 2 	1
// 4	6
// 3

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
int	ft_char_in_array(char c, char *str)
{
		while(*str)
		{
			if(c == *str)
			return(1);
			str++;
		}
	return(0);
}
int	ft_strlarg(int argc, char **str)
{
	int j;
	int	i;
	int	k;
		j = 0;
			k = 0;
			while(k < argc)
			{
				i=0;
				if (ft_char_in_array(str[k][i], "-+") && !ft_char_in_array(str[k][i+1],"-+") && str[k][i+1])
					i++;
				while(str[k][i] >='0' && str[k][i] <= '9')
					i++;
				if(i > 0)
					j++;
				k++;
			}
			if(j == argc)
				return(0);
	return(1);
}
int	ft_checknode(t_stack	*lst, int pos)
{
		while(pos-- > 0)
			lst = lst->next;
		return(lst->content);	
}
int	*ft_fillarr(t_stack *lst, int *res,int pos)
{
	while(pos >= 0)
	{
		res[pos] = ft_checknode(lst,res[pos]);
		pos--;
	}
	return(res);
}

void	ft_simulate_stack_push(t_stack **stackIn, t_stack **stackOut)
{
	t_stack	*temp;

	if (!(*stackIn))
		return ;
	temp = NULL;
	if ((*stackIn)->next != (*stackIn))
	{
		temp = (*stackIn)->next;
		temp->prev = (*stackIn)->prev;
		temp->prev->next = temp;
	}
	(*stackIn)->prev = *stackIn;
	(*stackIn)->next = *stackIn;
	if (*stackOut)
	{
		(*stackIn)->prev = (*stackOut)->prev;
		(*stackIn)->next = (*stackOut);
		(*stackOut)->prev->next = (*stackIn);
		(*stackOut)->prev = (*stackIn);
	}
	*stackOut = *stackIn;
	*stackIn = temp;
}
int *ft_algorithm(t_stack	*lst,int argc, int *len_arr)
{
	int	i;
	int k;
	int	*res;
	int *arr;
	int lenght;
	t_stack	*end;
	t_stack	*start;

	arr = malloc(sizeof(int) * argc);
	end = lst;
	k = 0;//2//4//6//1//9
	i = 0;
	while(i < argc)
		arr[i++] = 1;
	while(end->next != lst)
	{
		start = lst;
		i = 0;
		while(start != end)
		{
			if(start->content < end->content && arr[k] <= arr[i])
				arr[k] = arr[i] + 1;
			i++;
			start = start ->next;
		}
			end = end->next;
		k++;
		////////
	}// questa e' la lunghezza della subsequence
	start = lst;
		i = 0;
		while(start != end)
		{
			if(start->content < end->content && arr[k] <= arr[i])
				arr[k] = arr[i] + 1;
			i++;
			start = start ->next;
		}
		// qua finisce !
		lenght = 0;
		i = 0;
		while( i < argc)
		{
			if(arr[i] > lenght)
				lenght = arr[i];
			i++;
		} 
		ft_printf("\nlenght=%d\n",lenght);
		res = malloc(sizeof(int) * lenght);
		i = argc-1; ft_printf("\nargc:%d\n",i);
		*len_arr = lenght;
		while(i > 0)
		{
			if(lenght == arr[i])
				break;
			i--;
		}
	k = i;
	res[--lenght] = i;
	while(lenght > 0)	
	{
		if(arr[i] == lenght && ft_checknode(lst,i) < ft_checknode(lst,res[lenght]))
			res[--lenght] = i;
		i--;
	}
	res = ft_fillarr(lst,res,k);
	ft_printf("uaaa fratm:%i\n",lenght);
	return(res);	
}

void	ft_pushorder(int	*alg, t_all *stack, int arr_len)
{
	int	i;
	int	k;
		
	i =  0;
	k = 0;
	(void) arr_len;
	while(k < stack->len)
	{
		if(alg[i] != stack->a->content)
			ft_pb(&stack->a,&stack->b);
		else
		{
			ft_ra(&stack->a);
			i++;
		}
			k++;
	}
}

int  main(int argc, char **argv)
{
	t_all	all;
	char **temp;
	int	*arr;

	temp = argv + 1;
	argc--;
	if(argc == 1)
		temp = ft_checkarr(&argc,*temp);
	if(argc <= 0 || ft_checkarg(argc,temp) || ft_checknum(argc,temp) || ft_strlarg(argc, temp))
	{
		ft_printf("sto cazzo");
		return(0);
	}
	all.len = argc;
	all.a = ft_createstack(argc,temp);
	all.b = NULL;
	ft_printf("STACK A:\n");
	ft_printstack_new(all.a);
	arr = ft_algorithm(all.a, argc,&argc);
	ft_printf("sorm:%i\n",argc);
	(void) arr;
	ft_pushorder(arr,&all,argc);
	ft_printf("STACK A:\n");
	ft_printstack_new(all.a);
	ft_printf("STACK B:\n");
	ft_printstack_new(all.b);
	
	
	/*ft_ra(&all.a);
	ft_printf("\nSTACK RA:\n");

	ft_rra(&all.a);
	ft_printf("\nSTACK RRA:\n");
	ft_printstack_new(all.a);
	ft_free_lst(&all.a);
	ft_free_lst(&all.b);

	ft_printstack_new(all.b);

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
