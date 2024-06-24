# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char    *get_next_line(int fd);
int        ft_strlen_gnl(char *str);
int        include_n(char *s);
char    *ft_strjoin_gnl(char **s1, char **s2);
char    *ft_strdup_gnl(char *s);
void    free_and_null(char **p);
