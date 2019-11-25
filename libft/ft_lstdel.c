#include "libft.h"

void  ft_lstdel(t_list **alst, void (*del)(void *,size_t))
{
	t_list	*temp;
	t_list	*next;

	temp = *alst;
	while (temp)
	{
		del(temp->content, temp->content_size);
		next = temp;
		temp = temp->next;
		free(next);
	}
	*alst = NULL;
}