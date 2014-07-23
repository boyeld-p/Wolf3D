/*
** my_put_nbr.c for my_put_nbr in
**
** Made by Brahic
** Login   <Spam@epitech.net>
**
** Started on  Wed Oct  2 17:00:03 2013 Brahic
** Last update Sun Nov 17 07:57:21 2013 Brahic
*/

#include <unistd.h>

int	my_put_nbr(int nb)
{
  char	c;

  if (nb == -2147483648)
    {
      write(1, "-2147483648", 11);
      return (11);
    }
  if (nb < 0)
    {
      write(1, "-", 1);
      nb = nb * -1;
    }
  if (nb >= 10)
    my_put_nbr(nb / 10);
  c = nb % 10 + '0';
  write(1, &c, 1);
  return (0);
}
