#include "libft/libft.h"
#include "push_swap.h"
//argv e' un char quindi usiamo atoi,
//prima cosa da controllare se  argomento e' minore di 1 
//ritornare 1 o \n

// poi controllare se uno degli argomenti e' diverso da un numero non accettarlo
// quindi non esegui il programma ritorni 1 o \n


//controllo se gli argomenti sono uguali ad esempio se argv[1] == argv[2]
// se sono uguali non accetto gli argomenti quindi non esegui il programma ritorni 1 o \n

//ora eseguo il programma
// argv[1] = al primo elemento della lista, e a seguire gli altri elementi
//argv[2] = al secondo


//ok ho riempito lo stack fatto cio dobbiamo ordinarlo
//per ordinarlo eseguiamo varie azioni:

t_stack	*ft_add(int numero)
{
	t_stack *nodo;
	nodo = malloc(sizeof(t_stack));
	nodo->content = numero;
	nodo->next = 0;
	return (nodo);
	
}

void	ft_addback(t_stack **lst, int newnum)
{
	t_stack *temp;
	
	temp = *lst;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = ft_add(newnum);
}
// 4 -> null
void	ft_printstack(t_stack *lst)
{
	while(lst != NULL)
	{
		ft_printf("%d\n",lst->content);
		lst = lst-> next;
		
	}
}
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
int main(int argc, char **argv)
{
	if(argc < 2 || ft_checkarg(argc,argv) == 1)
	{
	 ft_printf("non ci sono argomenti a sufficienza \n");
	 return(1);
	}
	int c;
	t_stack *lst;
	lst = ft_add(ft_atoi(argv[1]));
	c = 1;
	while(++c <= argc - 1)
		ft_addback(&lst, ft_atoi(argv[c]));
	ft_printstack(lst);			
}
