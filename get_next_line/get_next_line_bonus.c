#include "get_next_line_bonus.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

t_list	*ft_lstnew(int fd)
{
	struct s_list	*lst;
	char			*saved;

	lst = (t_list *)malloc(sizeof(t_list));
	saved = (char *)malloc(1);
	if (!lst || !saved)
		return (NULL);
	*saved = 0;
	lst->fd = fd;
	lst->saved = saved;
	lst->next = NULL;
	return (lst);
}

t_list	*ft_findfd(int fd, t_list **saved_lst)
{
	t_list	*tmp;

	if (*saved_lst)
	{
		tmp = *saved_lst;
		while (tmp->saved && tmp->fd != fd)
		{	
			if (!tmp->next)
			{	
				tmp->next = ft_lstnew(fd);
				return (tmp->next);
			}
			tmp = tmp->next;
		}
	}
	else
	{	
		*saved_lst = ft_lstnew(fd);
		tmp = *saved_lst;
	}
	return (tmp);
}

/*	for ( ; ; ) {
 *		макс меня тролит;
 * 	}
 */

void	ft_lstclear(t_list **head, t_list **lst)
{
	t_list	*start;

	start = *head;
	if (*head == *lst)
	{	
		free((*head)->saved);
		(*head)->saved = NULL;
		free(*head);
		*head = NULL;
	}
	else
	{
		while ((*head)->next != *lst)
			*head = (*head)->next;
		free((*head)->next->saved);
		(*head)->next->saved = NULL;
		free((*head)->next);
		(*head)->next = (*head)->next->next;
		*head = start;
	}
}

int	get_next_line(int fd, char **line)
{
	static t_list	*saved_lst;
	t_list			*lst;
	char			buffer[BUFFER_SIZE + 1];
	int				bytes;

	bytes = 1;
	lst = ft_findfd(fd, &saved_lst);
	while (bytes > 0)
	{
		if (ft_strchr(lst->saved, '\n'))
			return (ft_getline(&lst->saved, line));
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes >= 0)
			lst->saved = ft_strmcat(&lst->saved, buffer, bytes);
	}
	*line = ft_substr(lst->saved, 0, ft_strlen(lst->saved));
	if (bytes < 0)
	{
		free(*line);
		*line = NULL;
		return (-1);
	}
	ft_lstclear(&saved_lst, &lst);
	return (0);
}
