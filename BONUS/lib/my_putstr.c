/*
** my_putstr.c for my_putstr.c in
**
** Made by Brahic
** Login   <Spam@epitech.net>
**
** Started on  Thu Oct  3 09:34:18 2013 Brahic
** Last update Sun Nov 17 12:22:28 2013 Brahic
*/

#include <unistd.h>

unsigned int	my_putstr(char *str)
{
  unsigned int	k;

  k = 0;
  while (str[k])
    write(1, &str[k++], 1);
  return (k);
}
