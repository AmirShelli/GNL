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

t_list	*ft_findfd(int fd, t_list **saved_lst)
{
	t_list	*tmp;

	tmp = *saved_lst;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew(fd);
	return (tmp);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*current;

	while (*lst && lst)
	{
		current = (*lst)->next;
		free((*lst)->saved);
		(*lst)->saved = NULL;
		free(*lst);
		(*lst) = current;
	}
}

int	get_next_line(int fd, char **line)
{
	static t_list	*saved_lst;
	char			buffer[BUFFER_SIZE + 1];
	int				bytes;

	bytes = 1;
	if (saved_lst)
		saved_lst = ft_findfd(fd, &saved_lst);
	while (bytes > 0)
	{
		if (!saved_lst)
			saved_lst = ft_lstnew(fd);
		if (ft_strchr(saved_lst->saved, '\n'))
			return (ft_getline(&saved_lst->saved, line));
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes >= 0)
			saved_lst->saved = ft_strmcat(&saved_lst->saved, buffer, bytes);
	}
	*line = ft_substr(saved_lst->saved, 0, ft_strlen(saved_lst->saved));
	ft_lstclear(&saved_lst);
	if (!*line)
		return (-1);
	return (0);
}
