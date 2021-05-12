# school21_GNL


   * char *ft_saverstr(char *saver, const char *buffer)
check if saver != NULL
NULL means first iter for saver
first iter malloc for saver then copy,
else concatinates until \n in a aux str, 
frees saver and fills it ready to be returned, 
returns result (itself or concatinated strs)
with \0 termination.