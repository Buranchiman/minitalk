#include "minitalk.h"

t_charlist	*ft_charlstnew(char content)
{
	t_charlist	*new;

	new = (t_charlist *)malloc(sizeof(t_charlist));
	if (new != NULL)
	{
		new->c = content;
		new->next = NULL;
	}
	return (new);
}

void	ft_charlstadd_back(t_charlist **lst, t_charlist *new)
{
	t_charlist	*temp;

	if (lst != NULL)
	{
		if (*lst != NULL)
		{
			temp = *lst;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new;
		}
		else
			*lst = new;
	}
}

int	ft_charlstsize(t_charlist *lst)
{
	int			i;
	t_charlist	*temp;	

	temp = lst;
	if (lst == NULL)
		return (0);
	i = 1;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void	clean_charlist(t_charlist *a)
{
	t_charlist	*temp;

	temp = a;
	while (a != NULL)
	{
		temp = a->next;
		free(a);
		a = temp;
	}
}

void	manage_charlist(t_charlist **msg, char	c)
{
	t_charlist	*temp;
	t_charlist	*temp2;

	//ft_printf("added a new element to list : %c\n", c);
	temp = ft_charlstnew(c);
	ft_printf("added a new element to list : %c\n", c);
	ft_charlstadd_back(msg, temp);
	ft_printf("element after add back is : %c\n", c);
	temp2 = *msg;
	while (temp2 != NULL)
	{
		//ft_printf("character is : %c\n", temp2->c);
		temp2 = temp2->next;
	}
}