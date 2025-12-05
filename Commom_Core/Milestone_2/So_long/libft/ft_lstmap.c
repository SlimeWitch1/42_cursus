
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	size_t	count;
	t_list	*init;

	count = ft_lstsize(lst);
	init = NULL;
	while (count--)
	{
		new = ft_lstnew(f(lst->content));
		if (new == NULL)
		{
			ft_lstdelone(new, del);
			return (init);
		}
		ft_lstadd_back(&init, new);
		new = new->next;
		lst = lst->next;
	}
	return (init);
}
