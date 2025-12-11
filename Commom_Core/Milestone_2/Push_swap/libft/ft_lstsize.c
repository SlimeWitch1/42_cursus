
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		n;
	t_list	*temp;

	temp = lst;
	n = 0;
	while (temp)
	{
		temp = temp->next;
		n++;
	}
	return (n);
}
