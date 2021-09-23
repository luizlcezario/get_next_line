#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef MAX_FD
#  define MAX_FD 256
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef enum e_bool
{
	false = 0,
	true = 1
}			t_bool;

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);

#endif