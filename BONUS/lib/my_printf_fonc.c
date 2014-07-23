/*
** my_printf_fonc.c for my_printf_fonc in /home/Spam/rendu/printf
**
** Made by Brahic
** Login   <Spam@epitech.net>
**
** Started on  Sun Nov 17 03:59:05 2013 Brahic
** Last update Sun Nov 17 17:11:18 2013 Brahic
*/

#include <stdarg.h>
#include "my.h"

unsigned int		my_printf_c(va_list *ap)
{
  my_putchar(va_arg(*ap, int));
  return (1);
}

unsigned int		my_printf_d(va_list *ap)
{
  unsigned int		len;
  int			nb;

  nb = va_arg(*ap, int);
  len = my_nbr_len(nb);
  my_put_nbr(nb);
  return (len);
}

unsigned int		my_printf_s(va_list *ap)
{
  unsigned int		len;
  char			*str;

  str = va_arg(*ap, char*);
  len = my_strlen(str);
  my_putstr(str);
  return (len);
}

unsigned int		my_printf_S(va_list *ap)
{
  unsigned int		len;
  unsigned int		i;
  char			*str;

  str = va_arg(*ap, char*);
  len = my_strlen(str);
  i = 0;
  while (str[i] != 0)
  {
    if (str[i] < 32 || str[i] >= 127)
      {
	len += my_putchar('\\');
	len += my_nbr_len(str[i]);
	len--;
	if (len < 8)
	  my_putchar('0');
	else if (len < 64)
	  my_putstr("00");
	my_putnbr_base(str[i], "01234567");
      }
    else
      my_putchar(str[i]);
    i++;
  }
  return (len + 1);
}
