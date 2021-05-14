#include "get_next_line.h"

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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*start_dest;
	int		i;

	i = 0;
	start_dest = dest;
	while (*dest)
		dest++;
	while ((src[i]) && (i < nb))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (start_dest);
}


char	*ft_strdup(char *src)
{
	char	*aux_src;
	char	*copy;

	aux_src = malloc(ft_strlen(src) + 1);
	if (!aux_src || !src)
		return (NULL);
	copy = aux_src;
	while (*src)
		*aux_src++ = *src++;
	*aux_src = '\0';
	return (copy);
}

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*start_dest;

	start_dest = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (start_dest);
}
