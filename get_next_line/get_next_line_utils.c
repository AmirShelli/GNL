#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	if (str)
	{
		while (str[length])
			length++;
	}
	return (length);
}

char	*ft_strchr(const char *src, int c)
{
	char			*aux;
	unsigned char	chr;

	aux = (char *)src;
	chr = c;
	if (src)
	{
		while (*aux && *aux != chr)
			aux++;
		if (*aux == chr)
			return (aux);
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t size)
{
	char	*str;
	char	*aux_str;

	if (!s)
		return (NULL);
	if (ft_strlen(s + start) < size)
		size = ft_strlen(s + start);
	str = (char *)malloc(size + 1);
	aux_str = str;
	if (str)
	{
		if (start < ft_strlen(s))
			while (*(s + start) && size--)
				*str++ = *(s++ + start);
	}
	*str = 0;
	return (aux_str);
}

char	*ft_strmcat(char **ptr_dest, char const *src, int n)
{
	char	*res;
	char	*dest;
	int		i;

	if (!*ptr_dest)
	{
		*ptr_dest = (char *)malloc(1);
		**ptr_dest = '\0';
	}
	i = 0;
	dest = *ptr_dest;
	if (dest && src && n >= 0)
	{
		res = (char *)malloc(ft_strlen(dest) + n + 1);
		if (!res)
			return (NULL);
		while (*dest)
			res[i++] = *dest++;
		while (*src && n--)
			res[i++] = *src++;
		free(*ptr_dest);
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}

int	ft_getline(char **saved, char **line)
{
	char	*tmp;
	size_t	size;

	size = ft_strlen(*saved) - ft_strlen(ft_strchr(*saved, '\n') + 1);
	*line = ft_substr(*saved, 0, size - 1);
	tmp = ft_substr(*saved, size, ft_strlen(ft_strchr(*saved, '\n')));
	free(*saved);
	if (!*line || !tmp)
	{	
		free(tmp);
		return (-1);
	}
	*saved = tmp;
	return (1);
}
