#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"
#include "libft/libft.h"

// scorri finche non arrivi ad argc solo cosi avrai scorso tuttoo,
// ora mentre scorri salva argv in una temporanea e controlla se argv e' uguale alla temporanea se
//non lo e' mettilo in essa appena un numero e' uguale alla temp esci e libera la temp;

int	ft_checkarg(int argc, char **argv)
{
	int	c;
	int	*arr;
	int	n;
	int	i;
	c = 1;
	n = 0;	
	i = 0;
	n = atoi(argv[c]);
	arr = malloc(sizeof(int) * argc);
	while(c < argc)
	{
		n = atoi(argv[c]);
		arr[c-1] = n;
		i = c - 2;
		while(i >= 0)
	  	{	
	  		if(arr[i] == n)
	  		{
				free(arr);
				return(1);
			}	
		i--;
		}
		c++;
	}
	free(arr);
	return(0);
}
t_stack	*ft_add(t_stack *prev, int numero)
{
	t_stack *new;
	new = malloc(sizeof(t_stack)); //new vuoto
	if(prev)
		prev->next = new; //prev e' il numero quindi 1, che punta  a 2
	new->prev = prev;// 2 punta a 1
	new->content = numero;
	new->next = NULL;	
}
void	 ft_freenode(t_stack **lst)
{
	t_stack *temp;
	
	(*lst)->prev->next = NULL;
	while((*lst) != NULL)
	{
		temp = (*lst)->next;
		free(*lst);
		(*lst) = temp;
	}
}
void	ft_printstack(t_stack *lst)
{
	while(lst != NULL)
	{
		ft_printf("%d\n",lst->content);
		lst = lst-> next;
		
	}
}
void	ft_addback(t_stack **lst, int newnum)
{
	t_stack *temp;
	
	temp = *lst;
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = ft_add(temp, newnum);
	(*lst)->prev = temp->next;
}
// numeri  1 2 3 1 5
//n = 1 n == arr[i]
// arr[i] = 1,2, ;
// 

//SA
//allora scorro la lista al 0 1 2 secondo argomento la fermo e sposto il secondo al primo posto con listaddfront
// essenzialmente faro' questo  2 4 5 6 8
// scorro fino a 4
// e dico sposta 4 al primo elemento salvando il 2 con una temp e lo faccio puntare a next->content  dell'attuale 4  quindi linko il 2 -> con il 5s

int main(int argc, char **argv)
{
	if(argc < 2 || ft_checkarg(argc,argv) == 1)
	{
	 ft_printf("non ci sono argomenti a sufficienza \n");
	 return(1);
	}
	int c;
	t_stack *lst;
	lst = ft_add(0,ft_atoi(argv[1]));
	c = 1;
	while(++c <= argc - 1)
		ft_addback(&lst, ft_atoi(argv[c]));
	ft_printstack(lst);			
	ft_freenode(&lst);
}
