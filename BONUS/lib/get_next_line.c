/*
** get_next_line.c for get_next_line in /home/brahic_a/rendu/fdf
** 
** Made by brahic
** Login   <brahic_a@epitech.net>
** 
** Started on  Sat Dec  7 21:22:13 2013 brahic
** Last update Sun Dec  8 08:16:20 2013 brahic
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*xfree(char *str)
{
  if (str)
    {
      free(str);
      str = NULL;
      return (str);
    }
  else
    return (str);
}

char	get_char(const int fd)
{
  static char *buff = NULL;
  static int my_i = 0;
  static int my_c = -42;

  if (my_c == -42)
    {
      if ((buff = malloc(SIZE * sizeof(char))) == NULL)
	return (-42);
      if ((my_c = read(fd, buff, SIZE)) <= 0)
	{
	  my_c = -42;
	  buff = xfree(buff);
	  return (-42);
	}
      my_i = 0;
    }
  if (my_i == my_c)
    {
      my_i = 0;
      my_c = -42;
      buff = xfree(buff);
      return (get_char(fd));
    }
  return (buff[my_i++]);
}

char	*my_ut(char *my_line, char c, int size)
{
  char	*tmp;
  int	i;

  i = 0;
  if ((tmp = malloc((size + SIZE) * sizeof(char))) == NULL)
    return (0);
  while (i < size)
    {
      tmp[i] = my_line[i];
      i += 1;
    }
  tmp[i] = c;
  my_line = xfree(my_line);
  return (tmp);
}

int	get_next_line_aux(int j, int i, char *my_line, char c)
{
  if (j != SIZE)
    {
      my_line[i] = c;
      return (j + 1);
    }
  else
    {
      my_line = my_ut(my_line, c, i);
      return (1);
    }
}

char	*get_next_line(const int fd)
{
  char	c;
  char	*my_line;
  int	i;
  int	j;
  static int my_end = 0;

  i = 0;
  j = 1;
  c = 42;
  if ((my_line = malloc(SIZE * sizeof(char))) == NULL)
    return (NULL);
  while (c != '\n' && c != -42)
    {
      c = get_char(fd);
      j = get_next_line_aux(j, i, my_line, c);
      i += 1;
    }
  my_line[i - 1] = '\0';
  if (c == '\n')
    return (my_line);
  else if (my_end++ == 0)
    return (my_line);
  else
    return (xfree(my_line));
}
