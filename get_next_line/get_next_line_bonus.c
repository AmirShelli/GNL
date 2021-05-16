#include "get_next_line_bonus.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

t_list	*ft_lstnew(int fd, char **saved)
{
	struct s_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->fd = fd;
	lst->saved = ft_substr(*saved, 0, ft_strlen(*saved));
	free(*saved);
	*saved = lst->saved;
	lst->next = NULL;
	return (lst);
}

char	*ft_findfd(int fd, t_list **saved_lst)
{
	struct s_list	*tmp;
	char			*saved;

	tmp = *saved_lst;
	while (saved_lst)
	{	
		if (tmp->fd == fd)
			return (tmp->saved);
		tmp = tmp->next;
	}
	saved = (char *)malloc(1);
	tmp = ft_lstnew(fd, &saved);
	*saved = 0; 
	return (tmp->saved);
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst)
	{
		(*del)(lst->saved);
		lst->next = NULL;
		free(lst);
		lst = NULL;
	}
}

int	get_next_line(int fd, char **line)
{
	static t_list	*saved_lst;
	char			*saved;
	char			buffer[BUFFER_SIZE + 1];
	int				bytes;

	bytes = 1;
	if (saved_lst)
		{saved = ft_findfd(fd, &saved_lst);
		}
	while (bytes > 0)
	{
		if (ft_strchr(saved, '\n'))
			return (ft_getline(&saved, line));
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes >= 0)
		{
			saved = ft_strmcat(&saved, buffer, bytes);
			if (!saved_lst)
			{printf("saved and bytes: |%s\t%d|\n\n", saved,bytes);
				saved_lst = ft_lstnew(fd, &saved);}
		}
	}
	*line = ft_substr(saved, 0, ft_strlen(saved));
	// ft_lstdelone(lst, del)(void*));
	if (!*line)
		return (-1);
	return (0);
}
