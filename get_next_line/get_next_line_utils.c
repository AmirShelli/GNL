#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

char	*ft_strchr(const char *src, int c)
{
	char			*aux;
	unsigned char	chr;

	aux = (char *)src;
	chr = c;
	while (*aux && *aux != chr)
		aux++;
	if (*aux == chr)
		return (aux);
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

char	*ft_strnjoin(char const *s1, char const *s2, int n)
{
	char	*res;
	char	*res_aux;

	if (s1 && s2)
	{
		res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (!res)
			return (NULL);
		res_aux = res;
		while (*s1)
			*res++ = *s1++;
		while (*s2 && n--)
			*res++ = *s2++;
		*res = '\0';
		return (res_aux);
	}
	return (NULL);
}
