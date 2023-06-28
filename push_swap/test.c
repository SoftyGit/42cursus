#include "test.h"
#include "ps.h"

void	ps_printer(int	data)
{
	printf("%d\n", data);
}

void	ps_lstiter(t_node *lst, void (*f)(int))
{
	while (lst)
	{
		f(lst -> data);
		lst = lst -> next;
	}
}

void	ps_lstreviter(t_node *lst, void (*f)(int))
{
	while (lst)
	{
		f(lst -> data);
		lst = lst -> prev;
	}
}