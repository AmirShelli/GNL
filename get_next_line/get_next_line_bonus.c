#include "get_next_line_bonus.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
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

t_list	*ft_findfd(int fd, t_list *saved_lst)
{
	t_list	*tmp;

	tmp = saved_lst;
	printf("%s	%p", tmp->saved, &(tmp->saved));
	while (tmp->fd != fd)
	{	
		if (!tmp->next)
		{	
			tmp->next = ft_lstnew(fd);
			return (tmp->next);
		}
		tmp = tmp->next;
	}
	return (tmp);
}

/*	for (; ; ) {
 *		макс меня тролит;
 * 	}
 */

void	ft_lstclear(t_list *head, t_list *lst)
{
	if (head == lst)
	{	head = head->next;
	}
	else
	{
		while (head->next != lst)
			head = head->next;
		head->next = head->next->next;
	}
	free(lst->saved);
	free(lst);
}

int	get_next_line(int fd, char **line)
{
	static t_list	*saved_lst;
	t_list			*lst;
	char			buffer[BUFFER_SIZE + 1];
	int				bytes;

	bytes = 1;
	if (!saved_lst)
	{
		saved_lst = ft_lstnew(fd);
		lst = saved_lst;
	}
	else
		lst = ft_findfd(fd, saved_lst);
	while (bytes > 0)
	{
		if (ft_strchr(lst->saved, '\n'))
			return (ft_getline(&lst->saved, line));
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes >= 0)
			lst->saved = ft_strmcat(&lst->saved, buffer, bytes);
	}
	*line = ft_substr(lst->saved, 0, ft_strlen(lst->saved));
	ft_lstclear(saved_lst, lst);
	if (!*line)
		return (-1);
	return (0);
}
