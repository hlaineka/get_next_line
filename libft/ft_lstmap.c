#include "libft.h"

t_list *  ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*returnable;
	t_list	*returnable_temp;
	t_list	*returnable_previous;

	if (!(returnable = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	returnable = f(lst);
	returnable->next = NULL;
	temp = lst->next;
	returnable_previous = returnable;
	while (temp)
	{
		if (!(returnable_temp = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
		returnable_temp = f(temp);
		returnable_temp->next = NULL;
		returnable_previous->next = returnable_temp;
		returnable_previous = returnable_temp;
		temp = temp->next;
	}
	return(returnable);
}