# school21_GNL

	functions needed:
char	*ft_savestr(char **into, char *from);
char	*ft_strchr(char *str, char c);
char	*ft_strdup(char *str);
char	*ft_strncat(char *dest, char *src, unsigned int n);
int		ft_strlen(char *str);

   * char *ft_saverstr(char *saver, const char *buffer)
NULL means first iter for saver
first iter malloc for saver then copy,
else concatinates until \n in a aux str, 
frees saver and fills it ready to be returned, 
returns result (itself or concatinated strs)
with \0 termination.
