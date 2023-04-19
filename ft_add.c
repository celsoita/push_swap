#include "push_swap.h"
#include "libft/libft.h"
// //check arg for see in are only number
// int ft_checknum(int argc, char **argv)
// {
// 	int	i;
// 	int	c;
// 	i = 0;
// 	c = 0;
// 	//2 3 4 - 3v 1c
// 	// devo scorrere argv se in esso c'e' solo una lettera return 1
// 	while(c < argc)
// 	{
// 		i = 0;
// 		while(argv[c][i])
// 		{
// 			if(ft_isdigit(argv[c][i])!= 1 && argv[c][i] != '-' && argv[c][i] != '+')
// 				return(1);
// 			i++;
// 		}	
// 		c++;
// 	}
// 	return(0);
// }
// //check double number
// int	ft_checkarg(int argc, char **argv)
// {
// 	int	c;
// 	int	*arr;
// 	int	n;
// 	int	i;
// 	c = 0;
// 	n = 0;	
// 	i = 0;
// 	n = ft_atoi(argv[c]);
// 	arr = malloc(sizeof(int) * argc);
// 	while(c < argc)
// 	{
// 		n = ft_atoi(argv[c]);
// 		arr[c] = n;
// 		i = c - 1;
// 		while(i >= 0)
// 	  	{	
// 	  		if(arr[i] == n)
// 	  		{
// 				free(arr);
// 				return(1); //if equal 1 give error
// 			}	
// 		i--;
// 		}
// 		c++;
// 	}
// 	free(arr);
// 	return(0);
// }
// create node and add to the next
// t_stack	*ft_add(t_stack *prev, int n)
// {
// 	t_stack *node;
	
// 	node = malloc(sizeof(t_stack));
// 	node->prev = prev;
// 	node->next = NULL;
// 	node->content = n;
// 	return(node);
// }
// //print stack (print list)
// void	ft_printstack_new(t_stack *lst)
// {
// 	t_stack	*temp;

// 	if(!lst)
// 	return ;
// 	temp = lst;
// 	while (temp->next != lst)
// 		{
// 			ft_printf("%d\n",temp->content);
// 			temp = temp->next;
// 		}
// 		ft_printf("%d\n",temp->content);
// }
// // reverse print stack
// void	ft_printstack_rnew(t_stack *lst)
// {
// 	t_stack	*temp;

// 	if(!lst)
// 	return ;
// 	temp = lst->prev;
// 	while (temp != lst)
// 		{
// 			ft_printf("%d\n",temp->content);
// 			temp = temp->prev;
// 		}
// 		ft_printf("%d\n",temp->content);
// }
// //this function create stack and we need a len = argc , and argument = argv and return all the stack
// t_stack	*ft_createstack(int argc, char **argv)
// {
// 	t_stack *lst;
// 	t_stack *temp;
// 	int	i;
// 	int	n;

// 	i = 0;
// 	n = ft_atoi(argv[i]);
// 	lst = ft_add(NULL,n);
// 	temp = lst;
// 	while(++i < argc)
// 	{
// 		n = ft_atoi(argv[i]);
// 		temp->next = ft_add(temp,n);
// 		temp = temp->next;
// 	}
// 	lst->prev = temp;
// 	temp->next = lst;
// 	return(lst);
// }
// // this function swap the first 2 element in the list
// void	ft_swap(t_stack *lst,char name)
// {
// 	int	temp;
// 	temp = lst->content;
// 	lst->content = lst->next->content;
// 	lst->next->content = temp;
// 	ft_printf("s%c\n",name);
// }
// // this function rotate stack 
// void	ft_rotate(t_stack **lst,char name)
// {
// 		if(!*lst || (*lst)->next == *lst)
// 			return ;
// 		 *lst = (*lst)->next;
// 		ft_printf("r%c\n",name);
// }
// // this function rotate stack in reverse order
// void ft_rrotate(t_stack **lst,char name)
// {
// 		if(!*lst || (*lst)->prev == *lst)
// 			return ;
// 		*lst = (*lst)->prev;
// 		ft_printf("rr%c\n",name);
//
// }
// this function rotate stack and in reverse order
// void	ft_rrr(t_stack **lsta, t_stack **lstb)
// {
// 	ft_rrotate(lsta,'a');
// 	ft_rrotate(lstb,'b');
// }
// // this function push the first element in stack_in to stack_out
// void	ft_push(t_stack **stack_in, t_stack **stack_out,char n)
// {
// 		t_stack	*temp;
//
// 		if(stack_in == NULL)
// 		 	return ;
// 		temp = (*stack_in)->next;
// 		if((*stack_in)->next == *stack_in)
// 			temp = NULL;
// 		(*stack_in)->next->prev = (*stack_in)->prev; 
// 		(*stack_in)->prev->next = temp;
// 		if(*stack_out)
// 		{
// 			(*stack_in)->next = *stack_out;
// 			(*stack_in)->prev = (*stack_out)->prev;
// 			(*stack_out)->prev->next = *stack_in;
// 			(*stack_out)->prev = *stack_in;
// 		}
// 		else
// 		{
// 			(*stack_in)->pr//this function is a check for accept  the string and create a matrix for it for example " 1 2 3" be a "1" "2" "3"
// char	**ft_checkarr(int *argc,char *str)
// {
// 	char	**res;
// 	int		i;
// 	res = ft_split(str,' ');
// 	i = 0;
// 	while(res[i])
// 		i++;
// 	*argc = i;
// 	return(res);
// }v = *stack_in;
// 			(*stack_in)->next = *stack_in;
// 		}
// 		*stack_out = *stack_in;
// 		*stack_in = temp;
// 		ft_printf("p%c\n",n);
// }
// // this function free the list
// void	ft_free_lst(t_stack **lst)
// {
// 	t_stack *temp;

// 	if(!*lst)
// 		return ;
// 	(*lst)->prev->next = NULL;
// 	while(*lst)
// 	{
// 		temp = (*lst)->next;
// 		free(*lst);
// 		*lst = temp;
// 	}	
// }
// //this function is a check for accept  the string and create a matrix for it for example " 1 2 3" be a "1" "2" "3"
// char	**ft_checkarr(int *argc,char *str)
// {
// 	char	**res;
// 	int		i;
// 	res = ft_split(str,' ');
// 	i = 0;
// 	while(res[i])
// 		i++;
// 	*argc = i;
// 	return(res);
// }
// //if the char is present in array return 1 u can use it for comparison with - || +
// int	ft_char_in_array(char c, char *str)
// {
// 		while(*str)
// 		{
// 			if(c == *str)
// 			return(1);
// 			str++;
// 		}
// 	return(0);
// }
// //this function check if present in array  "-" " +"
// int	ft_strlarg(int argc, char **str)
// {
// 	int j;
// 	int	i;
// 	int	k;
// 		j = 0;
// 			k = 0;
// 			while(k < argc)
// 			{
// 				i=0;
// 				if (ft_char_in_array(str[k][i], "-+") && !ft_char_in_array(str[k][i+1],"-+") && str[k][i+1])
// 					i++;
// 				while(str[k][i] >='0' && str[k][i] <= '9')
// 					i++;
// 				if(i > 0)
// 					j++;
// 				k++;
// 			}
// 			if(j == argc)
// 				return(0);
// 	return(1);
// }
// //take content at position of lst
// int	ft_checknode(t_stack *lst, int pos)
// {
// 		while(pos-- > 0)
// 			lst = lst->next;
// 		return(lst->content);	
// }
// //fill an array with stack content
// int	*ft_fillarr(t_stack *lst, int *res,int pos)
// {
// 	while(pos >= 0)
// 	{
// 		res[pos] = ft_checknode(lst,res[pos]);
// 		pos--;
// 	}
// 	return(res);
// }
// //its a LIS algorithm
// int *ft_algorithm(t_stack *lst,int argc, int *len_arr)
// {
// 	int	i;
// 	int k;
// 	int	*res;
// 	int *arr;
// 	int lenght;
// 	t_stack	*end;
// 	t_stack	*start;

// 	arr = malloc(sizeof(int) * argc);
// 	end = lst;
// 	k = 0;//2//4//6//1//9
// 	i = 0;
// 	while(i < argc)
// 		arr[i++] = 1;
// 	while(end->next != lst)
// 	{
// 		start = lst;
// 		i = 0;
// 		while(start != end)
// 		{
// 			if(start->content < end->content && arr[k] <= arr[i])
// 				arr[k] = arr[i] + 1;
// 			i++;
// 			start = start ->next;
// 		}
// 			end = end->next;
// 		k++;
// 		////////
// 	}// questa e' la lunghezza della subsequence
// 	start = lst;
// 		i = 0;
// 		while(start != end)
// 		{
// 			if(start->content < end->content && arr[k] <= arr[i])
// 				arr[k] = arr[i] + 1;
// 			i++;
// 			start = start ->next;
// 		}
// 		// qua finisce !
// 		lenght = 0;
// 		i = 0;
// 		while( i < argc)
// 		{
// 			if(arr[i] > lenght)
// 				lenght = arr[i];
// 			i++;
// 		} 
// 		res = malloc(sizeof(int) * lenght);
// 		i = argc-1; 
// 		*len_arr = lenght;
// 		while(i > 0)
// 		{
// 			if(lenght == arr[i])
// 				break;
// 			i--;
// 		}
// 	k = lenght - 1;
// 	res[--lenght] = i;
// 	while(lenght > 0)	
// 	{
// 		if(arr[i] == lenght && ft_checknode(lst,i) < ft_checknode(lst,res[lenght]))
// 			res[--lenght] = i;
// 		i--;
// 	}
// 	res = ft_fillarr(lst,res,k);
// 	free(arr);
// 	return(res);	
// }
//this function check the number in stack and push the element not in order in b ... remaining stack a in order
// void	ft_pushorder(int *alg, t_all *stack, int arr_len)
// {
// 	int	i;
// 	int	k;
// 	int	number;

// 	i =  0;
// 	k = 0;
// 	number = alg[i];
// 	while(k < stack->len )
// 	{
// 		if(number != stack->a->content)
// 			ft_push(&stack->a,&stack->b,'b');
// 		else
// 		{
// 			ft_rotate(&stack->a,'a');
// 			i++;
// 			if(i < arr_len)
// 				number = alg[i];
// 		}
// 			k++;
// 	}
// }
// // this function is a support for ft_countmva
// int	ft_calculatemv(t_stack *a, t_stack *b, t_stack *start, int temp)
// {
// 	int	i;
// 	int len;
// 	len = temp;

// 	i = 0;
// 	if(a->content > b->content)
// 		i = 1;
// 	else
// 	{
// 		while (1)
// 		{
// 			if(a->content < b->content && a->next->content > b->content)
// 			{
// 				i+=2;
// 				break ;
// 			}
// 			a = a->next;
// 			i+=2;
// 			if (i / 2 > len / 2)
// 			{
// 				i = 0;
// 				a = start;
// 				break ;
// 			}
// 		}
// 		if (!i)
// 		{
// 			while (temp-- > 0)
// 			{
// 				if(a->content < b->content && a->next->content > b->content)
// 				{
// 					i+=2;
// 					break ;
// 				}
// 				a = a->prev;
// 				i+=2;
// 			}
// 			if(temp < 0)
// 				i=2;
// 		}
// 	}
// 	return (i);
// }
// // function countmovement for push element in right order
// int	*ft_countmva(t_stack *a, t_stack *b, int len)
// {
// 	t_stack *startb;
// 	int	*res;
// 	int	k;

// 	k = 0;
// 	startb = b;
// 	res = malloc(sizeof(int) * len);
// 	while(startb != b->next)
// 	{
// 		res[k++] = ft_calculatemv(a, b, a, len);
// 		b = b->next;
// 	}
// 	res[k] = ft_calculatemv(a, b, a, len);
// 	return(res);
// }
// //this function count the size of stack
// int	ft_stacksize(t_stack *stack)
// {
// 	t_stack *temp;
// 	int 	i;
// 	temp = stack->next;
// 	i = 1;
// 	while(temp != stack)
// 	{
// 		temp = temp->next;
// 		i++; 
// 	}
// 	return(i);
// }
// // this function free the matrix 
// void ft_freematrix(char **matrix)
// {
// 	int	i;
// 	i = 0;
// 	while(matrix[i])
// 	{	
// 		free(matrix[i]);
// 		i++;
// 	}
// 	free(matrix);
// }
// // this function count the movement necessary for move the element in the first position
// int	*ft_countmvb(int len)
// {
// 	int *res;
// 	int	c;
// 	int	i;

// 	res = malloc(sizeof(int) * len);
// 	i = 0;
// 	c = 0; 
// 	while(c < len/2)
// 		res[i++] = c++;
// 	while(c < len)
// 		res[i++] = c++ - len;
// 	return(res);
// }
// //search the less num in array iny
// int	ft_checklessnum(int *arr,int len)
// {
// 	int	res;

// 	res = arr[len];
// 	while(len >= 0)
// 	{
// 		if(arr[len] < res)
// 			res = arr[len];
// 		len--;	
// 	}
// 	return(res);
// }

// //this function convert count in mv
// void	ft_convertmv(t_all *stacks)
// {
// 	int	*mov_a;
// 	int *mov_b;
// 	int	i;
// 	int	len;
// 	int	*naction;
// 	int start;
// 	len = ft_stacksize(stacks->b );
// 	mov_a = stacks->mov_a;
// 	mov_b = stacks->mov_b;
// 	naction = malloc(sizeof(int) * len);

// 	i = 0;
// 	while(i < len)
// 	{
// 		if (mov_b[i] < 0)
// 			naction[i] = mov_a[i] + (-mov_b[i]);
// 		else
// 			naction[i] = mov_a[i] + mov_b[i];
// 		i++;
// 	}
// 	start = ft_checklessnum(naction,len-1);
// 	i = 0;
// 	while(naction[i] != start)
// 		i++;
// 	start = 0;
// 	while(start++ < i)
// 	{
// 		if(mov_b[i] < 0)
// 			ft_rrotate(&stacks->b,'b');
// 		else
// 			ft_rotate(&stacks->b,'b');
// 	}
// 	free(naction);
// }

// void	ft_order(t_stack **a, t_stack **b, int len)
// {
// 	int	i;

// 	i = 0;
// 	if((*b)->content > (*a)->prev->content)
// 	{
// 		ft_push(b,a,'a');
// 		ft_rotate(a,'a');
// 		return ;
// 	}
// 	if((*b)->content < (*a)->content)
// 	{
// 		ft_push(b,a,'a');
// 		return ;
// 	}
// 	if(ft_checknode(*a,len/2) > (*b)->content)
// 	{
// 		while(i < len)
// 		{
// 			if((*b)->content > (*a)->content && (*b)->content < (*a)->next->content)
// 			{
// 				ft_push(b,a,'a');
// 				ft_swap(*a,'a');
// 				break;
// 			}	
// 			ft_rotate(a,'a');
// 			i++;
// 		}
// 		while(i--)
// 			ft_rrotate(a,'a');
// 	}
// 	else
// 	{
// 		i = 1;
// 		while(i < len)
// 		{
// 			if((*a)->content > (*b)->content && (*a)->prev->content < (*b)->content)
// 			{
// 				ft_push(b,a,'a');
// 				break ;
// 			}
// 			ft_rrotate(a,'a');
// 			i++;
// 		}
// 		while(i--)
// 			ft_rotate(a,'a');
// 	}
// }
// //mini algorithm for 2/3 number in stack
// void	ft_minialgo(t_stack **a,int len)
// {
// 	if(len == 2)
// 	{
// 		if((*a)->content > void	ft_minialgo(t_stack **a, int len))->prev->content && (*a)->content > (*a)->next->content && (*a)->next->content < (*a)->prev->content)
// 			ft_rotate(a,'a');
// 		// 2 3 1
// 		if ((*a)->content < (*a)->next->content && (*a)->prev->content < (*a)->next->content)
// 			ft_rrotate(a,'a');
// 		// 1 3 2
// 		if((*a)->content < (*a)->prev->content && (*a)->next->content > (*a)->prev->content)
// 			ft_rrotate(a,'a');
// 		//3 2 1
// 		if ((*a)->content > (*a)->next->content && (*a)->prev->content < (*a)->next->content)
// 			ft_rotate(a,'a');
// 		// 2 1 3
// 		if((*a)->content < (*a)->prev->content && (*a)->content > (*a)->next->content)
// 			ft_swap(*a,'a');
// 	}
// }
///...................///
int  main(int argc, char **argv)
{
	t_all	all;
	char **temp;
	int	*arr;
	char noarray;	

	temp = argv + 1;
	argc--;
	noarray = 0;
	if(argc == 1)
	{
		temp = ft_checkarr(&argc,*temp);
		noarray = 1;
	}
	if(argc <= 0 || ft_checkarg(argc,temp) || ft_checknum(argc,temp) || ft_strlarg(argc, temp))
	{
		ft_printf("error\n");
		if(noarray == 1)
			ft_freematrix(temp);
		return(0);
	}
	all.len = argc;
	all.a = ft_createstack(argc,temp);
	all.b = NULL;
	ft_printf("STACK A:\n");
	ft_printstack_new(all.a);
	arr = 0;
	if(all.len < 4 )
		ft_minialgo(&all.a,all.len);
	else
	{
		arr = ft_algorithm(all.a, argc,&argc);
		ft_printf("sorm:%i\n",argc);
		ft_pushorder(arr,&all,argc);
		ft_printf("STACK A:\n");
		ft_printstack_new(all.a);
		ft_printf("STACK B:\n");
		ft_printstack_new(all.b);
		while(all.b)
		{
			all.mov_b = ft_countmvb(ft_stacksize(all.b));
			all.mov_a = ft_countmva(all.a,all.b, ft_stacksize(all.b));
			ft_convertmv(&all);
			ft_printf("\nstack A:\n");
			ft_printstack_new(all.a);
			ft_printf("STACK B:\n");
			ft_printstack_new(all.b);
			ft_order(&all.a, &all.b, ft_stacksize(all.a));
			free(all.mov_b);
			free(all.mov_a);
		}
	}	
	ft_printf("STACK A:\n");
	ft_printstack_new(all.a);
	ft_free_lst(&all.a);
	ft_free_lst(&all.b);
	if(noarray == 1)
		ft_freematrix(temp);
	if(arr)
		free(arr);
}
