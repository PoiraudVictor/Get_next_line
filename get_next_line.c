#include "get_next_line.h"

static char *too_long(char *tmp, char c)
{
    int     i;
    char    *dst;
    i = 0;
    dst = NULL;
    while (tmp && tmp[i] && tmp[i] != c)
        i++;
    if (tmp && tmp[i])
        dst = ft_strdup(tmp + i + 1);
    return (dst);
}

static char *short_enough(char *main, char c)
{
    int     i;
    int     j;
    char    *dst;
    i = 0;
    if (!main)
        return (NULL);
    while (main && main[i] && main[i] != c)
        i++;
    if (!main[i])
        return (dst = ft_strdup(main));
    if (!(dst = ft_strnew(i + 1)))
        return (NULL);
    j = i;
    i = 0;
    while (i != j)
    {
        dst[i] = main[i];
        i++;
    }
    dst[i] = '\0';
    return (dst);
}

static  int stock_line(int *last, char **main, char **line)
{
  char *tmp;

  if (main && *main && ft_strchr(*main, '\n'))
  {
    tmp = *main;
    if (!(*line = short_enough(*main, '\n')))
      return (-1);
    if (!(*main = too_long(tmp, '\n')))
      return (-1);
    ft_strdel(&tmp);
    if (*main && !*main[0])
        *last = 1;
    return(1);
  }
  if (!(*line = ft_strdup(*main)))
    return (-1);
  *last = 1;
  return (1);
}

char    *buffer_management(int error, int fd)
{
  char  buf[BUFF_SIZE + 1];
  int   readen;
  char  *tmp;
  char  *result;

  result = NULL;
  if (!(tmp = ft_strnew(1)))
    return (NULL);
  while ((readen = read(fd, buf, BUFF_SIZE)) > 0)
  {
    buf[readen] = '\0';
    if (!(result = ft_strjoin(tmp, buf)))
      return (NULL);
    ft_strdel(&tmp);
    tmp = result;
  }
  if (tmp && !tmp[0])
    ft_strdel(&tmp);
  if (readen < 0)
    error = -1;
  return (result);
}

int     get_next_line(int fd, char **line)
{
  static  char *main = NULL;
  static  int last = 0;
  int error;

  error = 0;
  if (fd < 0 || !line || BUFF_SIZE < 0)
    return (-1);
  if (last == 1)
  {
    last = 0;
    if (main)
      ft_strdel(&main);
    return (0);
  }
  if (!main)
    if (!(main = buffer_management(error, fd)))
      return (-1);
  if (error < 0)
    return (error);
  return (stock_line(&last, &main, line));
}
